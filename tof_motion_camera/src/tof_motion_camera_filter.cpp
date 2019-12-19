/**
 * quanergy_decoder.cpp
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2016-08-31 #$
 * @version $Revision:: 3801    $
 * @author  $Author:: pike9269  $
 */

#include "stdafx.h"
#include "tof_motion_camera_filter.h"
#include "Cfl_SetController.h"
#include "Rtl16_ImageDataFormatReg.h"

const tChar* cTofMotionCameraFilter::OID_ADTF_TOF_MOTION_CAMERA_FILTER = "adtf.eb.tofmotion";
const tChar* cTofMotionCameraFilter::NAME_ADTF_TOF_MOTION_CAMERA_FILTER = "ToF Motion Camera Filter";

const cString cTofMotionCameraFilter::PROPERTY_UDP_TIMEOUT_USEC = "Filter Settings::Timeout usec";
const cString cTofMotionCameraFilter::PROPERTY_UDP_LISTENING_PORT = "Filter Settings::UDP Listening Port";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_X = "Filter Settings::Camera Mounting Position X";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_Y = "Filter Settings::Camera Mounting Position Y";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_Z = "Filter Settings::Camera Mounting Position Z";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_PITCH = "Filter Settings::Camera Mounting Pitch (x-rotation)";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_YAW = "Filter Settings::Camera Mounting Yaw (y-rotation)";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_ROLL = "Filter Settings::Camera Mounting Roll (z-rotation)";
const cString cTofMotionCameraFilter::PROPERTY_DISTANCE_GAIN = "Filter Settings::Distance gain (decibels)";
const cString cTofMotionCameraFilter::PROPERTY_AMPLITUDE_GAIN = "Filter Settings::Amplitude gain (decibels)";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_LOG_LEVEL = "ToF Motion Camera Settings::Log Level\n0 = No Logging\n1 = Error\n2 = Warning\n3 = Info\n4 = Debug";
const cString cTofMotionCameraFilter::PROPERTY_UPDATE_CAMERA_SETTINGS = "ToF Motion Camera Settings::Change Camera Settings\nTrue: Update ToF camera settings upon next initialization\nFalse: Do not update camera settings";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR = "ToF Motion Camera Settings::TCP/IPv4 Address";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_TCPIP_PORT = "ToF Motion Camera Settings::TCP/IPv4 Port";
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT = "ToF Motion Camera Settings::Output Image Format\n0 = DISTAMP\n3 = XYZ\n4 = XYZA\n9 = DISTXYZ\n10 = OPTAXIS\n11 = TESTMODE\n12 = DIST\n13 = RAWDISTAMP\n23 = DISTAMPBAL\n24 = RAWPHASES";

const tUInt32 cTofMotionCameraFilter::PROPERTY_UDP_TIMEOUT_USEC_DEFAULT = 100000;
const tUInt16 cTofMotionCameraFilter::PROPERTY_UDP_LISTENING_PORT_DEFAULT = 10002;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_X_DEFAULT = 0.0f;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_Y_DEFAULT = 0.0f;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_POS_Z_DEFAULT = 0.0f;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_PITCH_DEFAULT = 0.0f;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_YAW_DEFAULT = 0.0f;
const tFloat cTofMotionCameraFilter::PROPERTY_CAMERA_MOUNT_ROLL_DEFAULT = 0.0f;
const tUInt8 cTofMotionCameraFilter::PROPERTY_DISTANCE_GAIN_DEFAULT = 0;
const tUInt8 cTofMotionCameraFilter::PROPERTY_AMPLITUDE_GAIN_DEFAULT = 0;
const tUInt8 cTofMotionCameraFilter::PROPERTY_LOG_LEVEL_DEFAULT = 1;
const tBool cTofMotionCameraFilter::PROPERTY_UPDATE_CAMERA_SETTINGS_DEFAULT = false;
const cString cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR_DEFAULT = "192.168.0.10";
const tUInt16 cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_TCPIP_PORT_DEFAULT = 10001;
const tUInt8 cTofMotionCameraFilter::PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT_DEFAULT = 0;

