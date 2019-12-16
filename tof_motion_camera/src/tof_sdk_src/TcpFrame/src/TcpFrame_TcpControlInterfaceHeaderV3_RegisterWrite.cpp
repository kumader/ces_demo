///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- TcpControlInterfaceHeaderV3_RegisterWrite
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class TcpControlInterfaceHeaderV3_RegisterWrite 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Feb  9 17:10:55 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "TcpFrame_TcpControlInterfaceHeaderV3_RegisterWrite.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace TcpFrame;

//------------------------------ Constructor -------------------

TcpControlInterfaceHeaderV3_RegisterWrite::TcpControlInterfaceHeaderV3_RegisterWrite ( ) 
: its0Preamble ( 41452 )
, its2ProtocolVersion ( 3 )
, its3Command ( 4 )
, its4SubCommand ( 0 )
, its5Status ( 0 )
, its6Flags ( 1 )
, its8Length ( 2 )
, its12RegisterAddress ( 92 )
, its14HeaderData2 ( 0 )
, its15HeaderData3 ( 0 )
, its16CallbackIpVersion ( 0 )
, its17Reserved ( 0 )
, its18Reserved ( 0 )
, its20Reserved ( 0 )
, its24Reserved ( 0 )
, its28Reserved ( 0 )
, its32Reserved ( 0 )
, its36Reserved ( 0 )
, its40Reserved ( 0 )
, its44Reserved ( 0 )
, its48Reserved ( 0 )
, its52Reserved ( 0 )
, its56Reserved ( 0 )
, its58DataCrc32 ( 0 )
, its62HeaderCrc16 ( 93 )
, its64RegisterValue ( 94 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

TcpControlInterfaceHeaderV3_RegisterWrite::~TcpControlInterfaceHeaderV3_RegisterWrite (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool TcpControlInterfaceHeaderV3_RegisterWrite::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Preamble  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Preamble != 41452) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp0Preamble = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Preamble        = htons(its0Preamble);
     aByteOffset      += sizeof(uint2);
    }

    //2ProtocolVersion  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its2ProtocolVersion != 3) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp2ProtocolVersion = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp2ProtocolVersion        = its2ProtocolVersion; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //3Command  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its3Command != 4) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp3Command = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp3Command        = its3Command; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //4SubCommand  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its4SubCommand != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp4SubCommand = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp4SubCommand        = its4SubCommand; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //5Status  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its5Status != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp5Status = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp5Status        = its5Status; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //6Flags  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its6Flags != 1) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp6Flags = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp6Flags        = htons(its6Flags);
     aByteOffset      += sizeof(uint2);
    }

    //8Length  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its8Length != 2) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp8Length = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp8Length        = htonl(its8Length);
     aByteOffset      += sizeof(uint4);
    }

    //12RegisterAddress  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp12RegisterAddress = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp12RegisterAddress        = htons(its12RegisterAddress);
     aByteOffset      += sizeof(uint2);
    }

    //14HeaderData2  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its14HeaderData2 != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp14HeaderData2 = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp14HeaderData2        = its14HeaderData2; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //15HeaderData3  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its15HeaderData3 != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp15HeaderData3 = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp15HeaderData3        = its15HeaderData3; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //16CallbackIpVersion  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its16CallbackIpVersion == 0 || 
      its16CallbackIpVersion == 4); else { return false; } //array; on false, do not update aByteOffset

     uint1 * pTmp16CallbackIpVersion = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp16CallbackIpVersion        = its16CallbackIpVersion; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //17Reserved  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;
     if (its17Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint1 * pTmp17Reserved = reinterpret_cast< uint1 * > ( buffer + aByteOffset );
     *pTmp17Reserved        = its17Reserved; //FIXME: no endianess checked here
     aByteOffset      += sizeof(uint1);
    }

    //18Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its18Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp18Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp18Reserved        = htons(its18Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its20Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp20Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp20Reserved        = htonl(its20Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //24Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its24Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp24Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp24Reserved        = htonl(its24Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //28Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its28Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp28Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp28Reserved        = htonl(its28Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //32Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its32Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp32Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp32Reserved        = htonl(its32Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //36Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its36Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp36Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp36Reserved        = htonl(its36Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //40Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its40Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp40Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp40Reserved        = htonl(its40Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //44Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its44Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp44Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp44Reserved        = htonl(its44Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //48Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its48Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp48Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp48Reserved        = htonl(its48Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //52Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its52Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp52Reserved = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp52Reserved        = htonl(its52Reserved);
     aByteOffset      += sizeof(uint4);
    }

    //56Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its56Reserved != 0) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp56Reserved = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp56Reserved        = htons(its56Reserved);
     aByteOffset      += sizeof(uint2);
    }

    //58DataCrc32  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     if (its58DataCrc32 != 0) return false; //init value; on false, do not update aByteOffset

     uint4 * pTmp58DataCrc32 = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmp58DataCrc32        = htonl(its58DataCrc32);
     aByteOffset      += sizeof(uint4);
    }

    //62HeaderCrc16  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp62HeaderCrc16 = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp62HeaderCrc16        = htons(its62HeaderCrc16);
     aByteOffset      += sizeof(uint2);
    }

    //64RegisterValue  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp64RegisterValue = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp64RegisterValue        = htons(its64RegisterValue);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool TcpControlInterfaceHeaderV3_RegisterWrite::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Preamble  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Preamble = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Preamble = ntohs(*pTmp0Preamble);

     if (tmp0Preamble != 41452) return false; //init value; on false, do not update aByteOffset

     its0Preamble     = tmp0Preamble;
     aByteOffset += sizeof(uint2);
    }

    //2ProtocolVersion  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp2ProtocolVersion = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp2ProtocolVersion = *pTmp2ProtocolVersion; //FIXME: no endianess checked

     if (tmp2ProtocolVersion != 3) return false; //init value; on false, do not update aByteOffset

     its2ProtocolVersion     = tmp2ProtocolVersion;
     aByteOffset += sizeof(uint1);
    }

    //3Command  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp3Command = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp3Command = *pTmp3Command; //FIXME: no endianess checked

     if (tmp3Command != 4) return false; //init value; on false, do not update aByteOffset

     its3Command     = tmp3Command;
     aByteOffset += sizeof(uint1);
    }

    //4SubCommand  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp4SubCommand = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp4SubCommand = *pTmp4SubCommand; //FIXME: no endianess checked

     if (tmp4SubCommand != 0) return false; //init value; on false, do not update aByteOffset

     its4SubCommand     = tmp4SubCommand;
     aByteOffset += sizeof(uint1);
    }

    //5Status  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp5Status = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp5Status = *pTmp5Status; //FIXME: no endianess checked

     if (tmp5Status != 0) return false; //init value; on false, do not update aByteOffset

     its5Status     = tmp5Status;
     aByteOffset += sizeof(uint1);
    }

    //6Flags  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp6Flags = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp6Flags = ntohs(*pTmp6Flags);

     if (tmp6Flags != 1) return false; //init value; on false, do not update aByteOffset

     its6Flags     = tmp6Flags;
     aByteOffset += sizeof(uint2);
    }

    //8Length  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp8Length = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp8Length = ntohl(*pTmp8Length);

     if (tmp8Length != 2) return false; //init value; on false, do not update aByteOffset

     its8Length     = tmp8Length;
     aByteOffset += sizeof(uint4);
    }

    //12RegisterAddress  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp12RegisterAddress = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp12RegisterAddress = ntohs(*pTmp12RegisterAddress);

     

     its12RegisterAddress     = tmp12RegisterAddress;
     aByteOffset += sizeof(uint2);
    }

    //14HeaderData2  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp14HeaderData2 = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp14HeaderData2 = *pTmp14HeaderData2; //FIXME: no endianess checked

     if (tmp14HeaderData2 != 0) return false; //init value; on false, do not update aByteOffset

     its14HeaderData2     = tmp14HeaderData2;
     aByteOffset += sizeof(uint1);
    }

    //15HeaderData3  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp15HeaderData3 = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp15HeaderData3 = *pTmp15HeaderData3; //FIXME: no endianess checked

     if (tmp15HeaderData3 != 0) return false; //init value; on false, do not update aByteOffset

     its15HeaderData3     = tmp15HeaderData3;
     aByteOffset += sizeof(uint1);
    }

    //16CallbackIpVersion  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp16CallbackIpVersion = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp16CallbackIpVersion = *pTmp16CallbackIpVersion; //FIXME: no endianess checked

     if (tmp16CallbackIpVersion == 0 || 
      tmp16CallbackIpVersion == 4); else { return false; } //array; on false, do not update aByteOffset

     its16CallbackIpVersion     = tmp16CallbackIpVersion;
     aByteOffset += sizeof(uint1);
    }

    //17Reserved  uint1 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint1) > aBufferSize ) return false;

     const uint1 * pTmp17Reserved = reinterpret_cast< const uint1 * > ( buffer + aByteOffset );
     uint1 tmp17Reserved = *pTmp17Reserved; //FIXME: no endianess checked

     if (tmp17Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its17Reserved     = tmp17Reserved;
     aByteOffset += sizeof(uint1);
    }

    //18Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp18Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp18Reserved = ntohs(*pTmp18Reserved);

     if (tmp18Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its18Reserved     = tmp18Reserved;
     aByteOffset += sizeof(uint2);
    }

    //20Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp20Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp20Reserved = ntohl(*pTmp20Reserved);

     if (tmp20Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its20Reserved     = tmp20Reserved;
     aByteOffset += sizeof(uint4);
    }

    //24Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp24Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp24Reserved = ntohl(*pTmp24Reserved);

     if (tmp24Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its24Reserved     = tmp24Reserved;
     aByteOffset += sizeof(uint4);
    }

    //28Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp28Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp28Reserved = ntohl(*pTmp28Reserved);

     if (tmp28Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its28Reserved     = tmp28Reserved;
     aByteOffset += sizeof(uint4);
    }

    //32Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp32Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp32Reserved = ntohl(*pTmp32Reserved);

     if (tmp32Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its32Reserved     = tmp32Reserved;
     aByteOffset += sizeof(uint4);
    }

    //36Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp36Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp36Reserved = ntohl(*pTmp36Reserved);

     if (tmp36Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its36Reserved     = tmp36Reserved;
     aByteOffset += sizeof(uint4);
    }

    //40Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp40Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp40Reserved = ntohl(*pTmp40Reserved);

     if (tmp40Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its40Reserved     = tmp40Reserved;
     aByteOffset += sizeof(uint4);
    }

    //44Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp44Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp44Reserved = ntohl(*pTmp44Reserved);

     if (tmp44Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its44Reserved     = tmp44Reserved;
     aByteOffset += sizeof(uint4);
    }

    //48Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp48Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp48Reserved = ntohl(*pTmp48Reserved);

     if (tmp48Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its48Reserved     = tmp48Reserved;
     aByteOffset += sizeof(uint4);
    }

    //52Reserved  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp52Reserved = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp52Reserved = ntohl(*pTmp52Reserved);

     if (tmp52Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its52Reserved     = tmp52Reserved;
     aByteOffset += sizeof(uint4);
    }

    //56Reserved  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp56Reserved = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp56Reserved = ntohs(*pTmp56Reserved);

     if (tmp56Reserved != 0) return false; //init value; on false, do not update aByteOffset

     its56Reserved     = tmp56Reserved;
     aByteOffset += sizeof(uint2);
    }

    //58DataCrc32  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmp58DataCrc32 = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmp58DataCrc32 = ntohl(*pTmp58DataCrc32);

     if (tmp58DataCrc32 != 0) return false; //init value; on false, do not update aByteOffset

     its58DataCrc32     = tmp58DataCrc32;
     aByteOffset += sizeof(uint4);
    }

    //62HeaderCrc16  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp62HeaderCrc16 = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp62HeaderCrc16 = ntohs(*pTmp62HeaderCrc16);

     

     its62HeaderCrc16     = tmp62HeaderCrc16;
     aByteOffset += sizeof(uint2);
    }

    //64RegisterValue  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp64RegisterValue = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp64RegisterValue = ntohs(*pTmp64RegisterValue);

     

     its64RegisterValue     = tmp64RegisterValue;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void TcpControlInterfaceHeaderV3_RegisterWrite::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void TcpControlInterfaceHeaderV3_RegisterWrite::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "TcpFrame_TcpControlInterfaceHeaderV3_RegisterWrite" );
    aLogFormat . LogElement( aStreamRef, "0Preamble" );
    aLogFormat . LogDecValue( aStreamRef, its0Preamble );
    aLogFormat . LogElement( aStreamRef, "2ProtocolVersion" );
    aLogFormat . LogDecValue( aStreamRef, its2ProtocolVersion );
    aLogFormat . LogElement( aStreamRef, "3Command" );
    aLogFormat . LogDecValue( aStreamRef, its3Command );
    aLogFormat . LogElement( aStreamRef, "4SubCommand" );
    aLogFormat . LogDecValue( aStreamRef, its4SubCommand );
    aLogFormat . LogElement( aStreamRef, "5Status" );
    aLogFormat . LogDecValue( aStreamRef, its5Status );
    aLogFormat . LogElement( aStreamRef, "6Flags" );
    aLogFormat . LogDecValue( aStreamRef, its6Flags );
    aLogFormat . LogElement( aStreamRef, "8Length" );
    aLogFormat . LogDecValue( aStreamRef, its8Length );
    aLogFormat . LogElement( aStreamRef, "12RegisterAddress" );
    aLogFormat . LogDecValue( aStreamRef, its12RegisterAddress );
    aLogFormat . LogElement( aStreamRef, "14HeaderData2" );
    aLogFormat . LogDecValue( aStreamRef, its14HeaderData2 );
    aLogFormat . LogElement( aStreamRef, "15HeaderData3" );
    aLogFormat . LogDecValue( aStreamRef, its15HeaderData3 );
    aLogFormat . LogElement( aStreamRef, "16CallbackIpVersion" );
    aLogFormat . LogDecValue( aStreamRef, its16CallbackIpVersion );
    aLogFormat . LogElement( aStreamRef, "17Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its17Reserved );
    aLogFormat . LogElement( aStreamRef, "18Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its18Reserved );
    aLogFormat . LogElement( aStreamRef, "20Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its20Reserved );
    aLogFormat . LogElement( aStreamRef, "24Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its24Reserved );
    aLogFormat . LogElement( aStreamRef, "28Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its28Reserved );
    aLogFormat . LogElement( aStreamRef, "32Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its32Reserved );
    aLogFormat . LogElement( aStreamRef, "36Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its36Reserved );
    aLogFormat . LogElement( aStreamRef, "40Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its40Reserved );
    aLogFormat . LogElement( aStreamRef, "44Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its44Reserved );
    aLogFormat . LogElement( aStreamRef, "48Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its48Reserved );
    aLogFormat . LogElement( aStreamRef, "52Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its52Reserved );
    aLogFormat . LogElement( aStreamRef, "56Reserved" );
    aLogFormat . LogDecValue( aStreamRef, its56Reserved );
    aLogFormat . LogElement( aStreamRef, "58DataCrc32" );
    aLogFormat . LogDecValue( aStreamRef, its58DataCrc32 );
    aLogFormat . LogElement( aStreamRef, "62HeaderCrc16" );
    aLogFormat . LogDecValue( aStreamRef, its62HeaderCrc16 );
    aLogFormat . LogElement( aStreamRef, "64RegisterValue" );
    aLogFormat . LogDecValue( aStreamRef, its64RegisterValue );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
