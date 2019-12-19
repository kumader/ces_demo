/**
 * @file
 * ADTF Frame Extractor
 *
 * @copyright
 * @verbatim
   Copyright @ 2017 Audi Electronics Venture GmbH. All rights reserved.

       This Source Code Form is subject to the terms of the Mozilla
       Public License, v. 2.0. If a copy of the MPL was not distributed
       with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

   If it is not possible or desirable to put the notice in a particular file, then
   You may include the notice in a location (such as a LICENSE file in a
   relevant directory) where a recipient would be likely to look for such a notice.

   You may add additional accurate notices of copyright ownership.
   @endverbatim
 */

#include <adtf_file/standard_adtf_file_reader.h>

#include <stdio.h>
#include <direct.h>

#include <sys/stat.h>

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>

#include <QtGui/QImage>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include <opencv2/opencv.hpp>

#include "lidar.h"
#include "frame_extractor.h"

// initalize ADTF File and Plugin Mechanism
static adtf_file::Objects oObjects;
static adtf_file::PluginInitializer oInitializer([]
{
    adtf_file::add_standard_objects();
});

static const char* PROP_ADTF_IMAGE = "adtf/image";
static const char* PROP_PIXEL_WIDTH = "pixel_width";
static const char* PROP_PIXEL_HEIGHT = "pixel_height";
static const char* PROP_BITS_PER_PIXEL = "bits_per_pixel";
static const char* PROP_COLOR_FORMAT = "format_name";

static const std::set<std::string> SUPPORTED_IMG_FORMATS = { "BMP",
															 "JPG",
														     "JPEG",
														     "PNG",
														     "PPM",
														     "XBM",
														     "XPM" };

static const std::set<std::string> SUPPORTED_POINTCLOUD_FORMATS = { "PCD_ASCII",
                                                                    "PCD_BIN",
                                                                    "PCD_BIN_COMPRESSED",
                                                                    "PCD" }; // PCD defaults to binary pcd

static const std::set<std::string> SUPPORTED_VIDEO_FORMATS = { "AVI",
															   "H264",
															   "MP4" };

static const std::unordered_map<std::string, int> FOURCC_CODES = { {"AVI", cv::VideoWriter::fourcc('M', 'J', 'P', 'G')},
																   {"H264", cv::VideoWriter::fourcc('H', '2', '6', '4')},
																   {"MP4", cv::VideoWriter::fourcc('a', 'v', 'c', '1')} };

enum class OutputType
{
	IMAGE = 0,
	POINTCLOUD,
	VIDEO,
	NONE
};

enum class ErrorCodes
{
	SUCCESS = 0,
	ARGUMENT_ERROR,
	IO_ERROR,
	STREAM_NOT_FOUND_ERROR,
	INVALID_OUTPUT_FORMAT_ERROR,
	UNSUPPORTED_COLOR_DEPTH_ERROR,
	UNSUPPORTED_STREAM_TYPE_ERROR,
	ADTF_FILE_ERROR,
	IMAGE_COMPOSITE_ERRER,
	EXCEPTION_OCCURRED,
	QT_ERROR,
	OPENCV_ERROR,
	NONE
};

struct AdtfImageFormat {
	uint32_t width;
	uint32_t height;
	uint32_t depthBytes;
	std::string colorFormat;
};

adtf_file::Reader CreateReader(const a_util::filesystem::Path& adtfdat_file_path)
{
    //open file -> create reader from former added settings
    adtf_file::Reader reader(adtfdat_file_path,
                             adtf_file::getFactories<adtf_file::StreamTypeDeserializers,
                                                     adtf_file::StreamTypeDeserializer>(),
                             adtf_file::getFactories<adtf_file::SampleDeserializerFactories,
                                                     adtf_file::SampleDeserializerFactory>(),
                             std::make_shared<adtf_file::sample_factory<adtf_file::DefaultSample>>(),
                             std::make_shared<adtf_file::stream_type_factory<adtf_file::DefaultStreamType>>());

    return reader;
}

void GetImageStreamProperties(std::shared_ptr<const adtf_file::PropertyStreamType> propStreamType,
	                          AdtfImageFormat& output)
{
	if (propStreamType)
	{
		if (strcmp(propStreamType->getMetaType().c_str(), PROP_ADTF_IMAGE) == 0)
		{
			propStreamType->iterateProperties([&](const char* name,
				                                  const char* type,
				                                  const char* value) -> void
			{
				if (strcmp(name, PROP_PIXEL_HEIGHT) == 0)
				{
					output.height = std::stoi(value);
				}
				else if (strcmp(name, PROP_PIXEL_WIDTH) == 0)
				{
					output.width = std::stoi(value);
				}
				else if (strcmp(name, PROP_BITS_PER_PIXEL) == 0)
				{
					output.depthBytes = std::stoi(value) / 8;
				}
				else if (strcmp(name, PROP_COLOR_FORMAT) == 0)
				{
					output.colorFormat = value;
				}
			});
		}
	}
}

