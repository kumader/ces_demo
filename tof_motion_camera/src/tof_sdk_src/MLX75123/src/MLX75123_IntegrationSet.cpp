///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class IntegrationSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Thu Jul 27 21:49:16 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "MLX75123_IntegrationSet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace MLX75123;

//------------------------------ Constructor -------------------

IntegrationSet::IntegrationSet ( ) 
: itsFin_MHz ( 0 )
, itsFout_MHz ( 0.0 )
, itsFrameIdleTime_tmix ( 0 )
, itsFrameRate_Hz ( 0.0 )
, itsIllPower_percent ( 0 )
, itsIntegrationTimePhase0_tmix ( 0 )
, itsIntegrationTimePhase1_tmix ( 0 )
, itsIntegrationTimePhase2_tmix ( 0 )
, itsIntegrationTimePhase3_tmix ( 0 )
, itsLaserPower_W ( 0.0 )
, itsMixhVoltage_V ( 0.0 )
, itsReadoutTime_tmix ( 0 )
, itsTmix_us ( 0.0 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

IntegrationSet::~IntegrationSet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool IntegrationSet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //Fin_MHz  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpFin_MHz = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpFin_MHz        = htons(itsFin_MHz);
     aByteOffset      += sizeof(uint2);
    }

    //Fout_MHz  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpFout_MHz = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpFout_MHz        = itsFout_MHz; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //FrameIdleTime_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpFrameIdleTime_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpFrameIdleTime_tmix        = htonl(itsFrameIdleTime_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //FrameRate_Hz  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpFrameRate_Hz = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpFrameRate_Hz        = itsFrameRate_Hz; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //IllPower_percent  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     

     uint2 * pTmpIllPower_percent = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpIllPower_percent        = htons(itsIllPower_percent);
     aByteOffset      += sizeof(uint2);
    }

    //IntegrationTimePhase0_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpIntegrationTimePhase0_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpIntegrationTimePhase0_tmix        = htonl(itsIntegrationTimePhase0_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //IntegrationTimePhase1_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpIntegrationTimePhase1_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpIntegrationTimePhase1_tmix        = htonl(itsIntegrationTimePhase1_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //IntegrationTimePhase2_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpIntegrationTimePhase2_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpIntegrationTimePhase2_tmix        = htonl(itsIntegrationTimePhase2_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //IntegrationTimePhase3_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpIntegrationTimePhase3_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpIntegrationTimePhase3_tmix        = htonl(itsIntegrationTimePhase3_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //LaserPower_W  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpLaserPower_W = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpLaserPower_W        = itsLaserPower_W; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //MixhVoltage_V  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpMixhVoltage_V = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpMixhVoltage_V        = itsMixhVoltage_V; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

    //ReadoutTime_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;
     

     uint4 * pTmpReadoutTime_tmix = reinterpret_cast< uint4 * > ( buffer + aByteOffset );
     *pTmpReadoutTime_tmix        = htonl(itsReadoutTime_tmix);
     aByteOffset      += sizeof(uint4);
    }

    //Tmix_us  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;
     

     float * pTmpTmix_us = reinterpret_cast< float * > ( buffer + aByteOffset );
     *pTmpTmix_us        = itsTmix_us; //FIXME: no endianess checked here
     aByteOffset      += sizeof(float);
    }

   return true;
}

