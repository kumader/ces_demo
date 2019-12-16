///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- TemperatureGroup
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class TemperatureGroup 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Jul 19 20:33:27 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_TemperatureGroup_
#define _Rtl16_TemperatureGroup_

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

#include "Rtl16_Virtual16BitReg.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Rtl16
namespace Rtl16
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class TemperatureGroup
class TemperatureGroup: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        TemperatureGroup( );

   /// Destructor
        ~TemperatureGroup( );

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
       bool operator == (const TemperatureGroup & aRef) const;
   
   /// Less operator 
       bool operator < (const TemperatureGroup & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member BaseboardTemp_deg
         ///  The Get function for member BaseboardTemp_deg
              float   GetBaseboardTemp_deg( ) const;
         ///  The Set function for member BaseboardTemp_deg
              void    SetBaseboardTemp_deg( const float & aValue );
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

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         float itsBaseboardTemp_deg;
         float itsLaserboardTemp_deg;
         float itsMainboardTemp_deg;
         uint2 itsProcessorSpeed_MHz;
         float itsProcessorTemp_deg;

};
};

}; // End of class TemperatureGroup

//------------------------------ Inline Functions ----------------------
inline bool TemperatureGroup::operator == (const TemperatureGroup & aRef) const
{
   if ( ! (itsBaseboardTemp_deg == aRef.itsBaseboardTemp_deg) ) return false;
   if ( ! (itsLaserboardTemp_deg == aRef.itsLaserboardTemp_deg) ) return false;
   if ( ! (itsMainboardTemp_deg == aRef.itsMainboardTemp_deg) ) return false;
   if ( ! (itsProcessorSpeed_MHz == aRef.itsProcessorSpeed_MHz) ) return false;
   if ( ! (itsProcessorTemp_deg == aRef.itsProcessorTemp_deg) ) return false;

   return true;
}

inline bool TemperatureGroup::operator < (const TemperatureGroup & aRef) const
{
   if ( ! (itsBaseboardTemp_deg < aRef.itsBaseboardTemp_deg) ) return false;
   if ( ! (itsLaserboardTemp_deg < aRef.itsLaserboardTemp_deg) ) return false;
   if ( ! (itsMainboardTemp_deg < aRef.itsMainboardTemp_deg) ) return false;
   if ( ! (itsProcessorSpeed_MHz < aRef.itsProcessorSpeed_MHz) ) return false;
   if ( ! (itsProcessorTemp_deg < aRef.itsProcessorTemp_deg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const TemperatureGroup & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline float TemperatureGroup::GetBaseboardTemp_deg( ) const
{
 return itsBaseboardTemp_deg;
}

inline void TemperatureGroup::SetBaseboardTemp_deg( const float & aValue )
{
 itsBaseboardTemp_deg = aValue;
}

inline float TemperatureGroup::GetLaserboardTemp_deg( ) const
{
 return itsLaserboardTemp_deg;
}

inline void TemperatureGroup::SetLaserboardTemp_deg( const float & aValue )
{
 itsLaserboardTemp_deg = aValue;
}

inline float TemperatureGroup::GetMainboardTemp_deg( ) const
{
 return itsMainboardTemp_deg;
}

inline void TemperatureGroup::SetMainboardTemp_deg( const float & aValue )
{
 itsMainboardTemp_deg = aValue;
}

inline uint2 TemperatureGroup::GetProcessorSpeed_MHz( ) const
{
 return itsProcessorSpeed_MHz;
}

inline void TemperatureGroup::SetProcessorSpeed_MHz( const uint2 & aValue )
{
 itsProcessorSpeed_MHz = aValue;
}

inline float TemperatureGroup::GetProcessorTemp_deg( ) const
{
 return itsProcessorTemp_deg;
}

inline void TemperatureGroup::SetProcessorTemp_deg( const float & aValue )
{
 itsProcessorTemp_deg = aValue;
}






}; // End of namespace Rtl16

#endif