bool CopyScanData(const uint8_t* inScanSample, const size_t sampleLength, sScanData3D* outScanData)
{
	bool retVal = true;

	const sScanData3D* temp = reinterpret_cast<const sScanData3D*>(inScanSample);
	outScanData->mountingPosition = temp->mountingPosition;
	outScanData->pointsCount = temp->pointsCount;

	auto offset = sizeof(outScanData->mountingPosition) + sizeof(outScanData->pointsCount);
	auto pointsBegin = inScanSample + offset;
	const sLidarPoint3D* points = reinterpret_cast<const sLidarPoint3D*>(pointsBegin);

	auto calculatedSize = offset + (outScanData->pointsCount * sizeof(sLidarPoint3D));

	if (calculatedSize != sampleLength)
	{
		std::cout << "ERROR: Sample does not contain sScanData3D buffer." << std::endl;
		retVal = false;
	}
	else
	{
		outScanData->points = new sLidarPoint3D[outScanData->pointsCount];

		for (uint32_t i = 0; i < outScanData->pointsCount; ++i)
		{
			const sLidarPoint3D point = points[i];
			outScanData->points[i] = point;
		}
	}

	return retVal;
}

bool ContainsScanData(adtf_file::Reader& reader, uint16_t streamId)
{
	bool retVal = true;

	uint64_t itemIndex = reader.getItemIndexForStreamItemIndex(streamId, 0);
	reader.seekTo(itemIndex);
	adtf_file::FileItem item = reader.getNextItem();
	auto data = std::dynamic_pointer_cast<const adtf_file::Sample>(item.stream_item);

	if (data)
	{
		auto sampleData = std::dynamic_pointer_cast<const adtf_file::DefaultSample>(data);
		const uint8_t* buffer = sampleData->getContent<uint8_t>();

		const sScanData3D* temp = reinterpret_cast<const sScanData3D*>(buffer);
		tUInt32 pointsCount = temp->pointsCount;

		auto offset = sizeof(temp->mountingPosition) + sizeof(temp->pointsCount);
		auto calculatedSize = offset + (temp->pointsCount * sizeof(sLidarPoint3D));

		//input buffer size differs from calculated sScanData size
		if (calculatedSize != sampleData->GetBufferSize())
		{
			retVal = false;
		}
	}
	else
	{
		retVal = false;
	}

	return retVal;
}

bool FileExists(const char *fileName)
{
	std::ifstream infile(fileName);
	bool retVal = infile.good();
	infile.close();

	return retVal;
}

bool parseArgs(int argc,
	           char* argv[],
	           a_util::filesystem::Path& inputFile,
               std::vector<std::string>& targetPinNames,
               std::string& outPath,
               std::string& outFormat,
               uint32_t& skipRate,
			   bool& downscale,
	           bool& interactive)
{
	bool result = true;

	uint8_t inputFileCount = 0;
	uint8_t outputPathCount = 0;
	uint8_t formatCount = 0;
	uint8_t skipRateCount = 0;
	downscale = false;
	interactive = true;

	for (int i = 1; i < argc; ++i)
	{
		std::string optionType = argv[i];
		transform(optionType.begin(), optionType.end(), optionType.begin(), tolower);

		if (optionType.compare("-i") == 0 && i + 1 < argc)
		{
			inputFile = argv[++i];

			if (++inputFileCount > 1)
			{
				std::cerr << "ERROR: Maximum number of input file arguments is 1" << std::endl;
				result = false;
				break;
			}
		}
		else if (optionType.compare("-t") == 0 && i + 1 < argc)
		{
			targetPinNames.push_back(argv[++i]);
		}
		else if (optionType.compare("-o") == 0 && i + 1 < argc)
		{
			outPath = argv[++i];

			if (++outputPathCount > 1)
			{
				std::cerr << "ERROR: Maximum number of output path arguments is 1" << std::endl;
				result = false;
				break;
			}
		}
		else if (optionType.compare("-f") == 0 && i + 1 < argc)
		{
			outFormat = argv[++i];

			if (++formatCount > 1)
			{
				std::cerr << "ERROR: Maximum number of format arguments is 1" << std::endl;
				result = false;
				break;
			}
		}
		else if (optionType.compare("-s") == 0 && i + 1 < argc)
		{
			skipRate = std::abs(std::stoi(argv[++i]));

			if (++skipRateCount > 1)
			{
				std::cerr << "ERROR: Maximum number of skip rate arguments is 1" << std::endl;
				result = false;
				break;
			}
		}
		else if (optionType.compare("-d") == 0)
		{
			downscale = true;
		}
		else if (optionType.compare("-n") == 0)
		{
			interactive = false;
		}
		else
		{
			std::cerr << "ERROR: Unexpected argument: " << optionType << std::endl;
			result = false;
			break;
		}
	}

	if (inputFileCount == 0 || targetPinNames.size() == 0 || outputPathCount == 0 || formatCount == 0)
	{
		result = false;
	}
	
	return result;
}

