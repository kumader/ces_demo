///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Tx_MODE_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class Tx_MODE_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_Tx_MODE_Reg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

Tx_MODE_Reg::Tx_MODE_Reg ( ) 
: its0Addr ( 0x1018 )
, its0Reg ( 0x6e80 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

Tx_MODE_Reg::Tx_MODE_Reg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

Tx_MODE_Reg::~Tx_MODE_Reg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool Tx_MODE_Reg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

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

bool Tx_MODE_Reg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     

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
void Tx_MODE_Reg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void Tx_MODE_Reg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_Tx_MODE_Reg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "Tx_TRIGGER" );
    aLogFormat . LogDecValue( aStreamRef, its0Tx_TRIGGER );
    aLogFormat . LogElement( aStreamRef, "Tx_FSYNC" );
    aLogFormat . LogDecValue( aStreamRef, its2Tx_FSYNC );
    aLogFormat . LogElement( aStreamRef, "Tx_PIXCLK" );
    aLogFormat . LogDecValue( aStreamRef, its3Tx_PIXCLK );
    aLogFormat . LogElement( aStreamRef, "Tx_HSYNC" );
    aLogFormat . LogDecValue( aStreamRef, its4Tx_HSYNC );
    aLogFormat . LogElement( aStreamRef, "Tx_VSYNC" );
    aLogFormat . LogDecValue( aStreamRef, its5Tx_VSYNC );
    aLogFormat . LogElement( aStreamRef, "Tx_NDIV" );
    aLogFormat . LogDecValue( aStreamRef, its6Tx_NDIV );
    aLogFormat . LogElement( aStreamRef, "Tx_RDIV" );
    aLogFormat . LogDecValue( aStreamRef, its9Tx_RDIV );
    aLogFormat . LogElement( aStreamRef, "Tx_MOD_DUTY_CYCLE" );
    aLogFormat . LogDecValue( aStreamRef, its13Tx_MOD_DUTY_CYCLE );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
