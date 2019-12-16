///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class TemperatureSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 17:34:02 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_TemperatureSet_
#define _Cfl_TemperatureSet_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif

#include <string>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Cfl
namespace Cfl
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class TemperatureSet
class TemperatureSet
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        TemperatureSet( );

   /// Destructor
        ~TemperatureSet( );

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
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const TemperatureSet & aRef) const;
   
   /// Less operator 
       bool operator < (const TemperatureSet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member BaseboardTemp_deg
         ///  The Get function for member BaseboardTemp_deg
              float   GetBaseboardTemp_deg( ) const;
         ///  The Set function for member BaseboardTemp_deg
              void    SetBaseboardTemp_deg( const float & aValue );
         //----------------------------------------------------
         // The member LaserboardOverTempFlag
         ///  The Get function for member LaserboardOverTempFlag
              bool   GetLaserboardOverTempFlag( ) const;
         ///  The Set function for member LaserboardOverTempFlag
              void    SetLaserboardOverTempFlag( const bool & aValue );
         //----------------------------------------------------
         // The member LaserboardTempErrorFlag
         ///  The Get function for member LaserboardTempErrorFlag
              bool   GetLaserboardTempErrorFlag( ) const;
         ///  The Set function for member LaserboardTempErrorFlag
              void    SetLaserboardTempErrorFlag( const bool & aValue );
         //----------------------------------------------------
         // The member LaserboardTempLimit_deg
         ///  The Get function for member LaserboardTempLimit_deg
              float   GetLaserboardTempLimit_deg( ) const;
         ///  The Set function for member LaserboardTempLimit_deg
              void    SetLaserboardTempLimit_deg( const float & aValue );
         //----------------------------------------------------
         // The member LaserboardTemp_deg
         ///  The Get function for member LaserboardTemp_deg
              float   GetLaserboardTemp_deg( ) const;
         ///  The Set function for member LaserboardTemp_deg
              void    SetLaserboardTemp_deg( const float & aValue );
         //----------------------------------------------------
         // The member MainboardTemp_deg
         ///  The Get function for member MainboardTemp_deg
              float   GetMainboardTemp_deg( ) const;
         ///  The Set function for member MainboardTemp_deg
              void    SetMainboardTemp_deg( const float & aValue );
         //----------------------------------------------------
         // The member ProcessorSpeed_MHz
         ///  The Get function for member ProcessorSpeed_MHz
              uint2   GetProcessorSpeed_MHz( ) const;
         ///  The Set function for member ProcessorSpeed_MHz
              void    SetProcessorSpeed_MHz( const uint2 & aValue );
         //----------------------------------------------------
         // The member ProcessorTemp_deg
         ///  The Get function for member ProcessorTemp_deg
              float   GetProcessorTemp_deg( ) const;
         ///  The Set function for member ProcessorTemp_deg
              void    SetProcessorTemp_deg( const float & aValue );
         //----------------------------------------------------
         // The member ProcessorTooHotFlag
         ///  The Get function for member ProcessorTooHotFlag
              bool   GetProcessorTooHotFlag( ) const;
         ///  The Set function for member ProcessorTooHotFlag
              void    SetProcessorTooHotFlag( const bool & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         float itsBaseboardTemp_deg;
         bool itsLaserboardOverTempFlag;
         bool itsLaserboardTempErrorFlag;
         float itsLaserboardTempLimit_deg;
         float itsLaserboardTemp_deg;
         float itsMainboardTemp_deg;
         uint2 itsProcessorSpeed_MHz;
         float itsProcessorTemp_deg;
         bool itsProcessorTooHotFlag;


}; // End of class TemperatureSet

//------------------------------ Inline Functions ----------------------
inline bool TemperatureSet::operator == (const TemperatureSet & aRef) const
{
   if ( ! (itsBaseboardTemp_deg == aRef.itsBaseboardTemp_deg) ) return false;
   if ( ! (itsLaserboardOverTempFlag == aRef.itsLaserboardOverTempFlag) ) return false;
   if ( ! (itsLaserboardTempErrorFlag == aRef.itsLaserboardTempErrorFlag) ) return false;
   if ( ! (itsLaserboardTempLimit_deg == aRef.itsLaserboardTempLimit_deg) ) return false;
   if ( ! (itsLaserboardTemp_deg == aRef.itsLaserboardTemp_deg) ) return false;
   if ( ! (itsMainboardTemp_deg == aRef.itsMainboardTemp_deg) ) return false;
   if ( ! (itsProcessorSpeed_MHz == aRef.itsProcessorSpeed_MHz) ) return false;
   if ( ! (itsProcessorTemp_deg == aRef.itsProcessorTemp_deg) ) return false;
   if ( ! (itsProcessorTooHotFlag == aRef.itsProcessorTooHotFlag) ) return false;

   return true;
}

inline bool TemperatureSet::operator < (const TemperatureSet & aRef) const
{
   if ( ! (itsBaseboardTemp_deg < aRef.itsBaseboardTemp_deg) ) return false;
   if ( ! (itsLaserboardOverTempFlag < aRef.itsLaserboardOverTempFlag) ) return false;
   if ( ! (itsLaserboardTempErrorFlag < aRef.itsLaserboardTempErrorFlag) ) return false;
   if ( ! (itsLaserboardTempLimit_deg < aRef.itsLaserboardTempLimit_deg) ) return false;
   if ( ! (itsLaserboardTemp_deg < aRef.itsLaserboardTemp_deg) ) return false;
   if ( ! (itsMainboardTemp_deg < aRef.itsMainboardTemp_deg) ) return false;
   if ( ! (itsProcessorSpeed_MHz < aRef.itsProcessorSpeed_MHz) ) return false;
   if ( ! (itsProcessorTemp_deg < aRef.itsProcessorTemp_deg) ) return false;
   if ( ! (itsProcessorTooHotFlag < aRef.itsProcessorTooHotFlag) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const TemperatureSet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline float TemperatureSet::GetBaseboardTemp_deg( ) const
{
 return itsBaseboardTemp_deg;
}

inline void TemperatureSet::SetBaseboardTemp_deg( const float & aValue )
{
 itsBaseboardTemp_deg = aValue;
}

inline bool TemperatureSet::GetLaserboardOverTempFlag( ) const
{
 return itsLaserboardOverTempFlag;
}

inline void TemperatureSet::SetLaserboardOverTempFlag( const bool & aValue )
{
 itsLaserboardOverTempFlag = aValue;
}

inline bool TemperatureSet::GetLaserboardTempErrorFlag( ) const
{
 return itsLaserboardTempErrorFlag;
}

inline void TemperatureSet::SetLaserboardTempErrorFlag( const bool & aValue )
{
 itsLaserboardTempErrorFlag = aValue;
}

inline float TemperatureSet::GetLaserboardTempLimit_deg( ) const
{
 return itsLaserboardTempLimit_deg;
}

inline void TemperatureSet::SetLaserboardTempLimit_deg( const float & aValue )
{
 itsLaserboardTempLimit_deg = aValue;
}

inline float TemperatureSet::GetLaserboardTemp_deg( ) const
{
 return itsLaserboardTemp_deg;
}

inline void TemperatureSet::SetLaserboardTemp_deg( const float & aValue )
{
 itsLaserboardTemp_deg = aValue;
}

inline float TemperatureSet::GetMainboardTemp_deg( ) const
{
 return itsMainboardTemp_deg;
}

inline void TemperatureSet::SetMainboardTemp_deg( const float & aValue )
{
 itsMainboardTemp_deg = aValue;
}

inline uint2 TemperatureSet::GetProcessorSpeed_MHz( ) const
{
 return itsProcessorSpeed_MHz;
}

inline void TemperatureSet::SetProcessorSpeed_MHz( const uint2 & aValue )
{
 itsProcessorSpeed_MHz = aValue;
}

inline float TemperatureSet::GetProcessorTemp_deg( ) const
{
 return itsProcessorTemp_deg;
}

inline void TemperatureSet::SetProcessorTemp_deg( const float & aValue )
{
 itsProcessorTemp_deg = aValue;
}

inline bool TemperatureSet::GetProcessorTooHotFlag( ) const
{
 return itsProcessorTooHotFlag;
}

inline void TemperatureSet::SetProcessorTooHotFlag( const bool & aValue )
{
 itsProcessorTooHotFlag = aValue;
}






}; // End of namespace Cfl

#endif

