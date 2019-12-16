///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class IntegrationSet 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Thu Jul 27 21:49:16 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _MLX75123_IntegrationSet_
#define _MLX75123_IntegrationSet_

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

/// The namespace MLX75123
namespace MLX75123
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class IntegrationSet
class IntegrationSet
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        IntegrationSet( );

   /// Destructor
        ~IntegrationSet( );

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
       bool operator == (const IntegrationSet & aRef) const;
   
   /// Less operator 
       bool operator < (const IntegrationSet & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member Fin_MHz
         ///  The Get function for member Fin_MHz
              uint2   GetFin_MHz( ) const;
         ///  The Set function for member Fin_MHz
              void    SetFin_MHz( const uint2 & aValue );
         //----------------------------------------------------
         // The member Fout_MHz
         ///  The Get function for member Fout_MHz
              float   GetFout_MHz( ) const;
         ///  The Set function for member Fout_MHz
              void    SetFout_MHz( const float & aValue );
         //----------------------------------------------------
         // The member FrameIdleTime_tmix
         ///  The Get function for member FrameIdleTime_tmix
              uint4   GetFrameIdleTime_tmix( ) const;
         ///  The Set function for member FrameIdleTime_tmix
              void    SetFrameIdleTime_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member FrameRate_Hz
         ///  The Get function for member FrameRate_Hz
              float   GetFrameRate_Hz( ) const;
         ///  The Set function for member FrameRate_Hz
              void    SetFrameRate_Hz( const float & aValue );
         //----------------------------------------------------
         // The member IllPower_percent
         ///  The Get function for member IllPower_percent
              uint2   GetIllPower_percent( ) const;
         ///  The Set function for member IllPower_percent
              void    SetIllPower_percent( const uint2 & aValue );
         //----------------------------------------------------
         // The member IntegrationTimePhase0_tmix
         ///  The Get function for member IntegrationTimePhase0_tmix
              uint4   GetIntegrationTimePhase0_tmix( ) const;
         ///  The Set function for member IntegrationTimePhase0_tmix
              void    SetIntegrationTimePhase0_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member IntegrationTimePhase1_tmix
         ///  The Get function for member IntegrationTimePhase1_tmix
              uint4   GetIntegrationTimePhase1_tmix( ) const;
         ///  The Set function for member IntegrationTimePhase1_tmix
              void    SetIntegrationTimePhase1_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member IntegrationTimePhase2_tmix
         ///  The Get function for member IntegrationTimePhase2_tmix
              uint4   GetIntegrationTimePhase2_tmix( ) const;
         ///  The Set function for member IntegrationTimePhase2_tmix
              void    SetIntegrationTimePhase2_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member IntegrationTimePhase3_tmix
         ///  The Get function for member IntegrationTimePhase3_tmix
              uint4   GetIntegrationTimePhase3_tmix( ) const;
         ///  The Set function for member IntegrationTimePhase3_tmix
              void    SetIntegrationTimePhase3_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member LaserPower_W
         ///  The Get function for member LaserPower_W
              float   GetLaserPower_W( ) const;
         ///  The Set function for member LaserPower_W
              void    SetLaserPower_W( const float & aValue );
         //----------------------------------------------------
         // The member MixhVoltage_V
         ///  The Get function for member MixhVoltage_V
              float   GetMixhVoltage_V( ) const;
         ///  The Set function for member MixhVoltage_V
              void    SetMixhVoltage_V( const float & aValue );
         //----------------------------------------------------
         // The member ReadoutTime_tmix
         ///  The Get function for member ReadoutTime_tmix
              uint4   GetReadoutTime_tmix( ) const;
         ///  The Set function for member ReadoutTime_tmix
              void    SetReadoutTime_tmix( const uint4 & aValue );
         //----------------------------------------------------
         // The member Tmix_us
         ///  The Get function for member Tmix_us
              float   GetTmix_us( ) const;
         ///  The Set function for member Tmix_us
              void    SetTmix_us( const float & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         uint2 itsFin_MHz;
         float itsFout_MHz;
         uint4 itsFrameIdleTime_tmix;
         float itsFrameRate_Hz;
         uint2 itsIllPower_percent;
         uint4 itsIntegrationTimePhase0_tmix;
         uint4 itsIntegrationTimePhase1_tmix;
         uint4 itsIntegrationTimePhase2_tmix;
         uint4 itsIntegrationTimePhase3_tmix;
         float itsLaserPower_W;
         float itsMixhVoltage_V;
         uint4 itsReadoutTime_tmix;
         float itsTmix_us;


}; // End of class IntegrationSet

//------------------------------ Inline Functions ----------------------
inline bool IntegrationSet::operator == (const IntegrationSet & aRef) const
{
   if ( ! (itsFin_MHz == aRef.itsFin_MHz) ) return false;
   if ( ! (itsFout_MHz == aRef.itsFout_MHz) ) return false;
   if ( ! (itsFrameIdleTime_tmix == aRef.itsFrameIdleTime_tmix) ) return false;
   if ( ! (itsFrameRate_Hz == aRef.itsFrameRate_Hz) ) return false;
   if ( ! (itsIllPower_percent == aRef.itsIllPower_percent) ) return false;
   if ( ! (itsIntegrationTimePhase0_tmix == aRef.itsIntegrationTimePhase0_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase1_tmix == aRef.itsIntegrationTimePhase1_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase2_tmix == aRef.itsIntegrationTimePhase2_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase3_tmix == aRef.itsIntegrationTimePhase3_tmix) ) return false;
   if ( ! (itsLaserPower_W == aRef.itsLaserPower_W) ) return false;
   if ( ! (itsMixhVoltage_V == aRef.itsMixhVoltage_V) ) return false;
   if ( ! (itsReadoutTime_tmix == aRef.itsReadoutTime_tmix) ) return false;
   if ( ! (itsTmix_us == aRef.itsTmix_us) ) return false;

   return true;
}

inline bool IntegrationSet::operator < (const IntegrationSet & aRef) const
{
   if ( ! (itsFin_MHz < aRef.itsFin_MHz) ) return false;
   if ( ! (itsFout_MHz < aRef.itsFout_MHz) ) return false;
   if ( ! (itsFrameIdleTime_tmix < aRef.itsFrameIdleTime_tmix) ) return false;
   if ( ! (itsFrameRate_Hz < aRef.itsFrameRate_Hz) ) return false;
   if ( ! (itsIllPower_percent < aRef.itsIllPower_percent) ) return false;
   if ( ! (itsIntegrationTimePhase0_tmix < aRef.itsIntegrationTimePhase0_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase1_tmix < aRef.itsIntegrationTimePhase1_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase2_tmix < aRef.itsIntegrationTimePhase2_tmix) ) return false;
   if ( ! (itsIntegrationTimePhase3_tmix < aRef.itsIntegrationTimePhase3_tmix) ) return false;
   if ( ! (itsLaserPower_W < aRef.itsLaserPower_W) ) return false;
   if ( ! (itsMixhVoltage_V < aRef.itsMixhVoltage_V) ) return false;
   if ( ! (itsReadoutTime_tmix < aRef.itsReadoutTime_tmix) ) return false;
   if ( ! (itsTmix_us < aRef.itsTmix_us) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const IntegrationSet & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 IntegrationSet::GetFin_MHz( ) const
{
 return itsFin_MHz;
}

inline void IntegrationSet::SetFin_MHz( const uint2 & aValue )
{
 itsFin_MHz = aValue;
}

inline float IntegrationSet::GetFout_MHz( ) const
{
 return itsFout_MHz;
}

inline void IntegrationSet::SetFout_MHz( const float & aValue )
{
 itsFout_MHz = aValue;
}

inline uint4 IntegrationSet::GetFrameIdleTime_tmix( ) const
{
 return itsFrameIdleTime_tmix;
}

inline void IntegrationSet::SetFrameIdleTime_tmix( const uint4 & aValue )
{
 itsFrameIdleTime_tmix = aValue;
}

inline float IntegrationSet::GetFrameRate_Hz( ) const
{
 return itsFrameRate_Hz;
}

inline void IntegrationSet::SetFrameRate_Hz( const float & aValue )
{
 itsFrameRate_Hz = aValue;
}

inline uint2 IntegrationSet::GetIllPower_percent( ) const
{
 return itsIllPower_percent;
}

inline void IntegrationSet::SetIllPower_percent( const uint2 & aValue )
{
 itsIllPower_percent = aValue;
}

inline uint4 IntegrationSet::GetIntegrationTimePhase0_tmix( ) const
{
 return itsIntegrationTimePhase0_tmix;
}

inline void IntegrationSet::SetIntegrationTimePhase0_tmix( const uint4 & aValue )
{
 itsIntegrationTimePhase0_tmix = aValue;
}

inline uint4 IntegrationSet::GetIntegrationTimePhase1_tmix( ) const
{
 return itsIntegrationTimePhase1_tmix;
}

inline void IntegrationSet::SetIntegrationTimePhase1_tmix( const uint4 & aValue )
{
 itsIntegrationTimePhase1_tmix = aValue;
}

inline uint4 IntegrationSet::GetIntegrationTimePhase2_tmix( ) const
{
 return itsIntegrationTimePhase2_tmix;
}

inline void IntegrationSet::SetIntegrationTimePhase2_tmix( const uint4 & aValue )
{
 itsIntegrationTimePhase2_tmix = aValue;
}

inline uint4 IntegrationSet::GetIntegrationTimePhase3_tmix( ) const
{
 return itsIntegrationTimePhase3_tmix;
}

inline void IntegrationSet::SetIntegrationTimePhase3_tmix( const uint4 & aValue )
{
 itsIntegrationTimePhase3_tmix = aValue;
}

inline float IntegrationSet::GetLaserPower_W( ) const
{
 return itsLaserPower_W;
}

inline void IntegrationSet::SetLaserPower_W( const float & aValue )
{
 itsLaserPower_W = aValue;
}

inline float IntegrationSet::GetMixhVoltage_V( ) const
{
 return itsMixhVoltage_V;
}

inline void IntegrationSet::SetMixhVoltage_V( const float & aValue )
{
 itsMixhVoltage_V = aValue;
}

inline uint4 IntegrationSet::GetReadoutTime_tmix( ) const
{
 return itsReadoutTime_tmix;
}

inline void IntegrationSet::SetReadoutTime_tmix( const uint4 & aValue )
{
 itsReadoutTime_tmix = aValue;
}

inline float IntegrationSet::GetTmix_us( ) const
{
 return itsTmix_us;
}

inline void IntegrationSet::SetTmix_us( const float & aValue )
{
 itsTmix_us = aValue;
}






}; // End of namespace MLX75123

#endif