const tUInt8 cTofMotionCameraFilter::TOF_COLOR_DEPTH_BITS = 16;
const tUInt8 cTofMotionCameraFilter::TOF_FRAME_HEADER_SIZE_BYTES = 64;
const cImage::tPixelFormat cTofMotionCameraFilter::TOF_PIXEL_FORMAT = cImage::PF_GREYSCALE_16;
//const cImage::tPixelFormat cTofMotionCameraFilter::TOF_PIXEL_FORMAT = cImage::PF_RGB_565;
const tUInt16 cTofMotionCameraFilter::TOF_RESOLUTION_X = 320;
const tUInt16 cTofMotionCameraFilter::TOF_RESOLUTION_Y = 240;
const tUInt16 cTofMotionCameraFilter::TOF_BYTES_PER_LINE = cTofMotionCameraFilter::TOF_RESOLUTION_X *
                                                           (cTofMotionCameraFilter::TOF_COLOR_DEPTH_BITS / 8);
const tUInt32 cTofMotionCameraFilter::TOF_FRAME_SIZE = 2 * (cTofMotionCameraFilter::TOF_BYTES_PER_LINE *
                                                            cTofMotionCameraFilter::TOF_RESOLUTION_Y) +
                                                       cTofMotionCameraFilter::TOF_FRAME_HEADER_SIZE_BYTES;

//from spec sheet at https://drive.google.com/file/d/1SsqQaMEJybtkXtcVUCpcJ3YrC9h29nkH/view
const tFloat cTofMotionCameraFilter::TOF_HORIZONTAL_FOV = 1.0821f;
const tFloat cTofMotionCameraFilter::TOF_VERTICAL_FOV = 0.837758f;

ADTF_FILTER_PLUGIN(cTofMotionCameraFilter::NAME_ADTF_TOF_MOTION_CAMERA_FILTER,
                   cTofMotionCameraFilter::OID_ADTF_TOF_MOTION_CAMERA_FILTER,
                   cTofMotionCameraFilter);

cTofMotionCameraFilter::cTofMotionCameraFilter(const tChar* __info) :
    cTimeTriggeredFilter(__info),
    m_frameController(),
    m_outputDistanceImage(),
    m_outputAmplitudeImage(),
    m_outputScanData(),
    m_distanceImage(),
    m_amplitudeImage(),
    m_scanData3D(TOF_RESOLUTION_X * TOF_RESOLUTION_Y),
    m_imageBuffer(NULL),
    m_scanDataBuffer(NULL)
{
    //Filter settings
    SetPropertyInt(PROPERTY_UDP_TIMEOUT_USEC,
                   PROPERTY_UDP_TIMEOUT_USEC_DEFAULT);

    SetPropertyInt(PROPERTY_UDP_LISTENING_PORT,
                   PROPERTY_UDP_LISTENING_PORT_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_X,
                     PROPERTY_CAMERA_MOUNT_POS_X_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_Y,
                     PROPERTY_CAMERA_MOUNT_POS_Y_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_Z,
                     PROPERTY_CAMERA_MOUNT_POS_Z_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_PITCH,
                     PROPERTY_CAMERA_MOUNT_PITCH_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_YAW,
                     PROPERTY_CAMERA_MOUNT_YAW_DEFAULT);

    SetPropertyFloat(PROPERTY_CAMERA_MOUNT_ROLL,
                     PROPERTY_CAMERA_MOUNT_ROLL_DEFAULT);

    SetPropertyFloat(PROPERTY_DISTANCE_GAIN,
                     PROPERTY_DISTANCE_GAIN_DEFAULT);

    SetPropertyFloat(PROPERTY_AMPLITUDE_GAIN,
                     PROPERTY_AMPLITUDE_GAIN_DEFAULT);

    //Camera settings
    SetPropertyInt(PROPERTY_CAMERA_LOG_LEVEL,
                   PROPERTY_LOG_LEVEL_DEFAULT);

    SetPropertyBool(PROPERTY_UPDATE_CAMERA_SETTINGS,
                    PROPERTY_UPDATE_CAMERA_SETTINGS_DEFAULT);

    SetPropertyStr(PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR,
                   PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR_DEFAULT);

    SetPropertyInt(PROPERTY_CAMERA_SETTINGS_TCPIP_PORT,
                   PROPERTY_CAMERA_SETTINGS_TCPIP_PORT_DEFAULT);

    SetPropertyInt(PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT,
                   PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT_DEFAULT);
}