bool IntegrationSet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //Fin_MHz  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpFin_MHz = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpFin_MHz = ntohs(*pTmpFin_MHz);

     

     itsFin_MHz     = tmpFin_MHz;
     aByteOffset += sizeof(uint2);
    }

    //Fout_MHz  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpFout_MHz = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpFout_MHz = *pTmpFout_MHz; //FIXME: no endianess checked

     

     itsFout_MHz     = tmpFout_MHz;
     aByteOffset += sizeof(float);
    }

    //FrameIdleTime_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpFrameIdleTime_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpFrameIdleTime_tmix = ntohl(*pTmpFrameIdleTime_tmix);

     

     itsFrameIdleTime_tmix     = tmpFrameIdleTime_tmix;
     aByteOffset += sizeof(uint4);
    }

    //FrameRate_Hz  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpFrameRate_Hz = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpFrameRate_Hz = *pTmpFrameRate_Hz; //FIXME: no endianess checked

     

     itsFrameRate_Hz     = tmpFrameRate_Hz;
     aByteOffset += sizeof(float);
    }

    //IllPower_percent  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpIllPower_percent = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpIllPower_percent = ntohs(*pTmpIllPower_percent);

     

     itsIllPower_percent     = tmpIllPower_percent;
     aByteOffset += sizeof(uint2);
    }

    //IntegrationTimePhase0_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpIntegrationTimePhase0_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpIntegrationTimePhase0_tmix = ntohl(*pTmpIntegrationTimePhase0_tmix);

     

     itsIntegrationTimePhase0_tmix     = tmpIntegrationTimePhase0_tmix;
     aByteOffset += sizeof(uint4);
    }

    //IntegrationTimePhase1_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpIntegrationTimePhase1_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpIntegrationTimePhase1_tmix = ntohl(*pTmpIntegrationTimePhase1_tmix);

     

     itsIntegrationTimePhase1_tmix     = tmpIntegrationTimePhase1_tmix;
     aByteOffset += sizeof(uint4);
    }

    //IntegrationTimePhase2_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpIntegrationTimePhase2_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpIntegrationTimePhase2_tmix = ntohl(*pTmpIntegrationTimePhase2_tmix);

     

     itsIntegrationTimePhase2_tmix     = tmpIntegrationTimePhase2_tmix;
     aByteOffset += sizeof(uint4);
    }

    //IntegrationTimePhase3_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpIntegrationTimePhase3_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpIntegrationTimePhase3_tmix = ntohl(*pTmpIntegrationTimePhase3_tmix);

     

     itsIntegrationTimePhase3_tmix     = tmpIntegrationTimePhase3_tmix;
     aByteOffset += sizeof(uint4);
    }

    //LaserPower_W  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpLaserPower_W = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpLaserPower_W = *pTmpLaserPower_W; //FIXME: no endianess checked

     

     itsLaserPower_W     = tmpLaserPower_W;
     aByteOffset += sizeof(float);
    }

    //MixhVoltage_V  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpMixhVoltage_V = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpMixhVoltage_V = *pTmpMixhVoltage_V; //FIXME: no endianess checked

     

     itsMixhVoltage_V     = tmpMixhVoltage_V;
     aByteOffset += sizeof(float);
    }

    //ReadoutTime_tmix  uint4 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint4) > aBufferSize ) return false;

     const uint4 * pTmpReadoutTime_tmix = reinterpret_cast< const uint4 * > ( buffer + aByteOffset );
     uint4 tmpReadoutTime_tmix = ntohl(*pTmpReadoutTime_tmix);

     

     itsReadoutTime_tmix     = tmpReadoutTime_tmix;
     aByteOffset += sizeof(uint4);
    }

    //Tmix_us  float serialization with posix endianess
    {
     if( aByteOffset + sizeof(float) > aBufferSize ) return false;

     const float * pTmpTmix_us = reinterpret_cast< const float * > ( buffer + aByteOffset );
     float tmpTmix_us = *pTmpTmix_us; //FIXME: no endianess checked

     

     itsTmix_us     = tmpTmix_us;
     aByteOffset += sizeof(float);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void IntegrationSet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void IntegrationSet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "MLX75123_IntegrationSet" );
    aLogFormat . LogElement( aStreamRef, "Fin_MHz" );
    aLogFormat . LogDecValue( aStreamRef, itsFin_MHz );
    aLogFormat . LogStringValue( aStreamRef, "MHz" );
    aLogFormat . LogElement( aStreamRef, "Fout_MHz" );
    aLogFormat . LogDecValue( aStreamRef, itsFout_MHz );
    aLogFormat . LogStringValue( aStreamRef, "MHz" );
    aLogFormat . LogElement( aStreamRef, "FrameIdleTime_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsFrameIdleTime_tmix );
    aLogFormat . LogElement( aStreamRef, "FrameRate_Hz" );
    aLogFormat . LogDecValue( aStreamRef, itsFrameRate_Hz );
    aLogFormat . LogStringValue( aStreamRef, "Hz" );
    aLogFormat . LogElement( aStreamRef, "IllPower_percent" );
    aLogFormat . LogDecValue( aStreamRef, itsIllPower_percent );
    aLogFormat . LogStringValue( aStreamRef, "%" );
    aLogFormat . LogElement( aStreamRef, "IntegrationTimePhase0_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsIntegrationTimePhase0_tmix );
    aLogFormat . LogElement( aStreamRef, "IntegrationTimePhase1_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsIntegrationTimePhase1_tmix );
    aLogFormat . LogElement( aStreamRef, "IntegrationTimePhase2_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsIntegrationTimePhase2_tmix );
    aLogFormat . LogElement( aStreamRef, "IntegrationTimePhase3_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsIntegrationTimePhase3_tmix );
    aLogFormat . LogElement( aStreamRef, "LaserPower_W" );
    aLogFormat . LogDecValue( aStreamRef, itsLaserPower_W );
    aLogFormat . LogStringValue( aStreamRef, "W" );
    aLogFormat . LogElement( aStreamRef, "MixhVoltage_V" );
    aLogFormat . LogDecValue( aStreamRef, itsMixhVoltage_V );
    aLogFormat . LogStringValue( aStreamRef, "V" );
    aLogFormat . LogElement( aStreamRef, "ReadoutTime_tmix" );
    aLogFormat . LogDecValue( aStreamRef, itsReadoutTime_tmix );
    aLogFormat . LogElement( aStreamRef, "Tmix_us" );
    aLogFormat . LogDecValue( aStreamRef, itsTmix_us );
    aLogFormat . LogStringValue( aStreamRef, "us" );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
