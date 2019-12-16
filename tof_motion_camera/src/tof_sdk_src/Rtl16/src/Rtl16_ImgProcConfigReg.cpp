///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ImgProcConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class ImgProcConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_ImgProcConfigReg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

ImgProcConfigReg::ImgProcConfigReg ( ) 
: its0Addr ( 0x1e0 )
, its0Reg ( 0x28c0 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

ImgProcConfigReg::ImgProcConfigReg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

ImgProcConfigReg::~ImgProcConfigReg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool ImgProcConfigReg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Addr != 0x1e0) return false; //init value; on false, do not update aByteOffset

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

bool ImgProcConfigReg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     if (tmp0Addr != 0x1e0) return false; //init value; on false, do not update aByteOffset

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
void ImgProcConfigReg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void ImgProcConfigReg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_ImgProcConfigReg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "EnableMedianFilter" );
    aLogFormat . LogDecValue( aStreamRef, its0EnableMedianFilter );
    aLogFormat . LogElement( aStreamRef, "EnableBilateralFilter" );
    aLogFormat . LogDecValue( aStreamRef, its3EnableBilateralFilter );
    aLogFormat . LogElement( aStreamRef, "EnableSlidingAverage" );
    aLogFormat . LogDecValue( aStreamRef, its4EnableSlidingAverage );
    aLogFormat . LogElement( aStreamRef, "EnableWigglingCompensation" );
    aLogFormat . LogDecValue( aStreamRef, its6EnableWigglingCompensation );
    aLogFormat . LogElement( aStreamRef, "EnableFPPNCompensation" );
    aLogFormat . LogDecValue( aStreamRef, its7EnableFPPNCompensation );
    aLogFormat . LogElement( aStreamRef, "EnableFrameAverageFilter" );
    aLogFormat . LogDecValue( aStreamRef, its10EnableFrameAverageFilter );
    aLogFormat . LogElement( aStreamRef, "EnableTemperatureCompensation" );
    aLogFormat . LogDecValue( aStreamRef, its11EnableTemperatureCompensation );
    aLogFormat . LogElement( aStreamRef, "EnableOffsetViaDistOffset0" );
    aLogFormat . LogDecValue( aStreamRef, its13EnableOffsetViaDistOffset0 );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