tResult cTofMotionCameraFilter::Shutdown(tInitStage i_stage, __exception)
{
    if (m_frameController)
    {
        m_frameController.release();
    }

    if (m_imageBuffer)
    {
        delete[] m_imageBuffer;
        m_imageBuffer = NULL;
    }

    if (m_scanDataBuffer)
    {
        delete[] m_scanDataBuffer;
        m_scanDataBuffer = NULL;
    }

    return cTimeTriggeredFilter::Shutdown(i_stage, __exception_ptr);
}

tResult cTofMotionCameraFilter::Init(tInitStage i_stage, __exception)
{
    RETURN_IF_FAILED(cTimeTriggeredFilter::Init(i_stage, __exception_ptr));

    if (i_stage == StageFirst)
    {
        //Configure distance output pin
        m_outputDistanceImage.Create("out_distance_video",
                                      IPin::PD_Output,
                                      MEDIA_TYPE_VIDEO,
                                      MEDIA_SUBTYPE_VIDEO_UNCOMPRESSED,
                                      static_cast<IPinEventSink*>(this));
        RegisterPin(&m_outputDistanceImage);

        //Configure amplitude output pin
        m_outputAmplitudeImage.Create("out_amplitude_video",
                                      IPin::PD_Output,
                                      MEDIA_TYPE_VIDEO,
                                      MEDIA_SUBTYPE_VIDEO_UNCOMPRESSED,
                                      static_cast<IPinEventSink*>(this));
        RegisterPin(&m_outputAmplitudeImage);

        //Configure point cloud output pin
        m_outputScanData.Create("out_scan_data_3D",
                                cObjectPtr<IMediaType>(new cMediaType(MEDIA_TYPE_EB_ROBINOS,
                                                                      MEDIA_SUBTYPE_POINT_CLOUD_3D)),
                                static_cast<IPinEventSink*>(this));
        RegisterPin(&m_outputScanData);
    }
    else if (i_stage == StageNormal)
    {
        //EB_ROBINOS_CHECK_LICENSE(OID_ADTF_TOF_MOTION_CAMERA_FILTER);

        tUInt32 timeoutUsec = static_cast<tUInt32>(GetPropertyInt(PROPERTY_UDP_TIMEOUT_USEC));
        tUInt16 port = static_cast<tUInt16>(GetPropertyInt(PROPERTY_UDP_LISTENING_PORT));
        tUInt8 logLevelProp = static_cast<tUInt8>(GetPropertyInt(PROPERTY_CAMERA_LOG_LEVEL));

        Common::UseLogger::LogLevel_e logLevel = Common::UseLogger::S_NO_LOGGING;
        logLevel = logLevelProp == 4 ? Common::UseLogger::S_DEBUG : logLevel;
        logLevel = logLevelProp == 3 ? Common::UseLogger::S_INFO : logLevel;
        logLevel = logLevelProp == 2 ? Common::UseLogger::S_WARN : logLevel;
        logLevel = logLevelProp == 1 ? Common::UseLogger::S_ERROR : logLevel;

        tBool changeCamSettings = static_cast<tBool>(GetPropertyBool(PROPERTY_UPDATE_CAMERA_SETTINGS));

        if (changeCamSettings)
        {
            tResult retVal = UpdateCameraSettings(logLevel, timeoutUsec);

            if (retVal == ERR_UNKNOWN_FORMAT)
            {
                LogError("Unable to update ToF Motion camera output format");
            }
        }

        m_frameController.reset(new UdpFrame::FrameController("UdpFrameCtrl",
                                                              port,
                                                              logLevel,
                                                              0,
                                                              timeoutUsec > 0 ? timeoutUsec :
                                                                                1));

        SetInterval(timeoutUsec);

        tBitmapFormat format;
        format.nWidth = TOF_RESOLUTION_X;
        format.nHeight = TOF_RESOLUTION_Y;
        format.nBitsPerPixel = TOF_COLOR_DEPTH_BITS;
        format.nPixelFormat = TOF_PIXEL_FORMAT;
        format.nBytesPerLine = TOF_BYTES_PER_LINE;
        format.nSize = TOF_BYTES_PER_LINE * TOF_RESOLUTION_Y;

        m_distanceImage.Create(&format);
        m_amplitudeImage.Create(&format);

        m_outputDistanceImage.SetFormat(&format, NULL);
        m_outputAmplitudeImage.SetFormat(&format, NULL);

        m_imageBuffer = new tUInt8[m_distanceImage.GetSize()];

        m_scanData3D.mountingPosition = sPoint6D<tFloat>(GetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_X),
                                                         GetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_Y),
                                                         GetPropertyFloat(PROPERTY_CAMERA_MOUNT_POS_Z),
                                                         GetPropertyFloat(PROPERTY_CAMERA_MOUNT_YAW),
                                                         GetPropertyFloat(PROPERTY_CAMERA_MOUNT_ROLL),
                                                         GetPropertyFloat(PROPERTY_CAMERA_MOUNT_PITCH));

        tUInt32 pointCloudSize = m_scanData3D.pointsCount * sizeof(sLidarPoint3D);

        memset(m_scanData3D.points, 0, pointCloudSize);
        m_scanDataBuffer = new tUInt8[sizeof(sPoint6D<>) + sizeof(m_scanData3D.points) + pointCloudSize];

        m_distGain = static_cast<tUInt8>(GetPropertyInt(PROPERTY_DISTANCE_GAIN));
        m_ampGain = static_cast<tUInt8>(GetPropertyInt(PROPERTY_AMPLITUDE_GAIN));
    }

    RETURN_NOERROR;
}