int main(int argc, char* argv[])
{
	//required for QT load bundled plugins
	std::string qtPluginPath = "QT_PLUGIN_PATH=./plugins";
	_putenv(qtPluginPath.c_str());

	a_util::filesystem::Path datFile;
	std::vector<std::string> targetPinNames;
	std::string outPath;
	std::string outFormat;
	uint32_t skipRate = 0;
	bool downscale = false;
	bool interactive = true;

	if (!parseArgs(argc,
		           argv,
		           datFile,
		           targetPinNames,
		           outPath,
		           outFormat,
		           skipRate,
		           downscale,
		           interactive))
	{
		std::cerr << "usage: \n"
			<< argv[0] << " -i <DAT File Path> -t <Target Output Stream(s)> -o <Output Path> -f <Output Image Format> -s <Optional: Frame Skip Rate> -d <Optional: Downscale Output> -n <Optional: Disable Interactive Mode>" << std::endl
			<< "e.g. " << argv[0] << " -i c:\\data.dat -t out_stream -o c:\\output -f MP4";
		return static_cast<int>(ErrorCodes::ARGUMENT_ERROR);
	}

	std::ostringstream os;

	for(std::string s : targetPinNames)
	{
		os << s << " ";
	}

	std::cout << "Arguments:" << std::endl;
	std::cout << "DAT File      : " << datFile.toString() << std::endl;
	std::cout << "Target Pin(s) : " << os.str() << std::endl;
	std::cout << "Output Path   : " << outPath << std::endl;
	std::cout << "Output Format : " << outFormat << std::endl;
	std::cout << "Downscale     : " << std::boolalpha << downscale << std::endl;
	std::cout << "Interactive   : " << std::boolalpha << interactive << std::endl;

	struct stat info;

	//check if input file exists.
	if (!FileExists(datFile.toString().c_str()))
	{
		std::cerr << "ERROR: Input file does not exist." << std::endl;
		return static_cast<int>(ErrorCodes::IO_ERROR);
	}

	//check if output directory exists. If not, create it.
	if (stat(outPath.c_str(), &info) != 0)
	{ 
		_mkdir(outPath.c_str());
	}

	transform(outFormat.begin(), outFormat.end(), outFormat.begin(), toupper);
	std::string outFormatLower = outFormat;
	transform(outFormatLower.begin(), outFormatLower.end(), outFormatLower.begin(), tolower);

	std::cout << "Frame Skip Rate: " << skipRate << std::endl;

	try
	{
		//verify adtf|dat file
		if (("adtfdat" != datFile.getExtension())
			&& ("dat" != datFile.getExtension()))
		{
			throw std::runtime_error("ERROR: Unsupported extension, please use .adtfdat (ADTF 3.x) or .dat (ADTF 2.x).");
		}

		//TODO: Stuff below into a function, make into lib
		adtf_file::Reader reader = CreateReader(datFile);

		std::cout << "\nAvailable Pins/Streams:" << std::endl;

		std::vector<adtf_file::Stream> streams = reader.getStreams();
		vector<std::pair<adtf_file::Stream, AdtfImageFormat> >targetStreams;

		uint32_t matches = 0;

		uint32_t count = 1;
		for (const adtf_file::Stream currentStream : streams)
		{
			std::cout << count++ << ") " << currentStream.name << std::endl;

			for (size_t index = 0; index < targetPinNames.size(); ++index)
			{
				AdtfImageFormat currentFormat = { 0, 0, 0, "None" };
				auto propertyStreamType = std::dynamic_pointer_cast<const adtf_file::PropertyStreamType>(currentStream.initial_type);
				GetImageStreamProperties(propertyStreamType, currentFormat);

				// Allow partial matches when only dealing with single target. If multiple
				// pins match criteria, then we can only accept the first match.
				if (targetPinNames.size() == 1)
				{
					if (currentStream.name.find(targetPinNames[index]) != std::string::npos)
					{
						++matches; 
						targetStreams.push_back({ currentStream, currentFormat });
						targetPinNames[index] = currentStream.name;
						break;
					}
				}
				else
				{
					if (currentStream.name.compare(targetPinNames[index]) == 0)
					{
						++matches;
						targetStreams.push_back({ currentStream, currentFormat });
						targetPinNames[index] = currentStream.name;
					}
				}
			}
		}

		if (targetPinNames.size() > 1)
		{
			if (matches < targetPinNames.size())
			{
				if (matches == 0)
				{
					std::cout << "ERROR: No target streams not found, please check \"-t\" arguments" << std::endl;
					return static_cast<int>(ErrorCodes::STREAM_NOT_FOUND_ERROR);
				}
				else
				{
					if (interactive)
					{
						uint32_t numTargets = targetPinNames.size() - matches;
						bool interactiveLoop = true;

						while (interactiveLoop)
						{
							std::cout << "\n" << numTargets << " of " << targetPinNames.size() << " target pins found. Continue with following streams?" << std::endl;
							
							for (uint32_t i = 0; i < targetStreams.size(); ++i)
							{
								std::cout << i + 1 << ") " << targetStreams[i].first.name << std::endl;
							}
							std::cout << "(y/n) ";

							char c;
							std::cin >> c;

							if (c == 'y' || c == 'Y')
							{
								interactiveLoop = false;
							}
							else if (c == 'n' || c == 'N')
							{
								std::cout << "Exiting application." << std::endl;
								return static_cast<int>(ErrorCodes::SUCCESS);
							}
							else
							{
								std::cout << "\nInvalid response. Please try again." << std::endl;
							}
						}
					}

					std::cout << "\nContinuing data extraction on following streams:" << std::endl;

					for (uint32_t i = 0; i < targetStreams.size(); ++i)
					{
						std::cout << i + 1 << ") " << targetStreams[i].first.name << std::endl;
					}
				}
			}
			else
			{
				for (auto currentStream : targetStreams)
				{
					auto currentPropStreamType = std::dynamic_pointer_cast<const adtf_file::PropertyStreamType>(currentStream.first.initial_type);
					std::string currentStreamMetaType = currentPropStreamType->getMetaType();

					if (currentStreamMetaType.compare(PROP_ADTF_IMAGE) != 0)
					{
						std::cout << "ERROR: Multiple target pins are only supported for type, " << PROP_ADTF_IMAGE << std::endl;
						return static_cast<int>(ErrorCodes::UNSUPPORTED_STREAM_TYPE_ERROR);
					}
				}
			}
		}
		else
		{
			if (interactive)
			{
				while (matches < 1)
				{
					std::cout << "\nNo matching stream found. Please select one of the following:\n" << std::endl;
					for (uint32_t i = 0; i < streams.size(); ++i)
					{
						std::cout << i + 1 << ") " << streams[i].name << std::endl;
					}

					std::cout << streams.size() + 1 << ") Exit" << std::endl;

					uint32_t n;
					std::cin >> n;

					if (n <= streams.size())
					{
						++matches;
						AdtfImageFormat format = { 0, 0, 0, "None" };
						auto propertyStreamType = std::dynamic_pointer_cast<const adtf_file::PropertyStreamType>(streams[n - 1].initial_type);
						GetImageStreamProperties(propertyStreamType, format);
						targetStreams.push_back({ streams[n - 1], format });
						targetPinNames[0] = streams[n - 1].name;
					}
					else if (n == streams.size() + 1)
					{
						std::cout << "Exiting application." << std::endl;
						return static_cast<int>(ErrorCodes::SUCCESS);
					}
					else
					{
						std::cout << "\nInvalid response. Please try again." << std::endl;
					}
				}
			}
			else
			{
				if (matches == 0)
				{
					std::cout << "ERROR: Target stream not found, please check \"-t\" arguments" << std::endl;
					return static_cast<int>(ErrorCodes::STREAM_NOT_FOUND_ERROR);
				}
			}			
		}

		if (SUPPORTED_IMG_FORMATS.find(outFormat) != SUPPORTED_IMG_FORMATS.end() ||
			SUPPORTED_VIDEO_FORMATS.find(outFormat) != SUPPORTED_VIDEO_FORMATS.end())
		{
			for (auto currentStream : targetStreams)
			{
				if (currentStream.second.depthBytes < 3)
				{
					std::cout << "ERROR: Unsupported color depth. Only 24bpp RGB or 32bpp RGBA are supported at this time." << std::endl;
					return static_cast<int>(ErrorCodes::UNSUPPORTED_COLOR_DEPTH_ERROR);
				}
			}
		}

		adtf_file::Stream targetStream = targetStreams[0].first;
		AdtfImageFormat masterFormat = targetStreams[0].second;

		std::cout << "\nFound matching output stream" << (targetStreams.size() > 1 ? "s" : "") << "!\n" << std::endl;

		auto propertyStreamType = std::dynamic_pointer_cast<const adtf_file::PropertyStreamType>(targetStream.initial_type);
		std::string streamMetaType = propertyStreamType->getMetaType();

		OutputType outType = OutputType::NONE;

		if (propertyStreamType)
		{
			std::cout << "Stream Info: " << std::endl;
			std::cout << "    ID      : " << targetStream.stream_id << std::endl;
			std::cout << "    Pin Name: " << targetStream.name << std::endl;
			std::cout << "    MetaType: " << streamMetaType << std::endl;

			if (strcmp(streamMetaType.c_str(), PROP_ADTF_IMAGE) == 0)
			{
				std::set<std::string>::iterator it = SUPPORTED_IMG_FORMATS.find(outFormat);
				std::set<std::string>::iterator it2 = SUPPORTED_VIDEO_FORMATS.find(outFormat);

				//ensure output format is one of QT5's supported formats, or opencvs video formats (consolidate?)
				if (it == SUPPORTED_IMG_FORMATS.end() && it2 == SUPPORTED_VIDEO_FORMATS.end())
				{
					std::cout << "ERROR: Output image/video format not supported. Supported formats include: ";
					for (std::set<std::string>::iterator iter = SUPPORTED_IMG_FORMATS.begin(); iter != SUPPORTED_IMG_FORMATS.end(); ++iter)
					{
						std::cout << *iter << ' ';
					}
					for (std::set<std::string>::iterator iter = SUPPORTED_VIDEO_FORMATS.begin(); iter != SUPPORTED_VIDEO_FORMATS.end(); ++iter)
					{
						std::cout << *iter << ' ';
					}
					return static_cast<int>(ErrorCodes::INVALID_OUTPUT_FORMAT_ERROR);
				}

				if (it != SUPPORTED_IMG_FORMATS.end())
				{
					outType = OutputType::IMAGE;
				}
				else
				{
					outType = OutputType::VIDEO;
				}

 				std::cout << "\nImage Stream Properties: " << std::endl;
				std::cout << "    " << PROP_PIXEL_HEIGHT << "  : " << masterFormat.height << std::endl;
				std::cout << "    " << PROP_PIXEL_WIDTH << "   : " << masterFormat.width << std::endl;
				std::cout << "    " << PROP_BITS_PER_PIXEL << ": " << masterFormat.depthBytes * 8 << std::endl;
				std::cout << "    " << PROP_COLOR_FORMAT << "   : " << masterFormat.colorFormat << std::endl;

				if (masterFormat.width == 0 ||
					masterFormat.height == 0 ||
					masterFormat.depthBytes == 0 ||
					strcmp(masterFormat.colorFormat.c_str(), "None") == 0)
				{
					std::cerr << "ERROR: Unable to parse image stream properties." << std::endl;
					return static_cast<int>(ErrorCodes::IO_ERROR);
				}
			}
			else if (ContainsScanData(reader, targetStream.stream_id))
			{
				std::set<std::string>::iterator it = SUPPORTED_POINTCLOUD_FORMATS.find(outFormat);
				outFormatLower = outFormatLower.substr(0, 3);
				
				//ensure output format is one of PCL's supported formats
				if (it == SUPPORTED_POINTCLOUD_FORMATS.end())
				{
					std::cout << "ERROR: Output pointcloud format not supported. Supported formats include: ";
					for (std::set<std::string>::iterator iter = SUPPORTED_POINTCLOUD_FORMATS.begin(); iter != SUPPORTED_POINTCLOUD_FORMATS.end(); ++iter)
					{
						std::cout << *iter << ' ';
					}
					return static_cast<int>(ErrorCodes::INVALID_OUTPUT_FORMAT_ERROR);
				}
				else
				{
					outType = OutputType::POINTCLOUD;
				}
			}
			else
			{
				std::cerr << "ERROR: Stream does not contain image or point cloud buffers." << std::endl;
				return static_cast<int>(ErrorCodes::UNSUPPORTED_STREAM_TYPE_ERROR);
			}
		}

		std::cout << "\nTotal stream item count: " << targetStream.item_count << std::endl;

		uint64_t frameCounter = 1;
		uint64_t framesToProcess = targetStream.item_count;
	
		if (skipRate > 0)
		{
			framesToProcess = targetStream.item_count / (skipRate + 1) + 1;
		}

		//reset stream
		os.str(std::string());

		os << outPath << '/' << targetPinNames[0];
		outPath = os.str();

		//check if output directory exists. If not, create it.
		if (stat(outPath.c_str(), &info) != 0)
		{
			_mkdir(outPath.c_str());
		}

		std::string filename = datFile.getLastElement();
		filename = filename.substr(0, filename.length() - (datFile.getExtension().length() + 1));

		std::cout << "Items to process (after skipped frames): " << framesToProcess << std::endl << std::endl;

		cv::VideoWriter videoWriter;
		cv::Size videoResolution;

		//prepare videowriter 
		if (outType == OutputType::VIDEO)
		{
			auto it = FOURCC_CODES.find(outFormat);

			if (it != FOURCC_CODES.end())
			{
				os << '/' << filename << '.' << outFormatLower;
				std::string videoOutPath = os.str();
				std::chrono::seconds streamLengthSec = std::chrono::duration_cast<std::chrono::seconds>(targetStream.timestamp_of_last_item - targetStream.timestamp_of_first_item);
				double_t frameRate = static_cast<double_t>(targetStream.item_count) / static_cast<double_t>(streamLengthSec.count());

				if (targetStreams.size() == 1)
				{
					videoResolution = downscale ? cv::Size(masterFormat.width / 4, masterFormat.height / 4) :
						                          cv::Size(masterFormat.width, masterFormat.height);
				}
				else if (targetStreams.size() == 2)
				{
					videoResolution = downscale ? cv::Size(masterFormat.width / 4, (2 * masterFormat.height) / 4) :
						                          cv::Size(masterFormat.width, 2 * masterFormat.height);
				}
				else
				{
					videoResolution = downscale ? cv::Size((2 * masterFormat.width) / 4, (2 * masterFormat.height) / 4) :
						                          cv::Size(2 * masterFormat.width, 2 * masterFormat.height);
				}

				if (!videoWriter.open(videoOutPath,
					                  cv::CAP_ANY,
					                  it->second,
					                  frameRate,
					                  videoResolution,
					                  true))
				{
					std::cout << "ERROR: Unable to initialize OpenCV video writer." << std::endl;
					return static_cast<int>(ErrorCodes::OPENCV_ERROR);
				}
			}
		}

		for (uint64_t i = 0; i < targetStream.item_count; i += skipRate + 1)
		{
			uint64_t itemIndex = reader.getItemIndexForStreamItemIndex(targetStream.stream_id, i);
			reader.seekTo(itemIndex);
			adtf_file::FileItem item = reader.getNextItem();
			
			auto data = std::dynamic_pointer_cast<const adtf_file::Sample>(item.stream_item);

			if (data)
			{
				auto sampleData = std::dynamic_pointer_cast<const adtf_file::DefaultSample>(data);

				std::vector<std::shared_ptr<const adtf_file::DefaultSample> > complementarySamples;

				if (targetStreams.size() > 1)
				{
					for(uint64_t sampleIndex = 1; sampleIndex < targetStreams.size(); ++sampleIndex)
					{
						if (targetStreams[sampleIndex].first.item_count == 0)
						{
							std::cout << "ERROR: Slave target stream contains no elements" << std::endl;
							return static_cast<int>(ErrorCodes::ADTF_FILE_ERROR);
						}

						// assume all streams have same temporal length. If sample rate differs,
						// get relative index to targetStream's current index
						uint64_t relativeIndex = i * static_cast<float>(targetStreams[sampleIndex].first.item_count) / (static_cast<float>(targetStream.item_count));

						if (relativeIndex < targetStreams[sampleIndex].first.item_count)
						{
							uint64_t currentIndex = reader.getItemIndexForStreamItemIndex(targetStreams[sampleIndex].first.stream_id,
								                                                          relativeIndex);
							reader.seekTo(currentIndex);
							adtf_file::FileItem currentItem = reader.getNextItem();

							auto currentData = std::dynamic_pointer_cast<const adtf_file::Sample>(currentItem.stream_item);
							complementarySamples.push_back(std::dynamic_pointer_cast<const adtf_file::DefaultSample>(currentData));
						}
						else
						{
							std::cout << "ERROR: Error calculating relative sample index" << std::endl;
							return static_cast<int>(ErrorCodes::ADTF_FILE_ERROR);
						}
					}
				}

				if (sampleData)
				{
					//resetting stream
					os.str(std::string());
					os << "Processing Item (" << std::to_string(frameCounter++) << \
						" / " + std::to_string(framesToProcess) << ")";
					std::string status = os.str();

					std::cout << status;

					std::chrono::microseconds usTimeStamp = sampleData->getTimeStamp();
					std::string usTimeStampString = a_util::strings::format("%lld", usTimeStamp.count());

					//resetting stream
					os.str(std::string());

					os << outPath << '/' << filename << '_' << usTimeStampString << '.' << outFormatLower;

					std::string filePath = os.str();

					if (strcmp(streamMetaType.c_str(), PROP_ADTF_IMAGE) == 0)
					{
						vector<const uint8_t*> imageBuffers;
						const uint8_t* imageBuffer = sampleData->getContent<uint8_t>();

						if (complementarySamples.size() > 0)
						{
							imageBuffers.push_back(imageBuffer);

							for(auto sample : complementarySamples)
							{
								imageBuffers.push_back(sample->getContent<uint8_t>());
							}
						}

						uint32_t frameSizeBytes = masterFormat.height * masterFormat.width * masterFormat.depthBytes;

						if (outType == OutputType::IMAGE)
						{
							std::vector<uint8_t> rgbBuffer;

							QImage qImage;
							if (targetStreams[0].second.depthBytes == 4)
							{
								//copy from 32-bit RGBA buffer to 24-bit RGB buffer. Note that ADTF 32-bit
								//raw image format has incorrectly zeroed alpha channel
								for (uint32_t j = 0; j < frameSizeBytes; j += masterFormat.depthBytes)
								{
									rgbBuffer.push_back(imageBuffer[j]);
									rgbBuffer.push_back(imageBuffer[j + 1]);
									rgbBuffer.push_back(imageBuffer[j + 2]);
								}

								qImage = QImage(rgbBuffer.data(),
									            masterFormat.width,
									            masterFormat.height,
									            QImage::Format_RGB888);
							}
							else
							{
								qImage = QImage(imageBuffer,
									            masterFormat.width,
									            masterFormat.height,
									            QImage::Format_RGB888);
							}

							if (!qImage.rgbSwapped().save(QString(filePath.c_str()), outFormat.c_str(), 100))
							{
								std::cerr << "\nERROR: Failed to write output file, " << filePath << '.' << std::endl;
								return static_cast<int>(ErrorCodes::QT_ERROR);
							}
						}
						else
						{
							if (targetStreams.size() == 1)
							{
								cv::Mat frame(masterFormat.height,
									          masterFormat.width,
									          CV_8UC3);
								uint32_t index = 0;

								for (uint32_t j = 0; j < frameSizeBytes; j += targetStreams[0].second.depthBytes)
								{
									frame.data[index++] = imageBuffer[j];
									frame.data[index++] = imageBuffer[j + 1];
									frame.data[index++] = imageBuffer[j + 2];
								}
								cv::Mat resized;

								cv::resize(frame,
									       resized,
									       videoResolution,
									       0,
									       0,
									       cv::INTER_CUBIC);

								videoWriter.write(resized);
							}
							else
							{
								std::vector<cv::Mat> subFrames;

								for (size_t bufferIndex = 0; bufferIndex < imageBuffers.size(); ++bufferIndex)
								{
									uint32_t dstIndex = 0;

									cv::Mat subFrame(targetStreams[bufferIndex].second.height,
										             targetStreams[bufferIndex].second.width,
										             CV_8UC3);

									uint32_t frameSize = targetStreams[bufferIndex].second.height * targetStreams[bufferIndex].second.width * targetStreams[bufferIndex].second.depthBytes;

									for (size_t srcIndex = 0; srcIndex < frameSize; srcIndex += targetStreams[bufferIndex].second.depthBytes)
									{
										subFrame.data[dstIndex++] = imageBuffers[bufferIndex][srcIndex];
										subFrame.data[dstIndex++] = imageBuffers[bufferIndex][srcIndex + 1];
										subFrame.data[dstIndex++] = imageBuffers[bufferIndex][srcIndex + 2];
									}

									if (masterFormat.width != targetStreams[bufferIndex].second.width)
									{
										cv::Mat resized;

										cv::resize(subFrame,
											       resized,
											       cv::Size(masterFormat.width,
												            masterFormat.height),
											       0,
											       0,
											       cv::INTER_CUBIC);

										subFrames.push_back(resized);
									}
									else
									{
										subFrames.push_back(subFrame);
									}
								}

								cv::Mat composite;

								if (subFrames.size() == 2)
								{
									composite = cv::Mat(2 * masterFormat.height,
										                masterFormat.width,
										                CV_8UC3);

									size_t dstIndex = 0;
									for (cv::Mat subFrame : subFrames)
									{
										for (size_t srcIndex = 0; srcIndex < frameSizeBytes; ++srcIndex)
										{
											composite.data[dstIndex++] = subFrame.data[srcIndex];
										}
									}
								}
								else if (targetStreams.size() <= 4)
								{
									composite = cv::Mat(2 * masterFormat.height,
										                2 * masterFormat.width,
										                CV_8UC3);

									size_t index = 0;
									uint32_t stride = frameSizeBytes / masterFormat.height;

									for (size_t y = 0; y < masterFormat.height; ++y)
									{
										for (size_t x = 0; x < stride; ++x)
										{
											composite.data[(y * 2 * stride) + x] = subFrames[0].data[index];
											composite.data[(y * 2 * stride) + stride + x] = subFrames[1].data[index];
											composite.data[(y * 2 * stride) + (2 * frameSizeBytes) + x] = subFrames[2].data[index];
											
											if (subFrames.size() == 4)
											{
												composite.data[(y * 2 * stride) + (2 * frameSizeBytes) + stride + x] = subFrames[3].data[index];
											}
											++index;
										}
									}
								}
								else
								{
									std::cerr << "\nERROR: Unable to composite more than 4 streams" << std::endl;
									return static_cast<int>(ErrorCodes::IMAGE_COMPOSITE_ERRER);
								}


								cv::Mat resized;
								cv::resize(composite,
									       resized,
									       videoResolution,
									       0,
									       0,
									       cv::INTER_CUBIC);

								videoWriter.write(resized);
							}
						}						
					}
					else
					{
						sScanData3D scanData;
						if (!CopyScanData(sampleData->getContent<uint8_t>(), sampleData->GetBufferSize(), &scanData))
						{
							return static_cast<int>(ErrorCodes::UNSUPPORTED_STREAM_TYPE_ERROR);
						}

						pcl::PointCloud<pcl::PointXYZ> pointCloud;
						pointCloud.width = scanData.pointsCount;
						//height of 1 indicates that we're working with an unorganized set of points
						pointCloud.height = 1;
						//this field indicates if values in the dataset may be NaN (false) or finite (true)
						pointCloud.is_dense = true;

						pointCloud.points.resize(pointCloud.width);

						for (uint32_t pointIndex = 0; pointIndex < scanData.pointsCount; ++pointIndex)
						{
							pointCloud.points[pointIndex].x = scanData.points[pointIndex].lidarPoint.x;
							pointCloud.points[pointIndex].y = scanData.points[pointIndex].lidarPoint.y;
							pointCloud.points[pointIndex].z = scanData.points[pointIndex].lidarPoint.z;
						}

						if (strcmp(outFormat.c_str(), "PCD_ASCII") == 0)
						{
							pcl::io::savePCDFileASCII(filePath, pointCloud);
						}
						else if (strcmp(outFormat.c_str(), "PCD_BIN") == 0 || strcmp(outFormat.c_str(), "PCD") == 0)
						{
							pcl::io::savePCDFileBinary(filePath, pointCloud);
						}
						else if (strcmp(outFormat.c_str(), "PCD_BIN_COMPRESSED") == 0)
						{
							pcl::io::savePCDFileBinaryCompressed(filePath, pointCloud);
						}
					}

					if (i < targetStream.item_count - 1)
					{
						std::cout << std::string(status.length(), '\b');
					}
				}
			}
		}

		if (outType == OutputType::VIDEO)
		{
			videoWriter.release();
		}

		std::cout << "\nFinished!" << std::endl;
	}
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return static_cast<int>(ErrorCodes::EXCEPTION_OCCURRED);
    }

    return static_cast<int>(ErrorCodes::SUCCESS);
}
