///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FileController
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class FileController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Oct  8 11:31:17 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Pgm_FileController.h"
#include "Common_LogFormat.h"


#include <limits>    //uint2 limit
#include <fstream>   //ofstream
#include <sstream>   //stringstream


//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Pgm;

//------------------------------ Constructor -------------------

FileController::FileController ( ) 
: itsNrReads ( 0 )
, itsNrWrites ( 0 )

{
  /// nothing
}

//------------------------------ Special Constructor -------------------

FileController::FileController( const std::string & aName
			      , const Common::UseLogger::LogLevel_e & aLogLevel 
			      )
: UseLogger (
 0
, aLogLevel
, aName
)
, itsNrReads ( 0 )
, itsNrWrites ( 0 )
{
  ///nothing
}

//------------------------------ Destructor ----------------------------

FileController::~FileController (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool FileController::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //NrReads  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpNrReads = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpNrReads        = htonl(itsNrReads);
     aByteOffset      += sizeof(uint4);
    }

    //NrWrites  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpNrWrites = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpNrWrites        = htonl(itsNrWrites);
     aByteOffset      += sizeof(uint4);
    }

   return true;
}

bool FileController::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //NrReads  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpNrReads = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpNrReads = ntohl(*pTmpNrReads);

     

     itsNrReads     = tmpNrReads;
     aByteOffset += sizeof(uint4);
    }

    //NrWrites  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpNrWrites = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpNrWrites = ntohl(*pTmpNrWrites);

     

     itsNrWrites     = tmpNrWrites;
     aByteOffset += sizeof(uint4);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void FileController::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void FileController::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Pgm_FileController" );
    aLogFormat . LogElement( aStreamRef, "NrReads" );
    aLogFormat . LogDecValue( aStreamRef, itsNrReads );
    aLogFormat . LogElement( aStreamRef, "NrWrites" );
    aLogFormat . LogDecValue( aStreamRef, itsNrWrites );

   aLogFormat . LogEndStruct( aStreamRef );
}


//--------------------------------------------------------------------------------------------------------------------
//function: WritePgm
//description: writes a PGM file from a uint2 MatIdx 
//XRes: number of columns
//YRes: number of rows
//aFileName: name of the PGM file
//aMatIdx: Idx to a previously allocated memory
//aFrameCounter: uint2 counting number
//aFrameTimeStamp: uint4 counting number
//logger: used for logging macros

bool FileController::WritePgm( const uint4& aXRes
             , const uint4 & aYRes
             , const std::string & aFileName
             , const Mat2D::MatIdx<uint2> & aMatIdx 
             , const uint2 & aFrameCounter
             , const uint4 & aFrameTimeStamp
             , const bool & aUseScalingFactor)   

{

  LOG_ASSERT(aXRes > 0,"WritePgm: aXRes must be > 0");
  LOG_ASSERT(aYRes > 0,"WritePgm: aYRes must be > 0");
  LOG_ASSERT(aFileName != "","WritePgm: aFileName must be != \"\"");

  uint4 sum = 0;
  uint4 min = UINT4_MAX; 
  uint4 max = UINT4_MIN; 

    for (uint2 y = 0; y < aYRes; ++y) {
	for (uint2 x = 0; x < aXRes; ++x) {

	    uint2 tmpValue =  aMatIdx(x,y);
	    //avg
	    sum += tmpValue;
	    //max
	    if (tmpValue > max) max = tmpValue;
	    //min
	    if (tmpValue < min) min = tmpValue;
  
	} //for
    } //for

  INFOLOG()<<"The average is " <<  sum / aXRes /aYRes <<std::endl;
  INFOLOG()<<"The max is " << max<<std::endl;
  INFOLOG()<<"The min is " << min<<std::endl;

  //scale to uint2
  uint2 tmpScalingFactor = 1;

  if (aUseScalingFactor && max) { tmpScalingFactor = static_cast<uint2>(UINT2_MAX / max); }    //PROTECTED

  INFOLOG()<<"The scaling factor is "<<tmpScalingFactor<<std::endl;

  std::ofstream fFile;
  fFile.open(aFileName.c_str(), std::ios::binary);

  //PGM file format

  fFile << "P5"<<std::endl;
  fFile << "#"<<aFileName<<std::endl;
  fFile << "#date: "<<Common::Logger().DateTimestamp()<<std::endl;
  fFile << "#framecounter: "<<aFrameCounter<<std::endl;
  fFile << "#frametimestamp: "<<aFrameTimeStamp<<std::endl;
  fFile << "#max: "<<max<<std::endl;
  fFile << "#min: "<<min<<std::endl;
  fFile << "#uint16_t scale factor: "<<tmpScalingFactor<<std::endl;
  fFile << aXRes<<" "<<aYRes<<std::endl;
  fFile << UINT2_MAX <<std::endl;

    for (uint2 y = 0; y < aYRes; ++y) {
	for (uint2 x = 0; x < aXRes; ++x) {

	    uint2 tmpValue = aMatIdx(x,y);

            tmpValue *= tmpScalingFactor; 

            char tmpMSB = ( ( ( tmpValue ) & 0xff00 ) >> 8 );
            char tmpLSB = ( ( tmpValue ) & 0xff ); 

            fFile.write(&tmpMSB,1);
            fFile.write(&tmpLSB,1);

	} //for
    } //for
 fFile << std::endl; //not sure if needed
//close File
 fFile.close();

 return true;
}

