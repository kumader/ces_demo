///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- FactorySet
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class FactorySet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Sep  2 10:14:10 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Cfl_FactorySet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Cfl;

//------------------------------ Constructor -------------------

FactorySet::FactorySet ( ) 
: itsFactoryBuildInfo ( std::string("2017-01-01-00:00(00)") )
, itsFactoryMacAddress ( std::string("00:00:00:00:00:00") )
, itsFirmwareBuildInfo ( std::string("2017-01-01-00:00:00") )
, itsFirmwareLoadCounter ( 0 )
, itsFirmwareRevisionInfo ( std::string("0.0.0") )
, itsHardwareSpecificIdentification ( 0x0 )
, itsSerialNumber ( 0 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

FactorySet::~FactorySet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool FactorySet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //FactoryBuildInfo  std::string c-string serialization
    {
     uint4 tmpLength = itsFactoryBuildInfo . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsFactoryBuildInfo . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //FactoryMacAddress  std::string c-string serialization
    {
     uint4 tmpLength = itsFactoryMacAddress . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsFactoryMacAddress . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //FirmwareBuildInfo  std::string c-string serialization
    {
     uint4 tmpLength = itsFirmwareBuildInfo . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsFirmwareBuildInfo . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //FirmwareLoadCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpFirmwareLoadCounter = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpFirmwareLoadCounter        = htons(itsFirmwareLoadCounter);
     aByteOffset      += sizeof(uint2);
    }

    //FirmwareRevisionInfo  std::string c-string serialization
    {
     uint4 tmpLength = itsFirmwareRevisionInfo . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsFirmwareRevisionInfo . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //HardwareSpecificIdentification  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpHardwareSpecificIdentification = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpHardwareSpecificIdentification        = htons(itsHardwareSpecificIdentification);
     aByteOffset      += sizeof(uint2);
    }

    //SerialNumber  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpSerialNumber = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpSerialNumber        = htonl(itsSerialNumber);
     aByteOffset      += sizeof(uint4);
    }

   return true;
}

bool FactorySet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //FactoryBuildInfo  std::string c-string serialization
    {
     itsFactoryBuildInfo . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsFactoryBuildInfo . length() + 1; //>=0 incl 0 terminator
    }

    //FactoryMacAddress  std::string c-string serialization
    {
     itsFactoryMacAddress . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsFactoryMacAddress . length() + 1; //>=0 incl 0 terminator
    }

    //FirmwareBuildInfo  std::string c-string serialization
    {
     itsFirmwareBuildInfo . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsFirmwareBuildInfo . length() + 1; //>=0 incl 0 terminator
    }

    //FirmwareLoadCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpFirmwareLoadCounter = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpFirmwareLoadCounter = ntohs(*pTmpFirmwareLoadCounter);

     

     itsFirmwareLoadCounter     = tmpFirmwareLoadCounter;
     aByteOffset += sizeof(uint2);
    }

    //FirmwareRevisionInfo  std::string c-string serialization
    {
     itsFirmwareRevisionInfo . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsFirmwareRevisionInfo . length() + 1; //>=0 incl 0 terminator
    }

    //HardwareSpecificIdentification  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpHardwareSpecificIdentification = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpHardwareSpecificIdentification = ntohs(*pTmpHardwareSpecificIdentification);

     

     itsHardwareSpecificIdentification     = tmpHardwareSpecificIdentification;
     aByteOffset += sizeof(uint2);
    }

    //SerialNumber  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpSerialNumber = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpSerialNumber = ntohl(*pTmpSerialNumber);

     

     itsSerialNumber     = tmpSerialNumber;
     aByteOffset += sizeof(uint4);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void FactorySet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void FactorySet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_FactorySet" );
    aLogFormat . LogElement( aStreamRef, "FactoryBuildInfo" );
    aLogFormat . LogDecValue( aStreamRef, itsFactoryBuildInfo );
    aLogFormat . LogElement( aStreamRef, "FactoryMacAddress" );
    aLogFormat . LogDecValue( aStreamRef, itsFactoryMacAddress );
    aLogFormat . LogElement( aStreamRef, "FirmwareBuildInfo" );
    aLogFormat . LogDecValue( aStreamRef, itsFirmwareBuildInfo );
    aLogFormat . LogElement( aStreamRef, "FirmwareLoadCounter" );
    aLogFormat . LogDecValue( aStreamRef, itsFirmwareLoadCounter );
    aLogFormat . LogElement( aStreamRef, "FirmwareRevisionInfo" );
    aLogFormat . LogDecValue( aStreamRef, itsFirmwareRevisionInfo );
    aLogFormat . LogElement( aStreamRef, "HardwareSpecificIdentification" );
    aLogFormat . LogHexValue( aStreamRef, itsHardwareSpecificIdentification );
    aLogFormat . LogElement( aStreamRef, "SerialNumber" );
    aLogFormat . LogDecValue( aStreamRef, itsSerialNumber );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
