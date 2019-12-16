///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2383 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class UdpDataInterfaceHeaderV1 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Apr 17 15:45:31 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "UdpFrame_UdpDataInterfaceHeaderV1.h"
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

UdpDataInterfaceHeaderV1::UdpDataInterfaceHeaderV1 ( ) 
: its0Version ( 1 )
, its2FrameCounter ( 91 )
, its4PacketCounter ( 92 )
, its6DataLength ( 93 )
, its8FrameSize ( 94 )
, its12PacketCrc32 ( 0 )
, its16Flags ( 1 )
, its20Reserved ( 0 )
, its24Reserved ( 0 )
, its28Reserved ( 0 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

UdpDataInterfaceHeaderV1::~UdpDataInterfaceHeaderV1 (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool UdpDataInterfaceHeaderV1::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Version  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Version != 1) return false; //on false, do not update aByteOffset

     uint2 * pTmp0Version = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Version        = htons(its0Version);
     aByteOffset      += sizeof(uint2);
    }

    //2FrameCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp2FrameCounter = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp2FrameCounter        = htons(its2FrameCounter);
     aByteOffset      += sizeof(uint2);
    }

    //4PacketCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp4PacketCounter = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp4PacketCounter        = htons(its4PacketCounter);
     aByteOffset      += sizeof(uint2);
    }

    //6DataLength  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp6DataLength = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp6DataLength        = htons(its6DataLength);
     aByteOffset      += sizeof(uint2);
    }

    //8FrameSize  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmp8FrameSize = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp8FrameSize        = htonl(its8FrameSize);
     aByteOffset      += sizeof(uint4);
    }

    //12PacketCrc32  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its12PacketCrc32 != 0) return false; //on false, do not update aByteOffset

     uint4 * pTmp12PacketCrc32 = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp12PacketCrc32        = htonl(its12PacketCrc32);
     aByteOffset      += sizeof(uint4);
    }

    //16Flags  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its16Flags != 1) return false; //on false, do not update aByteOffset

     uint4 * pTmp16Flags = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp16Flags        = htonl(its16Flags);
     aByteOffset      += sizeof(uint4);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its20Reserved != 0) return false; //on false, do not update aByteOffset

     uint4 * pTmp20Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp20Reserved        = htonl(its20Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //24Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its24Reserved != 0) return false; //on false, do not update aByteOffset

     uint4 * pTmp24Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp24Reserved        = htonl(its24Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //28Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its28Reserved != 0) return false; //on false, do not update aByteOffset

     uint4 * pTmp28Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp28Reserved        = htonl(its28Reserved);
     aByteOffset      += sizeof(uint4);
    }

   return true;
}

bool UdpDataInterfaceHeaderV1::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Version  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Version = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Version = ntohs(*pTmp0Version);

     if (tmp0Version != 1) return false; //on false, do not update its0Version

     its0Version     = tmp0Version;
     aByteOffset += sizeof(uint2);
    }

    //2FrameCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp2FrameCounter = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp2FrameCounter = ntohs(*pTmp2FrameCounter);

     

     its2FrameCounter     = tmp2FrameCounter;
     aByteOffset += sizeof(uint2);
    }

    //4PacketCounter  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp4PacketCounter = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp4PacketCounter = ntohs(*pTmp4PacketCounter);

     

     its4PacketCounter     = tmp4PacketCounter;
     aByteOffset += sizeof(uint2);
    }

    //6DataLength  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp6DataLength = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp6DataLength = ntohs(*pTmp6DataLength);

     

     its6DataLength     = tmp6DataLength;
     aByteOffset += sizeof(uint2);
    }

    //8FrameSize  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp8FrameSize = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp8FrameSize = ntohl(*pTmp8FrameSize);

     

     its8FrameSize     = tmp8FrameSize;
     aByteOffset += sizeof(uint4);
    }

    //12PacketCrc32  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp12PacketCrc32 = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp12PacketCrc32 = ntohl(*pTmp12PacketCrc32);

     if (tmp12PacketCrc32 != 0) return false; //on false, do not update its12PacketCrc32

     its12PacketCrc32     = tmp12PacketCrc32;
     aByteOffset += sizeof(uint4);
    }

    //16Flags  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp16Flags = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp16Flags = ntohl(*pTmp16Flags);

     if (tmp16Flags != 1) return false; //on false, do not update its16Flags

     its16Flags     = tmp16Flags;
     aByteOffset += sizeof(uint4);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp20Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp20Reserved = ntohl(*pTmp20Reserved);

     if (tmp20Reserved != 0) return false; //on false, do not update its20Reserved

     its20Reserved     = tmp20Reserved;
     aByteOffset += sizeof(uint4);
    }

    //24Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp24Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp24Reserved = ntohl(*pTmp24Reserved);

     if (tmp24Reserved != 0) return false; //on false, do not update its24Reserved

     its24Reserved     = tmp24Reserved;
     aByteOffset += sizeof(uint4);
    }

    //28Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp28Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp28Reserved = ntohl(*pTmp28Reserved);

     if (tmp28Reserved != 0) return false; //on false, do not update its28Reserved

     its28Reserved     = tmp28Reserved;
     aByteOffset += sizeof(uint4);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void UdpDataInterfaceHeaderV1::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void UdpDataInterfaceHeaderV1::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "UdpFrame_UdpDataInterfaceHeaderV1" );
    aLogFormat . LogElement( aStreamRef, "0Version" );
    aLogFormat . LogDecValue( aStreamRef, its0Version );
    aLogFormat . LogElement( aStreamRef, "2FrameCounter" );
    aLogFormat . LogDecValue( aStreamRef, its2FrameCounter );
    aLogFormat . LogElement( aStreamRef, "4PacketCounter" );
    aLogFormat . LogDecValue( aStreamRef, its4PacketCounter );
    aLogFormat . LogElement( aStreamRef, "6DataLength" );
    aLogFormat . LogDecValue( aStreamRef, its6DataLength );
    aLogFormat . LogElement( aStreamRef, "8FrameSize" );
    aLogFormat . LogDecValue( aStreamRef, its8FrameSize );
    aLogFormat . LogElement( aStreamRef, "12PacketCrc32" );
    aLogFormat . LogDecValue( aStreamRef, its12PacketCrc32 );
    aLogFormat . LogElement( aStreamRef, "16Flags" );
    aLogFormat . LogDecValue( aStreamRef, its16Flags );
    aLogFormat . LogElement( aStreamRef, "20Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its20Reserved );
    aLogFormat . LogElement( aStreamRef, "24Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its24Reserved );
    aLogFormat . LogElement( aStreamRef, "28Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its28Reserved );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