//--------------------------------------------------------------------------------------------------------------------
//function: ReadPgm
//description: reads a PGM file and copies data into frame buffer
//XRes: number of columns
//YRes: number of rows
//aFileName: name of the PGM file
//aBufferPtr: Ptr to a previously allocated memory
//aBufferSize: size of previously allocated memory
//logger: used for logging macros

#define PGM_IDXL(b,c) \
0+(b)*2+(c)*aXRes*2

#define PGM_IDXH(b,c) \
1+(b)*2+(c)*aXRes*2

bool FileController::ReadPgm(const uint4& aXRes, const uint4 & aYRes, const std::string & aFileName, uint1 * aBufferPtr, const uint4 & aBufferSize)   
{
  
  LOG_ASSERT(aXRes > 0,"ReadPgm: aXRes must be > 0");
  LOG_ASSERT(aYRes > 0,"ReadPgm: aYRes must be > 0");
  LOG_ASSERT(aFileName != "","ReadPgm: aFileName must be != \"\"");
  LOG_ASSERT(aBufferPtr,"ReadPgm: aBufferPtr must be != 0");

  std::ifstream fFile;
  fFile.open(aFileName.c_str(), std::ios::binary);

  DEBUGLOG()<<"read file "<< aFileName << std::endl;
  LOG_ASSERT(fFile.is_open() , "ReadPgm: could not open " + aFileName);

  //PGM file format
  std::string tmpLine;
  LOG_ASSERT(getline(fFile, tmpLine) , "getline failed1"); LOG_ASSERT(tmpLine.find("P5") != std::string::npos , "ReadPgm: P5 marker not found");

  std::stringstream tmpss;
  tmpss << aXRes << " " << aYRes;

  //read text lines
  while (getline(fFile, tmpLine)) {
  if (tmpLine[0] == '#') continue;
  if (tmpLine.find(tmpss.str()) != std::string::npos) continue;         
  if (tmpLine.find("65535") != std::string::npos) break;

  LOG_ASSERT(false, "ReadPgm: invalid PGM file format");
  };//while

  //read binary data
    for (uint2 y = 0; y < aYRes; ++y) {
	for (uint2 x = 0; x < aXRes; ++x) {

            char tmpMSB;
            char tmpLSB;

            fFile.read(&tmpMSB,1);
            fFile.read(&tmpLSB,1);

            LOG_ASSERT( (PGM_IDXH(x,y) < aBufferSize), "ReadPgm: Buffer too small");
            
	    aBufferPtr[ PGM_IDXL(x,y) ] = tmpLSB & 0xff;        
	    aBufferPtr[ PGM_IDXH(x,y) ] = tmpMSB & 0xff;

	} //for
    } //for

//close File
 fFile.close();

 return true;
}

//End of File
