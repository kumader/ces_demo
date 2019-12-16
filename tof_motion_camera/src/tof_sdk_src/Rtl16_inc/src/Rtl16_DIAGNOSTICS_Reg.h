///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DIAGNOSTICS_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class DIAGNOSTICS_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_DIAGNOSTICS_Reg_
#define _Rtl16_DIAGNOSTICS_Reg_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#ifdef _TARGET_ARCH_W32_
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

/// The definition of class DIAGNOSTICS_Reg
class DIAGNOSTICS_Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        DIAGNOSTICS_Reg( );

   /// Special Constructor 
        DIAGNOSTICS_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~DIAGNOSTICS_Reg( );

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
       bool operator == (const DIAGNOSTICS_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const DIAGNOSTICS_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0PLL_LOCK
         ///  The Get function for member 0PLL_LOCK
              uint2   GetPLL_LOCK( ) const;
         ///  The Set function for member 0PLL_LOCK
              void    SetPLL_LOCK( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11DED_LATCH
         ///  The Get function for member 11DED_LATCH
              uint2   GetDED_LATCH( ) const;
         ///  The Set function for member 11DED_LATCH
              void    SetDED_LATCH( const uint2 & aValue );
         //----------------------------------------------------
         // The member 12SEC_LATCH
         ///  The Get function for member 12SEC_LATCH
              uint2   GetSEC_LATCH( ) const;
         ///  The Set function for member 12SEC_LATCH
              void    SetSEC_LATCH( const uint2 & aValue );
         //----------------------------------------------------
         // The member 13DED_ERROR
         ///  The Get function for member 13DED_ERROR
              uint2   GetDED_ERROR( ) const;
         ///  The Set function for member 13DED_ERROR
              void    SetDED_ERROR( const uint2 & aValue );
         //----------------------------------------------------
         // The member 14SEC_ERROR
         ///  The Get function for member 14SEC_ERROR
              uint2   GetSEC_ERROR( ) const;
         ///  The Set function for member 14SEC_ERROR
              void    SetSEC_ERROR( const uint2 & aValue );
         //----------------------------------------------------
         // The member 15ROI_ERROR
         ///  The Get function for member 15ROI_ERROR
              uint2   GetROI_ERROR( ) const;
         ///  The Set function for member 15ROI_ERROR
              void    SetROI_ERROR( const uint2 & aValue );
         //----------------------------------------------------
         // The member 23V3_READY
         ///  The Get function for member 23V3_READY
              uint2   GetV3_READY( ) const;
         ///  The Set function for member 23V3_READY
              void    SetV3_READY( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0PLL_LOCK: 1;
         uint2 its1Reserved: 1;
         uint2 its3Reserved: 1;
         uint2 its4Reserved: 1;
         uint2 its5Reserved: 1;
         uint2 its6Reserved: 1;
         uint2 its7Reserved: 1;
         uint2 its8Reserved: 1;
         uint2 its9Reserved: 1;
         uint2 its10Reserved: 1;
         uint2 its11DED_LATCH: 1;
         uint2 its12SEC_LATCH: 1;
         uint2 its13DED_ERROR: 1;
         uint2 its14SEC_ERROR: 1;
         uint2 its15ROI_ERROR: 1;
         uint2 its23V3_READY: 1;

};
};

}; // End of class DIAGNOSTICS_Reg

//------------------------------ Inline Functions ----------------------
inline bool DIAGNOSTICS_Reg::operator == (const DIAGNOSTICS_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool DIAGNOSTICS_Reg::operator < (const DIAGNOSTICS_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const DIAGNOSTICS_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 DIAGNOSTICS_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void DIAGNOSTICS_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetPLL_LOCK( ) const
{
 return its0PLL_LOCK;
}

inline void DIAGNOSTICS_Reg::SetPLL_LOCK( const uint2 & aValue )
{
 its0PLL_LOCK = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void DIAGNOSTICS_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetDED_LATCH( ) const
{
 return its11DED_LATCH;
}

inline void DIAGNOSTICS_Reg::SetDED_LATCH( const uint2 & aValue )
{
 its11DED_LATCH = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetSEC_LATCH( ) const
{
 return its12SEC_LATCH;
}

inline void DIAGNOSTICS_Reg::SetSEC_LATCH( const uint2 & aValue )
{
 its12SEC_LATCH = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetDED_ERROR( ) const
{
 return its13DED_ERROR;
}

inline void DIAGNOSTICS_Reg::SetDED_ERROR( const uint2 & aValue )
{
 its13DED_ERROR = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetSEC_ERROR( ) const
{
 return its14SEC_ERROR;
}

inline void DIAGNOSTICS_Reg::SetSEC_ERROR( const uint2 & aValue )
{
 its14SEC_ERROR = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetROI_ERROR( ) const
{
 return its15ROI_ERROR;
}

inline void DIAGNOSTICS_Reg::SetROI_ERROR( const uint2 & aValue )
{
 its15ROI_ERROR = aValue;
}

inline uint2 DIAGNOSTICS_Reg::GetV3_READY( ) const
{
 return its23V3_READY;
}

inline void DIAGNOSTICS_Reg::SetV3_READY( const uint2 & aValue )
{
 its23V3_READY = aValue;
}







}; // End of namespace Rtl16

#endif