tResult cTofMotionCameraFilter::Cycle(__exception)
{
    tUInt32 offset = 0;
    tUInt8 frameBuffer[TOF_FRAME_SIZE];

    if (m_frameController->GetFrame(frameBuffer,
                                    TOF_FRAME_SIZE,
                                    offset))
    {
        tUInt8* startIndex = frameBuffer + TOF_FRAME_HEADER_SIZE_BYTES;

        if (m_distGain > 0)
        {
            ApplyGain(startIndex,
                      m_distGain,
                      m_distanceImage.GetSize());
        }

        m_distanceImage.SetBits(startIndex,
                                m_distanceImage.GetFormat());
        
        if (m_ampGain > 0)
        {
            ApplyGain(startIndex + m_distanceImage.GetSize(),
                      m_ampGain,
                      m_amplitudeImage.GetSize());
        }

        m_amplitudeImage.SetBits(startIndex + m_distanceImage.GetSize(),
                                 m_amplitudeImage.GetFormat());

        PopulatePointCloudFromDistanceMap();

        return SendOutputs();
    }
    else
    {
        LogInfo("GetFrame() timed out waiting for camera");
    }

    RETURN_NOERROR;
}

tResult cTofMotionCameraFilter::SendOutputs()
{
    memcpy(m_imageBuffer, m_distanceImage.GetBitmap(), m_distanceImage.GetSize());
    cObjectPtr<IMediaSample> mediaSample;

    if (IS_OK(AllocMediaSample((tVoid**)&mediaSample, OID_ADTF_MEDIA_SAMPLE)))
    {
        if (IS_OK(mediaSample->Update(_clock->GetStreamTime(),
                                      (tVoid*)m_imageBuffer,
                                      m_distanceImage.GetSize(),
                                      IMediaSample::MSF_None)))
        {
            LogInfo("Distance image transmitted successfully");
            m_outputDistanceImage.Transmit(mediaSample);
        }
    }

    memcpy(m_imageBuffer, m_amplitudeImage.GetBitmap(), m_amplitudeImage.GetSize());

    if (IS_OK(AllocMediaSample((tVoid**)&mediaSample, OID_ADTF_MEDIA_SAMPLE)))
    {
        if (IS_OK(mediaSample->Update(_clock->GetStreamTime(),
                                      (tVoid*)m_imageBuffer,
                                      m_amplitudeImage.GetSize(),
                                      IMediaSample::MSF_None)))
        {
            LogInfo("Amplitude image transmitted successfully");
            m_outputAmplitudeImage.Transmit(mediaSample);
        }
    }

    memcpy(m_scanDataBuffer,
           &m_scanData3D.mountingPosition,
           sizeof(sPoint6D<>));
    memcpy(m_scanDataBuffer + sizeof(sPoint6D<>),
           &m_scanData3D.pointsCount,
           sizeof(m_scanData3D.pointsCount));
    memcpy((m_scanDataBuffer + sizeof(sPoint6D<>) + sizeof(m_scanData3D.pointsCount)),
           m_scanData3D.points,
           sizeof(sLidarPoint3D) * m_scanData3D.pointsCount);

    tUInt32 scanDataSize = sizeof(sPoint6D<>) +
                           sizeof(m_scanData3D.pointsCount) +
                           (sizeof(sLidarPoint3D) * m_scanData3D.pointsCount);
    
    if (IS_OK(AllocMediaSample((tVoid**)&mediaSample, OID_ADTF_MEDIA_SAMPLE)))
    {
        if (IS_OK(mediaSample->Update(_clock->GetStreamTime(),
                                      (tVoid*)m_scanDataBuffer,
                                      scanDataSize,
                                      IMediaSample::MSF_None)))
        {
            m_outputScanData.Transmit(mediaSample);
        }
    }

    return NOERROR;
}

