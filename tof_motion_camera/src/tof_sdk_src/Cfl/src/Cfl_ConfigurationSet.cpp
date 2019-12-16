///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class ConfigurationSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 20:54:53 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Cfl_ConfigurationSet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Cfl;

//------------------------------ Constructor -------------------

ConfigurationSet::ConfigurationSet ( ) 
: itsEnableDHCPFlag ( false )
, itsEnableUdpStreamingFlag ( true )
, itsGateway ( std::string("192.168.0.1") )
, itsIgnoreCrcForUdpStreamingFlag ( true )
, itsImageDataFormat ( 0 )
, itsIpAddress ( std::string("192.168.0.10") )
, itsIsInManualTrigger ( false )
, itsLensOpeningAngleIdentifier ( 60 )
, itsNetmask ( std::string("255.255.255.0") )
, itsTcpCtrlPort ( 10001 )
, itsUdpStreamAddress ( std::string("224.0.0.1") )
, itsUdpStreamPort ( 10002 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

ConfigurationSet::~ConfigurationSet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool ConfigurationSet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //EnableDHCPFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpEnableDHCPFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpEnableDHCPFlag        = itsEnableDHCPFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //EnableUdpStreamingFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpEnableUdpStreamingFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpEnableUdpStreamingFlag        = itsEnableUdpStreamingFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //Gateway  std::string c-string serialization
    {
     uint4 tmpLength = itsGateway . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsGateway . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //IgnoreCrcForUdpStreamingFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpIgnoreCrcForUdpStreamingFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpIgnoreCrcForUdpStreamingFlag        = itsIgnoreCrcForUdpStreamingFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //ImageDataFormat  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpImageDataFormat = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpImageDataFormat        = htons(itsImageDataFormat);
     aByteOffset      += sizeof(uint2);
    }

    //IpAddress  std::string c-string serialization
    {
     uint4 tmpLength = itsIpAddress . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsIpAddress . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //IsInManualTrigger  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpIsInManualTrigger = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpIsInManualTrigger        = itsIsInManualTrigger; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //LensOpeningAngleIdentifier  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpLensOpeningAngleIdentifier = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpLensOpeningAngleIdentifier        = htons(itsLensOpeningAngleIdentifier);
     aByteOffset      += sizeof(uint2);
    }

    //Netmask  std::string c-string serialization
    {
     uint4 tmpLength = itsNetmask . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsNetmask . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //TcpCtrlPort  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpTcpCtrlPort = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpTcpCtrlPort        = htons(itsTcpCtrlPort);
     aByteOffset      += sizeof(uint2);
    }

    //UdpStreamAddress  std::string c-string serialization
    {
     uint4 tmpLength = itsUdpStreamAddress . length();       //>=0 excl 0 terminator          
     uint4 tmpEnd    = aByteOffset + tmpLength;   //>=0  
     if (tmpEnd >= aBufferSize) return false;     //incl 0 terminator

     itsUdpStreamAddress . copy ( reinterpret_cast< char *> (buffer+aByteOffset), tmpLength );
     buffer[tmpEnd] = 0;  
     aByteOffset    = tmpEnd + 1; //one place after 0 terminator
    }

    //UdpStreamPort  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpUdpStreamPort = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpUdpStreamPort        = htons(itsUdpStreamPort);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool ConfigurationSet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //EnableDHCPFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpEnableDHCPFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpEnableDHCPFlag = *pTmpEnableDHCPFlag; //FIXME: no endianess checked

     

     itsEnableDHCPFlag     = tmpEnableDHCPFlag;
     aByteOffset += sizeof(bool);
    }

    //EnableUdpStreamingFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpEnableUdpStreamingFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpEnableUdpStreamingFlag = *pTmpEnableUdpStreamingFlag; //FIXME: no endianess checked

     

     itsEnableUdpStreamingFlag     = tmpEnableUdpStreamingFlag;
     aByteOffset += sizeof(bool);
    }

    //Gateway  std::string c-string serialization
    {
     itsGateway . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsGateway . length() + 1; //>=0 incl 0 terminator
    }

    //IgnoreCrcForUdpStreamingFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpIgnoreCrcForUdpStreamingFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpIgnoreCrcForUdpStreamingFlag = *pTmpIgnoreCrcForUdpStreamingFlag; //FIXME: no endianess checked

     

     itsIgnoreCrcForUdpStreamingFlag     = tmpIgnoreCrcForUdpStreamingFlag;
     aByteOffset += sizeof(bool);
    }

    //ImageDataFormat  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpImageDataFormat = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpImageDataFormat = ntohs(*pTmpImageDataFormat);

     

     itsImageDataFormat     = tmpImageDataFormat;
     aByteOffset += sizeof(uint2);
    }

    //IpAddress  std::string c-string serialization
    {
     itsIpAddress . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsIpAddress . length() + 1; //>=0 incl 0 terminator
    }

    //IsInManualTrigger  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpIsInManualTrigger = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpIsInManualTrigger = *pTmpIsInManualTrigger; //FIXME: no endianess checked

     

     itsIsInManualTrigger     = tmpIsInManualTrigger;
     aByteOffset += sizeof(bool);
    }

    //LensOpeningAngleIdentifier  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpLensOpeningAngleIdentifier = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpLensOpeningAngleIdentifier = ntohs(*pTmpLensOpeningAngleIdentifier);

     

     itsLensOpeningAngleIdentifier     = tmpLensOpeningAngleIdentifier;
     aByteOffset += sizeof(uint2);
    }

    //Netmask  std::string c-string serialization
    {
     itsNetmask . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsNetmask . length() + 1; //>=0 incl 0 terminator
    }

    //TcpCtrlPort  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpTcpCtrlPort = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpTcpCtrlPort = ntohs(*pTmpTcpCtrlPort);

     

     itsTcpCtrlPort     = tmpTcpCtrlPort;
     aByteOffset += sizeof(uint2);
    }

    //UdpStreamAddress  std::string c-string serialization
    {
     itsUdpStreamAddress . assign ( reinterpret_cast<const char *> (buffer+aByteOffset) );
     aByteOffset += itsUdpStreamAddress . length() + 1; //>=0 incl 0 terminator
    }

    //UdpStreamPort  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpUdpStreamPort = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpUdpStreamPort = ntohs(*pTmpUdpStreamPort);

     

     itsUdpStreamPort     = tmpUdpStreamPort;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void ConfigurationSet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void ConfigurationSet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_ConfigurationSet" );
    aLogFormat . LogElement( aStreamRef, "EnableDHCPFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsEnableDHCPFlag );
    aLogFormat . LogElement( aStreamRef, "EnableUdpStreamingFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsEnableUdpStreamingFlag );
    aLogFormat . LogElement( aStreamRef, "Gateway" );
    aLogFormat . LogDecValue( aStreamRef, itsGateway );
    aLogFormat . LogElement( aStreamRef, "IgnoreCrcForUdpStreamingFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsIgnoreCrcForUdpStreamingFlag );
    aLogFormat . LogElement( aStreamRef, "ImageDataFormat" );
    aLogFormat . LogDecValue( aStreamRef, ConfigurationSet::ConvertToStringImageDataFormat(itsImageDataFormat) );
    aLogFormat . LogElement( aStreamRef, "IpAddress" );
    aLogFormat . LogDecValue( aStreamRef, itsIpAddress );
    aLogFormat . LogElement( aStreamRef, "IsInManualTrigger" );
    aLogFormat . LogDecValue( aStreamRef, itsIsInManualTrigger );
    aLogFormat . LogElement( aStreamRef, "LensOpeningAngleIdentifier" );
    aLogFormat . LogDecValue( aStreamRef, itsLensOpeningAngleIdentifier );
    aLogFormat . LogElement( aStreamRef, "Netmask" );
    aLogFormat . LogDecValue( aStreamRef, itsNetmask );
    aLogFormat . LogElement( aStreamRef, "TcpCtrlPort" );
    aLogFormat . LogDecValue( aStreamRef, itsTcpCtrlPort );
    aLogFormat . LogElement( aStreamRef, "UdpStreamAddress" );
    aLogFormat . LogDecValue( aStreamRef, itsUdpStreamAddress );
    aLogFormat . LogElement( aStreamRef, "UdpStreamPort" );
    aLogFormat . LogDecValue( aStreamRef, itsUdpStreamPort );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
