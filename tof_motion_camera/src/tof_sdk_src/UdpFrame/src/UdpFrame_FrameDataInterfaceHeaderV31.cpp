///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class FrameDataInterfaceHeaderV31 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Jun 17 08:43:13 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "UdpFrame_FrameDataInterfaceHeaderV31.h"
#include "Common_LogFormat.h"

#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8 // Windows 8.0
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>                            //inet_ functions
#endif


//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace UdpFrame;

//------------------------------ Constructor -------------------

FrameDataInterfaceHeaderV31::FrameDataInterfaceHeaderV31 ( ) 
: its0Reserved ( 65535 )
, its2HeaderVersion ( 3 )
, its4ImageWidth ( 91 )
, its6ImageHeight ( 92 )
, its8NofChannels ( 93 )
, its9BytesPerPixel ( 94 )
, its10ImageFormat ( 95 )
, its12Timestamp ( 96 )
, its16FrameCounter ( 97 )
, its18PreMetaData ( 98 )
, its19PostMetaData ( 99 )
, its20Reserved ( 0 )
, its24Reserved ( 0 )
, its26MainTemp ( 91 )
, its27LedTemp ( 92 )
, its28FirmwareVersion ( 93 )
, its30MagicV31 ( 13105 )
, its32IntegrationTime ( 95 )
, its34ModulationFreq ( 96 )
, its36Temp3 ( 97 )
, its37ColorMode ( 0 )
, its38ColorSensorWidth ( 0 )
, its40ColorSensorHeight ( 0 )
, its42Reserved ( 0 )
, its46Reserved ( 0 )
, its48RawPhaseContent ( 98 )
, its52Reserved ( 0 )
, its54Reserved ( 0 )
, its58Reserved ( 0 )
, its62Crc16 ( 99 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

FrameDataInterfaceHeaderV31::~FrameDataInterfaceHeaderV31 (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool FrameDataInterfaceHeaderV31::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Reserved != 65535) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp0Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Reserved        = htons(its0Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //2HeaderVersion  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its2HeaderVersion != 3) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp2HeaderVersion = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp2HeaderVersion        = htons(its2HeaderVersion);
     aByteOffset      += sizeof(uint2);
    }

    //4ImageWidth  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp4ImageWidth = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp4ImageWidth        = htons(its4ImageWidth);
     aByteOffset      += sizeof(uint2);
    }

    //6ImageHeight  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp6ImageHeight = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp6ImageHeight        = htons(its6ImageHeight);
     aByteOffset      += sizeof(uint2);
    }

    //8NofChannels  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp8NofChannels = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp8NofChannels        = its8NofChannels; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //9BytesPerPixel  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp9BytesPerPixel = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp9BytesPerPixel        = its9BytesPerPixel; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //10ImageFormat  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp10ImageFormat = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp10ImageFormat        = htons(its10ImageFormat);
     aByteOffset      += sizeof(uint2);
    }

    //12Timestamp  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmp12Timestamp = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp12Timestamp        = htonl(its12Timestamp);
     aByteOffset      += sizeof(uint4);
    }

    //16FrameCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp16FrameCounter = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp16FrameCounter        = htons(its16FrameCounter);
     aByteOffset      += sizeof(uint2);
    }

    //18PreMetaData  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp18PreMetaData = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp18PreMetaData        = its18PreMetaData; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //19PostMetaData  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp19PostMetaData = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp19PostMetaData        = its19PostMetaData; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its20Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp20Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp20Reserved        = htonl(its20Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //24Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its24Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp24Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp24Reserved        = htons(its24Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //26MainTemp  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp26MainTemp = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp26MainTemp        = its26MainTemp; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //27LedTemp  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp27LedTemp = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp27LedTemp        = its27LedTemp; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //28FirmwareVersion  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp28FirmwareVersion = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp28FirmwareVersion        = htons(its28FirmwareVersion);
     aByteOffset      += sizeof(uint2);
    }

    //30MagicV31  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its30MagicV31 != 13105) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp30MagicV31 = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp30MagicV31        = htons(its30MagicV31);
     aByteOffset      += sizeof(uint2);
    }

    //32IntegrationTime  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp32IntegrationTime = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp32IntegrationTime        = htons(its32IntegrationTime);
     aByteOffset      += sizeof(uint2);
    }

    //34ModulationFreq  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp34ModulationFreq = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp34ModulationFreq        = htons(its34ModulationFreq);
     aByteOffset      += sizeof(uint2);
    }

    //36Temp3  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     

     uint1 * pTmp36Temp3 = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp36Temp3        = its36Temp3; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //37ColorMode  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its37ColorMode != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp37ColorMode = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp37ColorMode        = its37ColorMode; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //38ColorSensorWidth  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its38ColorSensorWidth != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp38ColorSensorWidth = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp38ColorSensorWidth        = htons(its38ColorSensorWidth);
     aByteOffset      += sizeof(uint2);
    }

    //40ColorSensorHeight  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its40ColorSensorHeight != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp40ColorSensorHeight = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp40ColorSensorHeight        = htons(its40ColorSensorHeight);
     aByteOffset      += sizeof(uint2);
    }

    //42Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its42Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp42Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp42Reserved        = htonl(its42Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //46Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its46Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp46Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp46Reserved        = htons(its46Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //48RawPhaseContent  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmp48RawPhaseContent = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp48RawPhaseContent        = htonl(its48RawPhaseContent);
     aByteOffset      += sizeof(uint4);
    }

    //52Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its52Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp52Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp52Reserved        = htons(its52Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //54Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its54Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp54Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp54Reserved        = htonl(its54Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //58Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its58Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp58Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp58Reserved        = htonl(its58Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //62Crc16  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp62Crc16 = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp62Crc16        = htons(its62Crc16);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool FrameDataInterfaceHeaderV31::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Reserved = ntohs(*pTmp0Reserved);

     if (its0Reserved != 65535) return false; //init value; on false, do not update aByteOffset

     its0Reserved     = tmp0Reserved;
     aByteOffset += sizeof(uint2);
    }

    //2HeaderVersion  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp2HeaderVersion = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp2HeaderVersion = ntohs(*pTmp2HeaderVersion);

     if (its2HeaderVersion != 3) return false; //init value; on false, do not update aByteOffset

     its2HeaderVersion     = tmp2HeaderVersion;
     aByteOffset += sizeof(uint2);
    }

    //4ImageWidth  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp4ImageWidth = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp4ImageWidth = ntohs(*pTmp4ImageWidth);

     

     its4ImageWidth     = tmp4ImageWidth;
     aByteOffset += sizeof(uint2);
    }

    //6ImageHeight  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp6ImageHeight = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp6ImageHeight = ntohs(*pTmp6ImageHeight);

     

     its6ImageHeight     = tmp6ImageHeight;
     aByteOffset += sizeof(uint2);
    }

    //8NofChannels  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp8NofChannels = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp8NofChannels = *pTmp8NofChannels; //FIXME: no endianess checked

     

     its8NofChannels     = tmp8NofChannels;
     aByteOffset += sizeof(uint1);
    }

    //9BytesPerPixel  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp9BytesPerPixel = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp9BytesPerPixel = *pTmp9BytesPerPixel; //FIXME: no endianess checked

     

     its9BytesPerPixel     = tmp9BytesPerPixel;
     aByteOffset += sizeof(uint1);
    }

    //10ImageFormat  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp10ImageFormat = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp10ImageFormat = ntohs(*pTmp10ImageFormat);

     

     its10ImageFormat     = tmp10ImageFormat;
     aByteOffset += sizeof(uint2);
    }

    //12Timestamp  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp12Timestamp = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp12Timestamp = ntohl(*pTmp12Timestamp);

     

     its12Timestamp     = tmp12Timestamp;
     aByteOffset += sizeof(uint4);
    }

    //16FrameCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp16FrameCounter = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp16FrameCounter = ntohs(*pTmp16FrameCounter);

     

     its16FrameCounter     = tmp16FrameCounter;
     aByteOffset += sizeof(uint2);
    }

    //18PreMetaData  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp18PreMetaData = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp18PreMetaData = *pTmp18PreMetaData; //FIXME: no endianess checked

     

     its18PreMetaData     = tmp18PreMetaData;
     aByteOffset += sizeof(uint1);
    }

    //19PostMetaData  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp19PostMetaData = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp19PostMetaData = *pTmp19PostMetaData; //FIXME: no endianess checked

     

     its19PostMetaData     = tmp19PostMetaData;
     aByteOffset += sizeof(uint1);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp20Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp20Reserved = ntohl(*pTmp20Reserved);

     if (its20Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its20Reserved     = tmp20Reserved;
     aByteOffset += sizeof(uint4);
    }

    //24Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp24Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp24Reserved = ntohs(*pTmp24Reserved);

     if (its24Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its24Reserved     = tmp24Reserved;
     aByteOffset += sizeof(uint2);
    }

    //26MainTemp  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp26MainTemp = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp26MainTemp = *pTmp26MainTemp; //FIXME: no endianess checked

     

     its26MainTemp     = tmp26MainTemp;
     aByteOffset += sizeof(uint1);
    }

    //27LedTemp  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp27LedTemp = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp27LedTemp = *pTmp27LedTemp; //FIXME: no endianess checked

     

     its27LedTemp     = tmp27LedTemp;
     aByteOffset += sizeof(uint1);
    }

    //28FirmwareVersion  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp28FirmwareVersion = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp28FirmwareVersion = ntohs(*pTmp28FirmwareVersion);

     

     its28FirmwareVersion     = tmp28FirmwareVersion;
     aByteOffset += sizeof(uint2);
    }

    //30MagicV31  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp30MagicV31 = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp30MagicV31 = ntohs(*pTmp30MagicV31);

     if (its30MagicV31 != 13105) return false; //init value; on false, do not update aByteOffset

     its30MagicV31     = tmp30MagicV31;
     aByteOffset += sizeof(uint2);
    }

    //32IntegrationTime  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp32IntegrationTime = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp32IntegrationTime = ntohs(*pTmp32IntegrationTime);

     

     its32IntegrationTime     = tmp32IntegrationTime;
     aByteOffset += sizeof(uint2);
    }

    //34ModulationFreq  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp34ModulationFreq = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp34ModulationFreq = ntohs(*pTmp34ModulationFreq);

     

     its34ModulationFreq     = tmp34ModulationFreq;
     aByteOffset += sizeof(uint2);
    }

    //36Temp3  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp36Temp3 = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp36Temp3 = *pTmp36Temp3; //FIXME: no endianess checked

     

     its36Temp3     = tmp36Temp3;
     aByteOffset += sizeof(uint1);
    }

    //37ColorMode  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp37ColorMode = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp37ColorMode = *pTmp37ColorMode; //FIXME: no endianess checked

     if (its37ColorMode != 0) return false; //init value; on false, do not update aByteOffset

     its37ColorMode     = tmp37ColorMode;
     aByteOffset += sizeof(uint1);
    }

    //38ColorSensorWidth  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp38ColorSensorWidth = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp38ColorSensorWidth = ntohs(*pTmp38ColorSensorWidth);

     if (its38ColorSensorWidth != 0) return false; //init value; on false, do not update aByteOffset

     its38ColorSensorWidth     = tmp38ColorSensorWidth;
     aByteOffset += sizeof(uint2);
    }

    //40ColorSensorHeight  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp40ColorSensorHeight = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp40ColorSensorHeight = ntohs(*pTmp40ColorSensorHeight);

     if (its40ColorSensorHeight != 0) return false; //init value; on false, do not update aByteOffset

     its40ColorSensorHeight     = tmp40ColorSensorHeight;
     aByteOffset += sizeof(uint2);
    }

    //42Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp42Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp42Reserved = ntohl(*pTmp42Reserved);

     if (its42Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its42Reserved     = tmp42Reserved;
     aByteOffset += sizeof(uint4);
    }

    //46Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp46Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp46Reserved = ntohs(*pTmp46Reserved);

     if (its46Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its46Reserved     = tmp46Reserved;
     aByteOffset += sizeof(uint2);
    }

    //48RawPhaseContent  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp48RawPhaseContent = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp48RawPhaseContent = ntohl(*pTmp48RawPhaseContent);

     

     its48RawPhaseContent     = tmp48RawPhaseContent;
     aByteOffset += sizeof(uint4);
    }

    //52Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp52Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp52Reserved = ntohs(*pTmp52Reserved);

     if (its52Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its52Reserved     = tmp52Reserved;
     aByteOffset += sizeof(uint2);
    }

    //54Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp54Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp54Reserved = ntohl(*pTmp54Reserved);

     if (its54Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its54Reserved     = tmp54Reserved;
     aByteOffset += sizeof(uint4);
    }

    //58Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp58Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp58Reserved = ntohl(*pTmp58Reserved);

     if (its58Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its58Reserved     = tmp58Reserved;
     aByteOffset += sizeof(uint4);
    }

    //62Crc16  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp62Crc16 = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp62Crc16 = ntohs(*pTmp62Crc16);

     

     its62Crc16     = tmp62Crc16;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void FrameDataInterfaceHeaderV31::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void FrameDataInterfaceHeaderV31::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "UdpFrame_FrameDataInterfaceHeaderV31" );
    aLogFormat . LogElement( aStreamRef, "0Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its0Reserved );
    aLogFormat . LogElement( aStreamRef, "2HeaderVersion" );
    aLogFormat . LogDecValue( aStreamRef, its2HeaderVersion );
    aLogFormat . LogElement( aStreamRef, "4ImageWidth" );
    aLogFormat . LogDecValue( aStreamRef, its4ImageWidth );
    aLogFormat . LogElement( aStreamRef, "6ImageHeight" );
    aLogFormat . LogDecValue( aStreamRef, its6ImageHeight );
    aLogFormat . LogElement( aStreamRef, "8NofChannels" );
    aLogFormat . LogDecValue( aStreamRef, its8NofChannels );
    aLogFormat . LogElement( aStreamRef, "9BytesPerPixel" );
    aLogFormat . LogDecValue( aStreamRef, its9BytesPerPixel );
    aLogFormat . LogElement( aStreamRef, "10ImageFormat" );
    aLogFormat . LogDecValue( aStreamRef, its10ImageFormat );
    aLogFormat . LogElement( aStreamRef, "12Timestamp" );
    aLogFormat . LogDecValue( aStreamRef, its12Timestamp );
    aLogFormat . LogElement( aStreamRef, "16FrameCounter" );
    aLogFormat . LogDecValue( aStreamRef, its16FrameCounter );
    aLogFormat . LogElement( aStreamRef, "18PreMetaData" );
    aLogFormat . LogDecValue( aStreamRef, its18PreMetaData );
    aLogFormat . LogElement( aStreamRef, "19PostMetaData" );
    aLogFormat . LogDecValue( aStreamRef, its19PostMetaData );
    aLogFormat . LogElement( aStreamRef, "20Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its20Reserved );
    aLogFormat . LogElement( aStreamRef, "24Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its24Reserved );
    aLogFormat . LogElement( aStreamRef, "26MainTemp" );
    aLogFormat . LogDecValue( aStreamRef, its26MainTemp );
    aLogFormat . LogElement( aStreamRef, "27LedTemp" );
    aLogFormat . LogDecValue( aStreamRef, its27LedTemp );
    aLogFormat . LogElement( aStreamRef, "28FirmwareVersion" );
    aLogFormat . LogDecValue( aStreamRef, its28FirmwareVersion );
    aLogFormat . LogElement( aStreamRef, "30MagicV31" );
    aLogFormat . LogDecValue( aStreamRef, its30MagicV31 );
    aLogFormat . LogElement( aStreamRef, "32IntegrationTime" );
    aLogFormat . LogDecValue( aStreamRef, its32IntegrationTime );
    aLogFormat . LogElement( aStreamRef, "34ModulationFreq" );
    aLogFormat . LogDecValue( aStreamRef, its34ModulationFreq );
    aLogFormat . LogElement( aStreamRef, "36Temp3" );
    aLogFormat . LogDecValue( aStreamRef, its36Temp3 );
    aLogFormat . LogElement( aStreamRef, "37ColorMode" );
    aLogFormat . LogDecValue( aStreamRef, its37ColorMode );
    aLogFormat . LogElement( aStreamRef, "38ColorSensorWidth" );
    aLogFormat . LogDecValue( aStreamRef, its38ColorSensorWidth );
    aLogFormat . LogElement( aStreamRef, "40ColorSensorHeight" );
    aLogFormat . LogDecValue( aStreamRef, its40ColorSensorHeight );
    aLogFormat . LogElement( aStreamRef, "42Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its42Reserved );
    aLogFormat . LogElement( aStreamRef, "46Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its46Reserved );
    aLogFormat . LogElement( aStreamRef, "48RawPhaseContent" );
    aLogFormat . LogDecValue( aStreamRef, its48RawPhaseContent );
    aLogFormat . LogElement( aStreamRef, "52Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its52Reserved );
    aLogFormat . LogElement( aStreamRef, "54Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its54Reserved );
    aLogFormat . LogElement( aStreamRef, "58Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its58Reserved );
    aLogFormat . LogElement( aStreamRef, "62Crc16" );
    aLogFormat . LogDecValue( aStreamRef, its62Crc16 );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