tResult cTofMotionCameraFilter::UpdateCameraSettings(Common::UseLogger::LogLevel_e logLevel, tUInt32 timeoutUsec)
{
    std::string ipv4Address = static_cast<std::string>(GetPropertyStr(PROPERTY_CAMERA_SETTINGS_TCPIP_ADDR));
    tUInt16 ipv4Port = static_cast<tUInt16>(GetPropertyInt(PROPERTY_CAMERA_SETTINGS_TCPIP_PORT));
    tUInt8 imageFormat = static_cast<tUInt8>(GetPropertyInt(PROPERTY_CAMERA_SETTINGS_IMAGE_FORMAT));

    Cfl::SetController cameraController("CflCtrl",
                                        ipv4Address,
                                        ipv4Port,
                                        logLevel,
                                        0,
                                        timeoutUsec);
    std::string format = "DISTAMP";

    switch (imageFormat)
    {
    case 3:
        format = "XYZ";
        break;
    case 4:
        format = "XYZA";
        break;
    case 9:
        format = "DISTXYZ";
        break;
    case 10:
        format = "OPTAXIS";
        break;
    case 11:
        format = "TESTMODE";
        break;
    case 12:
        format = "DIST";
        break;
    case 13:
        format = "RAWDISTAMP";
        break;
    case 23:
        format = "DISTAMPBAL";
        break;
    case 24:
        format = "RAWPHASES";
        break;
    default:
        format = "INVALID";
        break;
    }

    Rtl16::ImageDataFormatReg imgFormatRegister;
    if (!imgFormatRegister.SetFromStringImageDataFormat(format))
    {
        RETURN_ERROR(ERR_UNKNOWN_FORMAT);
    }
    else
    {
        if (!cameraController.WriteRegister(imgFormatRegister))
        {
            RETURN_ERROR(ERR_UNKNOWN_FORMAT);
        }
    }

    //TODO: Add other settings

    RETURN_NOERROR;
}

void cTofMotionCameraFilter::PopulatePointCloudFromDistanceMap()
{
    tUInt8* distMap = m_distanceImage.GetBitmap();
    tInt size = m_distanceImage.GetSize();
    //FILE* f = fopen("d:\\pcl.txt", "a");
    //fputs("start\n", f);

    for (tInt i = 0; i < size / 2; ++i)
    {
        tInt mapIndex = 2 * i;
     
        tUInt row = i / TOF_RESOLUTION_X;
        tUInt col = i % TOF_RESOLUTION_X;

        //tUInt16 depth = distMap[mapIndex] << 8 | distMap[mapIndex + 1]; //nope, looks terrible
        tUInt16 depth = distMap[mapIndex + 1] << 8 | distMap[mapIndex]; //why does reversed order bytes provide the most sensical depth values?
        //tUInt16 depth = ReverseBits(distMap[mapIndex] << 8 | distMap[mapIndex + 1]); //nope, looks terrible

        tFloat alphaH = (M_PI - TOF_HORIZONTAL_FOV) / 2;
        tFloat gammaH = alphaH + (col * (TOF_HORIZONTAL_FOV / TOF_RESOLUTION_X));
        m_scanData3D.points[i].lidarPoint.x = static_cast<tFloat32>(depth / tan(gammaH));

        tFloat alphaV = (2 * M_PI) - (TOF_VERTICAL_FOV / 2);
        tFloat gammaV = alphaV + (row * (TOF_VERTICAL_FOV / TOF_RESOLUTION_Y));
        m_scanData3D.points[i].lidarPoint.y = static_cast<tFloat32>(-depth * tan(gammaV));

        m_scanData3D.points[i].lidarPoint.z = depth;

        //stringstream ss;
        //ss << m_scanData3D.points[i].lidarPoint.x << " " << m_scanData3D.points[i].lidarPoint.y << " " << m_scanData3D.points[i].lidarPoint.z << endl;

        //fputs(ss.str().c_str(), f);
    }
    //fputs("end\n", f);
    //fclose(f);
}

