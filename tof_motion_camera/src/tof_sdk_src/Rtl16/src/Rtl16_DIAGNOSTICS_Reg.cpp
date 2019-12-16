///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DIAGNOSTICS_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class DIAGNOSTICS_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_DIAGNOSTICS_Reg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

DIAGNOSTICS_Reg::DIAGNOSTICS_Reg ( ) 
: its0Addr ( 0x0ffd )
, its0Reg ( 0x0005 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

DIAGNOSTICS_Reg::DIAGNOSTICS_Reg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

DIAGNOSTICS_Reg::~DIAGNOSTICS_Reg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool DIAGNOSTICS_Reg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Addr != 0x0ffd) return false; //init value; on false, do not update aByteOffset

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

bool DIAGNOSTICS_Reg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     if (tmp0Addr != 0x0ffd) return false; //init value; on false, do not update aByteOffset

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
void DIAGNOSTICS_Reg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void DIAGNOSTICS_Reg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_DIAGNOSTICS_Reg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "PLL_LOCK" );
    aLogFormat . LogDecValue( aStreamRef, its0PLL_LOCK );
    aLogFormat . LogElement( aStreamRef, "DED_LATCH" );
    aLogFormat . LogDecValue( aStreamRef, its11DED_LATCH );
    aLogFormat . LogElement( aStreamRef, "SEC_LATCH" );
    aLogFormat . LogDecValue( aStreamRef, its12SEC_LATCH );
    aLogFormat . LogElement( aStreamRef, "DED_ERROR" );
    aLogFormat . LogDecValue( aStreamRef, its13DED_ERROR );
    aLogFormat . LogElement( aStreamRef, "SEC_ERROR" );
    aLogFormat . LogDecValue( aStreamRef, its14SEC_ERROR );
    aLogFormat . LogElement( aStreamRef, "ROI_ERROR" );
    aLogFormat . LogDecValue( aStreamRef, its15ROI_ERROR );
    aLogFormat . LogElement( aStreamRef, "V3_READY" );
    aLogFormat . LogDecValue( aStreamRef, its23V3_READY );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
