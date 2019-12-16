///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class ErrorSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Aug 15 16:01:18 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Cfl_ErrorSet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Cfl;

//------------------------------ Constructor -------------------

ErrorSet::ErrorSet ( ) 
: itsApplicationProcessorTooHot ( false )
, itsCalibrationDataMissing ( false )
, itsCaptureError ( false )
, itsCaptureTimeout ( false )
, itsIlluminationError ( false )
, itsIlluminationOverTemperature ( false )
, itsIlluminationTemperatureSensorError ( false )
, itsSerdesError ( false )
, itsTofCCPLLConfigurationError ( false )
, itsTofCCTemperatureError ( false )
, itsTofSensorTemperatureSensorError ( false )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

ErrorSet::~ErrorSet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool ErrorSet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //ApplicationProcessorTooHot  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpApplicationProcessorTooHot = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpApplicationProcessorTooHot        = itsApplicationProcessorTooHot; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //CalibrationDataMissing  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpCalibrationDataMissing = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpCalibrationDataMissing        = itsCalibrationDataMissing; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //CaptureError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpCaptureError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpCaptureError        = itsCaptureError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //CaptureTimeout  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpCaptureTimeout = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpCaptureTimeout        = itsCaptureTimeout; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //IlluminationError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpIlluminationError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpIlluminationError        = itsIlluminationError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //IlluminationOverTemperature  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpIlluminationOverTemperature = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpIlluminationOverTemperature        = itsIlluminationOverTemperature; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //IlluminationTemperatureSensorError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpIlluminationTemperatureSensorError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpIlluminationTemperatureSensorError        = itsIlluminationTemperatureSensorError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //SerdesError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpSerdesError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpSerdesError        = itsSerdesError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //TofCCPLLConfigurationError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpTofCCPLLConfigurationError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpTofCCPLLConfigurationError        = itsTofCCPLLConfigurationError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //TofCCTemperatureError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpTofCCTemperatureError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpTofCCTemperatureError        = itsTofCCTemperatureError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //TofSensorTemperatureSensorError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpTofSensorTemperatureSensorError = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpTofSensorTemperatureSensorError        = itsTofSensorTemperatureSensorError; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

   return true;
}

bool ErrorSet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //ApplicationProcessorTooHot  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpApplicationProcessorTooHot = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpApplicationProcessorTooHot = *pTmpApplicationProcessorTooHot; //FIXME: no endianess checked

     

     itsApplicationProcessorTooHot     = tmpApplicationProcessorTooHot;
     aByteOffset += sizeof(bool);
    }

    //CalibrationDataMissing  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpCalibrationDataMissing = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpCalibrationDataMissing = *pTmpCalibrationDataMissing; //FIXME: no endianess checked

     

     itsCalibrationDataMissing     = tmpCalibrationDataMissing;
     aByteOffset += sizeof(bool);
    }

    //CaptureError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpCaptureError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpCaptureError = *pTmpCaptureError; //FIXME: no endianess checked

     

     itsCaptureError     = tmpCaptureError;
     aByteOffset += sizeof(bool);
    }

    //CaptureTimeout  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpCaptureTimeout = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpCaptureTimeout = *pTmpCaptureTimeout; //FIXME: no endianess checked

     

     itsCaptureTimeout     = tmpCaptureTimeout;
     aByteOffset += sizeof(bool);
    }

    //IlluminationError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpIlluminationError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpIlluminationError = *pTmpIlluminationError; //FIXME: no endianess checked

     

     itsIlluminationError     = tmpIlluminationError;
     aByteOffset += sizeof(bool);
    }

    //IlluminationOverTemperature  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpIlluminationOverTemperature = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpIlluminationOverTemperature = *pTmpIlluminationOverTemperature; //FIXME: no endianess checked

     

     itsIlluminationOverTemperature     = tmpIlluminationOverTemperature;
     aByteOffset += sizeof(bool);
    }

    //IlluminationTemperatureSensorError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpIlluminationTemperatureSensorError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpIlluminationTemperatureSensorError = *pTmpIlluminationTemperatureSensorError; //FIXME: no endianess checked

     

     itsIlluminationTemperatureSensorError     = tmpIlluminationTemperatureSensorError;
     aByteOffset += sizeof(bool);
    }

    //SerdesError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpSerdesError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpSerdesError = *pTmpSerdesError; //FIXME: no endianess checked

     

     itsSerdesError     = tmpSerdesError;
     aByteOffset += sizeof(bool);
    }

    //TofCCPLLConfigurationError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpTofCCPLLConfigurationError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpTofCCPLLConfigurationError = *pTmpTofCCPLLConfigurationError; //FIXME: no endianess checked

     

     itsTofCCPLLConfigurationError     = tmpTofCCPLLConfigurationError;
     aByteOffset += sizeof(bool);
    }

    //TofCCTemperatureError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpTofCCTemperatureError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpTofCCTemperatureError = *pTmpTofCCTemperatureError; //FIXME: no endianess checked

     

     itsTofCCTemperatureError     = tmpTofCCTemperatureError;
     aByteOffset += sizeof(bool);
    }

    //TofSensorTemperatureSensorError  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpTofSensorTemperatureSensorError = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpTofSensorTemperatureSensorError = *pTmpTofSensorTemperatureSensorError; //FIXME: no endianess checked

     

     itsTofSensorTemperatureSensorError     = tmpTofSensorTemperatureSensorError;
     aByteOffset += sizeof(bool);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void ErrorSet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void ErrorSet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_ErrorSet" );
    aLogFormat . LogElement( aStreamRef, "ApplicationProcessorTooHot" );
    aLogFormat . LogDecValue( aStreamRef, itsApplicationProcessorTooHot );
    aLogFormat . LogElement( aStreamRef, "CalibrationDataMissing" );
    aLogFormat . LogDecValue( aStreamRef, itsCalibrationDataMissing );
    aLogFormat . LogElement( aStreamRef, "CaptureError" );
    aLogFormat . LogDecValue( aStreamRef, itsCaptureError );
    aLogFormat . LogElement( aStreamRef, "CaptureTimeout" );
    aLogFormat . LogDecValue( aStreamRef, itsCaptureTimeout );
    aLogFormat . LogElement( aStreamRef, "IlluminationError" );
    aLogFormat . LogDecValue( aStreamRef, itsIlluminationError );
    aLogFormat . LogElement( aStreamRef, "IlluminationOverTemperature" );
    aLogFormat . LogDecValue( aStreamRef, itsIlluminationOverTemperature );
    aLogFormat . LogElement( aStreamRef, "IlluminationTemperatureSensorError" );
    aLogFormat . LogDecValue( aStreamRef, itsIlluminationTemperatureSensorError );
    aLogFormat . LogElement( aStreamRef, "SerdesError" );
    aLogFormat . LogDecValue( aStreamRef, itsSerdesError );
    aLogFormat . LogElement( aStreamRef, "TofCCPLLConfigurationError" );
    aLogFormat . LogDecValue( aStreamRef, itsTofCCPLLConfigurationError );
    aLogFormat . LogElement( aStreamRef, "TofCCTemperatureError" );
    aLogFormat . LogDecValue( aStreamRef, itsTofCCTemperatureError );
    aLogFormat . LogElement( aStreamRef, "TofSensorTemperatureSensorError" );
    aLogFormat . LogDecValue( aStreamRef, itsTofSensorTemperatureSensorError );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