void cTofMotionCameraFilter::LogInfo(cString infoString)
{
    stringstream ss;
    ss << OID_ADTF_TOF_MOTION_CAMERA_FILTER << ": " << infoString;
    LOG_INFO(ss.str().c_str());
}

void cTofMotionCameraFilter::LogError(cString errorString)
{
    stringstream ss;
    ss << OID_ADTF_TOF_MOTION_CAMERA_FILTER << ": " << errorString;
    LOG_ERROR(ss.str().c_str());
}

void cTofMotionCameraFilter::ApplyGain(tUInt8* data, tUInt8 gain, tInt size)
{
    tFloat deltaIntensity = pow(2.0, gain / 10);

    for (tInt i = 0; i < size; i += 2)
    {
        tUInt16 value = data[i] << 8 | data[i + 1];

        tUInt32 amplified = static_cast<tUInt32>(value * deltaIntensity);

        if (amplified > UINT16_MAX)
        {
            amplified = UINT16_MAX;
        }

        value = static_cast<tUInt16>(amplified);

        data[i] = value >> 8;
        data[i + 1] = value & 0x00FF;
    }
}

//tUInt16 cTofMotionCameraFilter::ReverseBits(const tUInt16 input)
//{
//    tUInt16 num = input;
//    tUInt16 reversed = num;
//    tUInt8 count = sizeof(num) * 8 - 1;
//
//    num >>= 1;
//
//    while (num)
//    {
//        reversed <<= 1;
//        reversed |= num & 0x1;
//        num >>= 1;
//        --count;
//    }
//
//    reversed <<= count;
//    return reversed;
//}

//void cTofMotionCameraFilter::ConvertDistanceImage(sScanData* outScanData)
//{
//    outScanData->pointsCount = 0;
//    outScanData->points = new sLidarPoint3D[TOF_RESOLUTION_X * TOF_RESOLUTION_Y];
//}

//std::vector<tUInt8> cTofMotionCameraFilter::convertScalarRasterToRedGreenRaster(tUInt8* input, tUInt64 size)
//{
//    std::vector<tUInt8> outRaster;
//
//    for (size_t i = 0; i < size; i += 2)
//    {
//        tUInt16 scalar = input[i] << 8 & input[i + 1];
//        tUInt8 red;
//        tUInt8 green;
//
//        interpolateScalarToRedGreen(scalar, red, green);
//
//        outRaster.push_back(red);
//        outRaster.push_back(green);
//        outRaster.push_back(0);
//    }
//
//    return outRaster;
//}
//
//void cTofMotionCameraFilter::interpolateScalarToRedGreen(tUInt16 scalar, tUInt8& outRed, tUInt8& outGreen)
//{
//    if (scalar < UINT16_MAX / 2)
//    {
//        outRed = 255;
//        outGreen = static_cast<tUInt8>((static_cast<tFloat32>(scalar) / (static_cast<tFloat32>(UINT16_MAX) / 2.0f)) * 255.0f);
//    }
//    else
//    {
//        outGreen = 255;
//        outRed = static_cast<tUInt8>((static_cast<tFloat32>(scalar - (UINT16_MAX / 2)) / (static_cast<tFloat32>(UINT16_MAX) / 2.0f)) * 255.0f);
//    }
//}
