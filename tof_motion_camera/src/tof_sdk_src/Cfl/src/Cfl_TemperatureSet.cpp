///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class TemperatureSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 17:34:02 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Cfl_TemperatureSet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Cfl;

//------------------------------ Constructor -------------------

TemperatureSet::TemperatureSet ( ) 
: itsBaseboardTemp_deg ( 0.0 )
, itsLaserboardOverTempFlag ( false )
, itsLaserboardTempErrorFlag ( false )
, itsLaserboardTempLimit_deg ( 0.0 )
, itsLaserboardTemp_deg ( 0.0 )
, itsMainboardTemp_deg ( 0.0 )
, itsProcessorSpeed_MHz ( 0 )
, itsProcessorTemp_deg ( 0.0 )
, itsProcessorTooHotFlag ( false )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

TemperatureSet::~TemperatureSet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool TemperatureSet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //BaseboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpBaseboardTemp_deg = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpBaseboardTemp_deg        = itsBaseboardTemp_deg; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //LaserboardOverTempFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpLaserboardOverTempFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpLaserboardOverTempFlag        = itsLaserboardOverTempFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //LaserboardTempErrorFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpLaserboardTempErrorFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpLaserboardTempErrorFlag        = itsLaserboardTempErrorFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //LaserboardTempLimit_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpLaserboardTempLimit_deg = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpLaserboardTempLimit_deg        = itsLaserboardTempLimit_deg; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //LaserboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpLaserboardTemp_deg = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpLaserboardTemp_deg        = itsLaserboardTemp_deg; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //MainboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpMainboardTemp_deg = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpMainboardTemp_deg        = itsMainboardTemp_deg; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //ProcessorSpeed_MHz  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpProcessorSpeed_MHz = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpProcessorSpeed_MHz        = htons(itsProcessorSpeed_MHz);
     aByteOffset      += sizeof(uint2);
    }

    //ProcessorTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpProcessorTemp_deg = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpProcessorTemp_deg        = itsProcessorTemp_deg; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //ProcessorTooHotFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpProcessorTooHotFlag = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpProcessorTooHotFlag        = itsProcessorTooHotFlag; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

   return true;
}

bool TemperatureSet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //BaseboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpBaseboardTemp_deg = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpBaseboardTemp_deg = *pTmpBaseboardTemp_deg; //FIXME: no endianess checked

     

     itsBaseboardTemp_deg     = tmpBaseboardTemp_deg;
     aByteOffset += sizeof(float);
    }

    //LaserboardOverTempFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpLaserboardOverTempFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpLaserboardOverTempFlag = *pTmpLaserboardOverTempFlag; //FIXME: no endianess checked

     

     itsLaserboardOverTempFlag     = tmpLaserboardOverTempFlag;
     aByteOffset += sizeof(bool);
    }

    //LaserboardTempErrorFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpLaserboardTempErrorFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpLaserboardTempErrorFlag = *pTmpLaserboardTempErrorFlag; //FIXME: no endianess checked

     

     itsLaserboardTempErrorFlag     = tmpLaserboardTempErrorFlag;
     aByteOffset += sizeof(bool);
    }

    //LaserboardTempLimit_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpLaserboardTempLimit_deg = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpLaserboardTempLimit_deg = *pTmpLaserboardTempLimit_deg; //FIXME: no endianess checked

     

     itsLaserboardTempLimit_deg     = tmpLaserboardTempLimit_deg;
     aByteOffset += sizeof(float);
    }

    //LaserboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpLaserboardTemp_deg = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpLaserboardTemp_deg = *pTmpLaserboardTemp_deg; //FIXME: no endianess checked

     

     itsLaserboardTemp_deg     = tmpLaserboardTemp_deg;
     aByteOffset += sizeof(float);
    }

    //MainboardTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpMainboardTemp_deg = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpMainboardTemp_deg = *pTmpMainboardTemp_deg; //FIXME: no endianess checked

     

     itsMainboardTemp_deg     = tmpMainboardTemp_deg;
     aByteOffset += sizeof(float);
    }

    //ProcessorSpeed_MHz  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpProcessorSpeed_MHz = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpProcessorSpeed_MHz = ntohs(*pTmpProcessorSpeed_MHz);

     

     itsProcessorSpeed_MHz     = tmpProcessorSpeed_MHz;
     aByteOffset += sizeof(uint2);
    }

    //ProcessorTemp_deg  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpProcessorTemp_deg = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpProcessorTemp_deg = *pTmpProcessorTemp_deg; //FIXME: no endianess checked

     

     itsProcessorTemp_deg     = tmpProcessorTemp_deg;
     aByteOffset += sizeof(float);
    }

    //ProcessorTooHotFlag  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpProcessorTooHotFlag = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpProcessorTooHotFlag = *pTmpProcessorTooHotFlag; //FIXME: no endianess checked

     

     itsProcessorTooHotFlag     = tmpProcessorTooHotFlag;
     aByteOffset += sizeof(bool);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void TemperatureSet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void TemperatureSet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_TemperatureSet" );
    aLogFormat . LogElement( aStreamRef, "BaseboardTemp_deg" );
    aLogFormat . LogDecValue( aStreamRef, itsBaseboardTemp_deg );
    aLogFormat . LogStringValue( aStreamRef, "degC" );
    aLogFormat . LogElement( aStreamRef, "LaserboardOverTempFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsLaserboardOverTempFlag );
    aLogFormat . LogElement( aStreamRef, "LaserboardTempErrorFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsLaserboardTempErrorFlag );
    aLogFormat . LogElement( aStreamRef, "LaserboardTempLimit_deg" );
    aLogFormat . LogDecValue( aStreamRef, itsLaserboardTempLimit_deg );
    aLogFormat . LogStringValue( aStreamRef, "degC" );
    aLogFormat . LogElement( aStreamRef, "LaserboardTemp_deg" );
    aLogFormat . LogDecValue( aStreamRef, itsLaserboardTemp_deg );
    aLogFormat . LogStringValue( aStreamRef, "degC" );
    aLogFormat . LogElement( aStreamRef, "MainboardTemp_deg" );
    aLogFormat . LogDecValue( aStreamRef, itsMainboardTemp_deg );
    aLogFormat . LogStringValue( aStreamRef, "degC" );
    aLogFormat . LogElement( aStreamRef, "ProcessorSpeed_MHz" );
    aLogFormat . LogDecValue( aStreamRef, itsProcessorSpeed_MHz );
    aLogFormat . LogStringValue( aStreamRef, "MHz" );
    aLogFormat . LogElement( aStreamRef, "ProcessorTemp_deg" );
    aLogFormat . LogDecValue( aStreamRef, itsProcessorTemp_deg );
    aLogFormat . LogStringValue( aStreamRef, "degC" );
    aLogFormat . LogElement( aStreamRef, "ProcessorTooHotFlag" );
    aLogFormat . LogDecValue( aStreamRef, itsProcessorTooHotFlag );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
