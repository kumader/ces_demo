///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 3773 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class PreciseTimeValue 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Sep 14 21:35:38 2004
//              automatically generated code
//              manually modified
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_PreciseTimeValue_
#define _Common_PreciseTimeValue_

#ifdef USE_IDENT
#ident "$Header$" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include <string>
//#include <sys/time.h>
#include <time.h>
#include <windows.h>
#include "Common_LogFormat.h"

//------------------------------ Declarations --------------------------
class LogCtx;

/// The namespace Common
namespace Common
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class PreciseTimeValue
class PreciseTimeValue
{
public:

   // enums
      enum PreciseTimeValue_e
      {
       PTV_TIME
      ,PTV_DATE
      ,PTV_DATE_TIME
      };
   
   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        PreciseTimeValue( );

   /// Destructor
        ~PreciseTimeValue( );

   /// Write content into buffer
        bool WriteToBuffer( uint1 * buffer
                          , uint2 aBufferSize
                          , uint2 & aByteOffset ) const;
   /// Read content from buffer
        bool ReadFromBuffer( const uint1 * buffer
                           , uint2 aBufferSize
                           , uint2 & aByteOffset );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef,  Common::LogFormat & aLogFormat ) const;



   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const PreciseTimeValue & aRef) const;
   
   /// Less operator 
       bool operator < (const PreciseTimeValue & aRef) const;

   ///@name Set and Get functions for all members 
   //@{
         // The member TimeSec
         ///  The Get function for member TimeSec
              sint8   GetTimeSec( ) const;
         ///  The Set function for member TimeSec
              void    SetTimeSec( sint8 aValue );
         //----------------------------------------------------
         // The member TimeUs
         ///  The Get function for member TimeUs
              sint8   GetTimeUs( ) const;
         ///  The Set function for member TimeUs
              void    SetTimeUs( sint8 aValue );
         //----------------------------------------------------

   //@}

   ///@name Special Functions 
   //@{
        /// The standard function to read a system time
        void GetPresentTime( void );
        
        /// Subtract another PreciseTimeValue and give Microseconds; NOTE: overflow may occur
        sint8 operator - ( const PreciseTimeValue & rRight ) const;
        
        /// Convert a PreciseTimeValue to a string
	std::string ConvertToString( PreciseTimeValue_e aSelection = PTV_TIME) const;

        /// Sleep seconds and microseconds
        void MySleep(uint4 theMicroseconds, uint4 theSeconds=0 ) const;

   //@}

private:
  

   //   All the Elements

         sint8 itsTimeSec;
         sint8 itsTimeUs;


}; // End of class PreciseTimeValue

#endif
//------------------------------ Inline Functions ----------------------
inline bool PreciseTimeValue::operator == (const PreciseTimeValue& aRef) const
{
    if (itsTimeSec != aRef.itsTimeSec) return false;
    if (itsTimeUs != aRef.itsTimeUs) return false;

    return true;
}

inline bool PreciseTimeValue::operator < (const PreciseTimeValue& aRef) const
{
    if (itsTimeSec >= aRef.itsTimeSec) return false;
    if (itsTimeUs >= aRef.itsTimeUs) return false;

    return true; //min 1 attribute in class
}


inline std::ostream& operator << (std::ostream& aStreamRef, const PreciseTimeValue& aRef)
{
    aRef.Log(aStreamRef);
    return aStreamRef;
}

inline sint8 PreciseTimeValue::GetTimeSec() const
{
    return itsTimeSec;
}

inline void PreciseTimeValue::SetTimeSec(sint8 aValue)
{
    itsTimeSec = aValue;
}
inline sint8 PreciseTimeValue::GetTimeUs() const
{
    return itsTimeUs;
}

inline void PreciseTimeValue::SetTimeUs(sint8 aValue)
{
    itsTimeUs = aValue;
}

struct timezone2
{
    __int32  tz_minuteswest; /* minutes W of Greenwich */
    bool  tz_dsttime;     /* type of dst correction */
};

struct timeval2 {
    __int32    tv_sec;         /* seconds */
    __int32    tv_usec;        /* microseconds */
};

const __int64 DELTA_EPOCH_IN_MICROSECS = 11644473600000000;

inline int GetTimeOfDay(timeval2* tv, timezone2* tz)
{
    FILETIME ft;
    __int64 tmpres = 0;
    TIME_ZONE_INFORMATION tz_winapi;
    int rez = 0;

    ZeroMemory(&ft, sizeof(ft));
    ZeroMemory(&tz_winapi, sizeof(tz_winapi));

    GetSystemTimeAsFileTime(&ft);

    tmpres = ft.dwHighDateTime;
    tmpres <<= 32;
    tmpres |= ft.dwLowDateTime;

    /*converting file time to unix epoch*/
    tmpres /= 10;  /*convert into microseconds*/
    tmpres -= DELTA_EPOCH_IN_MICROSECS;
    tv->tv_sec = (__int32)(tmpres * 0.000001);
    tv->tv_usec = (tmpres % 1000000);


    //_tzset(),don't work properly, so we use GetTimeZoneInformation
    rez = GetTimeZoneInformation(&tz_winapi);

    if (tz)
    {
        tz->tz_dsttime = (rez == 2) ? true : false;
        tz->tz_minuteswest = tz_winapi.Bias + ((rez == 2) ? tz_winapi.DaylightBias : 0);
    }

    return 0;
}
//NOTE: inline for performance optimization 
inline void PreciseTimeValue::GetPresentTime(void)
{
    timeval2 tmpTimeVal;

    GetTimeOfDay(&tmpTimeVal, NULL);

    itsTimeSec = tmpTimeVal.tv_sec;
    itsTimeUs = tmpTimeVal.tv_usec;
}

}; // End of namespace Common
