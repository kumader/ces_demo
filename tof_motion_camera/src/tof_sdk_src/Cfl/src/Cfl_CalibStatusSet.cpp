///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class CalibStatusSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Aug 15 16:01:14 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Cfl_CalibStatusSet.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Cfl;

//------------------------------ Constructor -------------------

CalibStatusSet::CalibStatusSet ( ) 
: itsCalibErrorOccured ( false )
, itsNoFPPNCalibrationDataInNVRAM ( false )
, itsNoLensCalibrationDataInNVRAM ( false )
, itsNoWigglingCalibrationInNVRAM ( false )
, itsStatus ( 0 )

{
  /// nothing
}

//------------------------------ Destructor ----------------------------

CalibStatusSet::~CalibStatusSet (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool CalibStatusSet::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{

    //CalibErrorOccured  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpCalibErrorOccured = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpCalibErrorOccured        = itsCalibErrorOccured; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //NoFPPNCalibrationDataInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpNoFPPNCalibrationDataInNVRAM = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpNoFPPNCalibrationDataInNVRAM        = itsNoFPPNCalibrationDataInNVRAM; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //NoLensCalibrationDataInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpNoLensCalibrationDataInNVRAM = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpNoLensCalibrationDataInNVRAM        = itsNoLensCalibrationDataInNVRAM; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //NoWigglingCalibrationInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;
     

     bool * pTmpNoWigglingCalibrationInNVRAM = reinterpret_cast< bool * > ( buffer + aByteOffset );
     *pTmpNoWigglingCalibrationInNVRAM        = itsNoWigglingCalibrationInNVRAM; //FIXME: no endianess checked here
     aByteOffset      += sizeof(bool);
    }

    //Status  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;
     if (itsStatus == 0 || 
      itsStatus == 19 || 
      itsStatus == 20 || 
      itsStatus == 21 || 
      itsStatus == 161 || 
      itsStatus == 255 || 
      itsStatus == 252 || 
      itsStatus == 246 || 
      itsStatus == 244); else { return false; } //array; on false, do not update aByteOffset

     uint2 * pTmpStatus = reinterpret_cast< uint2 * > ( buffer + aByteOffset );
     *pTmpStatus        = htons(itsStatus);
     aByteOffset      += sizeof(uint2);
    }

   return true;
}

bool CalibStatusSet::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{

    //CalibErrorOccured  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpCalibErrorOccured = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpCalibErrorOccured = *pTmpCalibErrorOccured; //FIXME: no endianess checked

     

     itsCalibErrorOccured     = tmpCalibErrorOccured;
     aByteOffset += sizeof(bool);
    }

    //NoFPPNCalibrationDataInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpNoFPPNCalibrationDataInNVRAM = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpNoFPPNCalibrationDataInNVRAM = *pTmpNoFPPNCalibrationDataInNVRAM; //FIXME: no endianess checked

     

     itsNoFPPNCalibrationDataInNVRAM     = tmpNoFPPNCalibrationDataInNVRAM;
     aByteOffset += sizeof(bool);
    }

    //NoLensCalibrationDataInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpNoLensCalibrationDataInNVRAM = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpNoLensCalibrationDataInNVRAM = *pTmpNoLensCalibrationDataInNVRAM; //FIXME: no endianess checked

     

     itsNoLensCalibrationDataInNVRAM     = tmpNoLensCalibrationDataInNVRAM;
     aByteOffset += sizeof(bool);
    }

    //NoWigglingCalibrationInNVRAM  bool serialization with posix endianess
    {
     if( aByteOffset + sizeof(bool) > aBufferSize ) return false;

     const bool * pTmpNoWigglingCalibrationInNVRAM = reinterpret_cast< const bool * > ( buffer + aByteOffset );
     bool tmpNoWigglingCalibrationInNVRAM = *pTmpNoWigglingCalibrationInNVRAM; //FIXME: no endianess checked

     

     itsNoWigglingCalibrationInNVRAM     = tmpNoWigglingCalibrationInNVRAM;
     aByteOffset += sizeof(bool);
    }

    //Status  uint2 serialization with posix endianess
    {
     if( aByteOffset + sizeof(uint2) > aBufferSize ) return false;

     const uint2 * pTmpStatus = reinterpret_cast< const uint2 * > ( buffer + aByteOffset );
     uint2 tmpStatus = ntohs(*pTmpStatus);

     if (itsStatus == 0 || 
      itsStatus == 19 || 
      itsStatus == 20 || 
      itsStatus == 21 || 
      itsStatus == 161 || 
      itsStatus == 255 || 
      itsStatus == 252 || 
      itsStatus == 246 || 
      itsStatus == 244); else { return false; } //array; on false, do not update aByteOffset

     itsStatus     = tmpStatus;
     aByteOffset += sizeof(uint2);
    }

   return true;
}

//------------------------------ Logging ------------------------------
void CalibStatusSet::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10, Common::LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}

void CalibStatusSet::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_CalibStatusSet" );
    aLogFormat . LogElement( aStreamRef, "CalibErrorOccured" );
    aLogFormat . LogDecValue( aStreamRef, itsCalibErrorOccured );
    aLogFormat . LogElement( aStreamRef, "NoFPPNCalibrationDataInNVRAM" );
    aLogFormat . LogDecValue( aStreamRef, itsNoFPPNCalibrationDataInNVRAM );
    aLogFormat . LogElement( aStreamRef, "NoLensCalibrationDataInNVRAM" );
    aLogFormat . LogDecValue( aStreamRef, itsNoLensCalibrationDataInNVRAM );
    aLogFormat . LogElement( aStreamRef, "NoWigglingCalibrationInNVRAM" );
    aLogFormat . LogDecValue( aStreamRef, itsNoWigglingCalibrationInNVRAM );
    aLogFormat . LogElement( aStreamRef, "Status" );
    aLogFormat . LogDecValue( aStreamRef, CalibStatusSet::ConvertToStringStatus(itsStatus) );

   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
