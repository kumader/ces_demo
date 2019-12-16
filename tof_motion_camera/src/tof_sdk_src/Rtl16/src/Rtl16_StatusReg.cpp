///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- StatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class StatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_StatusReg.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

StatusReg::StatusReg ( ) 
: its0Addr ( 0x3 )
, its0Reg ( 0 )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

StatusReg::StatusReg ( const uint2 & a0AddrValue, const uint2& a0RegValue ) 
: its0Addr ( a0AddrValue )
, its0Reg  ( a0RegValue )
{
  /// nothing
}



//------------------------------ Destructor ----------------------------

StatusReg::~StatusReg (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool StatusReg::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (its0Addr != 0x3) return false; //init value; on false, do not update aByteOffset

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

bool StatusReg::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //0Addr  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmp0Addr = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmp0Addr = ntohs(*pTmp0Addr);

     if (tmp0Addr != 0x3) return false; //init value; on false, do not update aByteOffset

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
void StatusReg::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void StatusReg::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_StatusReg" );
    aLogFormat . LogElement( aStreamRef, "Addr" );
    aLogFormat . LogHexValue( aStreamRef, its0Addr );
    aLogFormat . LogElement( aStreamRef, "OngoingCalibration" );
    aLogFormat . LogDecValue( aStreamRef, its2OngoingCalibration );
    aLogFormat . LogElement( aStreamRef, "IlluminationTemperatureSensorError" );
    aLogFormat . LogDecValue( aStreamRef, its3IlluminationTemperatureSensorError );
    aLogFormat . LogElement( aStreamRef, "TofSensorTemperatureSensorError" );
    aLogFormat . LogDecValue( aStreamRef, its4TofSensorTemperatureSensorError );
    aLogFormat . LogElement( aStreamRef, "CalibrationDataMissing" );
    aLogFormat . LogDecValue( aStreamRef, its5CalibrationDataMissing );
    aLogFormat . LogElement( aStreamRef, "FactoryRegMapWasLoaded" );
    aLogFormat . LogDecValue( aStreamRef, its6FactoryRegMapWasLoaded );
    aLogFormat . LogElement( aStreamRef, "PreviousFirmwareVersionWasRestored" );
    aLogFormat . LogDecValue( aStreamRef, its8PreviousFirmwareVersionWasRestored );
    aLogFormat . LogElement( aStreamRef, "IlluminationOverTemperature" );
    aLogFormat . LogDecValue( aStreamRef, its9IlluminationOverTemperature );
    aLogFormat . LogElement( aStreamRef, "IlluminationError" );
    aLogFormat . LogDecValue( aStreamRef, its11IlluminationError );
    aLogFormat . LogElement( aStreamRef, "TofCCTemperatureError" );
    aLogFormat . LogDecValue( aStreamRef, its14TofCCTemperatureError );
    aLogFormat . LogElement( aStreamRef, "TofCCPLLConfigurationError" );
    aLogFormat . LogDecValue( aStreamRef, its15TofCCPLLConfigurationError );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
