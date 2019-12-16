///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 3774 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class PreciseTimeValue 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Sep 14 21:35:38 2004
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header$" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_PreciseTimeValue.h"
#include "Common_LogFormat.h"
#include <stdio.h>
//#include <unistd.h>

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------

PreciseTimeValue::PreciseTimeValue ( ) 
: itsTimeSec ( 91 )
, itsTimeUs ( 92 )

{
 ///nothing
}

//------------------------------ Destructor ----------------------------

PreciseTimeValue::~PreciseTimeValue (  ) 
{
  /// nothing
}


//------------------------------ Pickling ------------------------------

bool PreciseTimeValue::WriteToBuffer( uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset ) const
{
    if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;
    sint8 * pTmpTimeSec = reinterpret_cast< sint8 * > ( buffer + aByteOffset );
    *pTmpTimeSec = itsTimeSec;
    aByteOffset += sizeof(sint8);
    if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;
    sint8 * pTmpTimeUs = reinterpret_cast< sint8 * > ( buffer + aByteOffset );
    *pTmpTimeUs = itsTimeUs;
    aByteOffset += sizeof(sint8);

   return true;
}

bool PreciseTimeValue::ReadFromBuffer( const uint1 * buffer, uint2 aBufferSize, uint2 & aByteOffset )
{
    if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;
    const sint8 * pTmpTimeSec = reinterpret_cast< const sint8 * > ( buffer + aByteOffset );
    itsTimeSec = *pTmpTimeSec;
    aByteOffset += sizeof(sint8);
    if( aByteOffset + sizeof(sint8) > aBufferSize ) return false;
    const sint8 * pTmpTimeUs = reinterpret_cast< const sint8 * > ( buffer + aByteOffset );
    itsTimeUs = *pTmpTimeUs;
    aByteOffset += sizeof(sint8);

   return true;
}

//------------------------------ Logging ------------------------------
void PreciseTimeValue::Log( ostream & aStreamRef ) const
{
    Common::LogFormat tmpLogFormat( 10 );
    Log( aStreamRef, tmpLogFormat );
    
}

void PreciseTimeValue::Log( ostream & aStreamRef,  Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Common_PreciseTimeValue" );
    aLogFormat . LogElement( aStreamRef, "TimeSec" );
    aLogFormat . LogDecValue( aStreamRef, itsTimeSec );
    aLogFormat . LogElement( aStreamRef, "TimeUs" );
    aLogFormat . LogDecValue( aStreamRef, itsTimeUs );
   aLogFormat . LogEndStruct( aStreamRef );
}

string PreciseTimeValue::ConvertToString( PreciseTimeValue_e aSelection ) const
{
   const size_t MAX_STRING_SIZE = 27;   //FIX: stack-smashing, format is 01/01/1970<space>00:00:00:000000\0 
   char tmpTimeString[MAX_STRING_SIZE];
   //TST struct tm tmpTime;
   //TST tm *ptmvalue = localtime_r( & ( itsTimeSec ), &tmpTime );  //TBD check for leak
   
   time_t temp = itsTimeSec;

   tm *ptmvalue = localtime( & ( temp ) );  //TBD check for leak

   if ( ptmvalue )
   {
      switch ( aSelection )
      {
      default:
         // intentional fall through
         // should not occure
      case PTV_TIME:
         {
            size_t size = strftime( tmpTimeString, MAX_STRING_SIZE - 7, "%H:%M:%S", ptmvalue );      //FIX: strftime writes also a \0 
            printf( &tmpTimeString[size], 8, ":%06ld", itsTimeUs );                     //PROTECTED: size <= 19
         }
         break;
      case PTV_DATE:
         {
            strftime( tmpTimeString, MAX_STRING_SIZE, "%d/%m/%Y", ptmvalue );
         }
         break;
      case PTV_DATE_TIME:
         {
            size_t size = strftime( tmpTimeString, MAX_STRING_SIZE - 7, "%d/%m/%Y %H:%M:%S", ptmvalue );    //FIX: strftime writes also a \0 
            printf( &tmpTimeString[size], 8, ":%06ld", itsTimeUs );                            //PROTECTED: size <= 19
         }
         break;
      }
      
      return string( tmpTimeString );
   }
   else
   {
      return string( "no_time" );
   }
}

//NOTE: arithmetic overflow can occur
sint8 PreciseTimeValue::operator - ( const PreciseTimeValue & rRight ) const
{
  sint8 diffTimeSec = itsTimeSec - rRight.itsTimeSec;

  //TBD need overflow protection
  sint8 diffTimeUs = diffTimeSec*1000000 + (itsTimeUs - rRight.itsTimeUs);
  return diffTimeUs;
}

void PreciseTimeValue::MySleep(uint4 theMicroseconds, uint4 theSeconds ) const
{

#ifdef _TARGET_ARCH_W32_

 cerr << "WARNING: PreciseTimeValue::MySleep: select in w32 not supported, no sleep done"<<endl;
 return;

#else

  struct timeval tv;

  tv.tv_sec  = theSeconds;
  tv.tv_usec = theMicroseconds;
  select(0, NULL, NULL, NULL, &tv);
#endif

}

//End of File
