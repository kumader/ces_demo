///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Status2Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class Status2Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_Status2Reg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

Status2Reg::Status2Reg ( ) 
: its0Addr ( 0xfe )
, its0Reg ( 0 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

Status2Reg::Status2Reg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

Status2Reg::~Status2Reg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool Status2Reg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Addr != 0xfe) return false; //init value; on false, do not update aByteOffset

     uint2 * pTmp0Addr = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Addr        = htons(its0Addr);
     aByteOffset      += sizeof(uint2);
    }

    //0Reg  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmp0Reg = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmp0Reg        = htons(its0Reg);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool Status2Reg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     if (tmp0Addr != 0xfe) return false; //init value; on false, do not update aByteOffset

     its0Addr     = tmp0Addr;
     aByteOffset += sizeof(uint2);
    }

    //0Reg  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Reg = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Reg = ntohs(*pTmp0Reg);

     

     its0Reg     = tmp0Reg;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void Status2Reg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void Status2Reg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_Status2Reg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "SerdesError" );
    aLogFormat . LogDecValue( aStreamRef, its0SerdesError );
    aLogFormat . LogElement( aStreamRef, "CaptureError" );
    aLogFormat . LogDecValue( aStreamRef, its1CaptureError );
    aLogFormat . LogElement( aStreamRef, "CaptureTimeout" );
    aLogFormat . LogDecValue( aStreamRef, its2CaptureTimeout );
    aLogFormat . LogElement( aStreamRef, "ApplicationProcessorTooHot" );
    aLogFormat . LogDecValue( aStreamRef, its3ApplicationProcessorTooHot );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
