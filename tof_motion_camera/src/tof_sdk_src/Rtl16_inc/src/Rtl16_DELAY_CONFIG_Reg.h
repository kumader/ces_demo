///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DELAY_CONFIG_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class DELAY_CONFIG_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_DELAY_CONFIG_Reg_
#define _Rtl16_DELAY_CONFIG_Reg_

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

/// The definition of class DELAY_CONFIG_Reg
class DELAY_CONFIG_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          DELAY_CONFIG = 0x1116 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        DELAY_CONFIG_Reg( );

   /// Special Constructor 
        DELAY_CONFIG_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~DELAY_CONFIG_Reg( );

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
       bool operator == (const DELAY_CONFIG_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const DELAY_CONFIG_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0DELAY_LINE_ADDRESS
         ///  The Get function for member 0DELAY_LINE_ADDRESS
              uint2   GetDELAY_LINE_ADDRESS( ) const;
         ///  The Set function for member 0DELAY_LINE_ADDRESS
              void    SetDELAY_LINE_ADDRESS( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8DELAY_LINE_ADC
         ///  The Get function for member 8DELAY_LINE_ADC
              uint2   GetDELAY_LINE_ADC( ) const;
         ///  The Set function for member 8DELAY_LINE_ADC
              void    SetDELAY_LINE_ADC( const uint2 & aValue );
         //----------------------------------------------------
         // The member 10ADC_LATENCY
         ///  The Get function for member 10ADC_LATENCY
              uint2   GetADC_LATENCY( ) const;
         ///  The Set function for member 10ADC_LATENCY
              void    SetADC_LATENCY( const uint2 & aValue );
         //----------------------------------------------------
         // The member 15MOD_INV
         ///  The Get function for member 15MOD_INV
              uint2   GetMOD_INV( ) const;
         ///  The Set function for member 15MOD_INV
              void    SetMOD_INV( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0DELAY_LINE_ADDRESS: 8;
         uint2 its8DELAY_LINE_ADC: 2;
         uint2 its10ADC_LATENCY: 5;
         uint2 its15MOD_INV: 1;

};
};

}; // End of class DELAY_CONFIG_Reg

//------------------------------ Inline Functions ----------------------
inline bool DELAY_CONFIG_Reg::operator == (const DELAY_CONFIG_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool DELAY_CONFIG_Reg::operator < (const DELAY_CONFIG_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const DELAY_CONFIG_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 DELAY_CONFIG_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void DELAY_CONFIG_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 DELAY_CONFIG_Reg::GetDELAY_LINE_ADDRESS( ) const
{
 return its0DELAY_LINE_ADDRESS;
}

inline void DELAY_CONFIG_Reg::SetDELAY_LINE_ADDRESS( const uint2 & aValue )
{
 its0DELAY_LINE_ADDRESS = aValue;
}

inline uint2 DELAY_CONFIG_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void DELAY_CONFIG_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 DELAY_CONFIG_Reg::GetDELAY_LINE_ADC( ) const
{
 return its8DELAY_LINE_ADC;
}

inline void DELAY_CONFIG_Reg::SetDELAY_LINE_ADC( const uint2 & aValue )
{
 its8DELAY_LINE_ADC = aValue;
}

inline uint2 DELAY_CONFIG_Reg::GetADC_LATENCY( ) const
{
 return its10ADC_LATENCY;
}

inline void DELAY_CONFIG_Reg::SetADC_LATENCY( const uint2 & aValue )
{
 its10ADC_LATENCY = aValue;
}

inline uint2 DELAY_CONFIG_Reg::GetMOD_INV( ) const
{
 return its15MOD_INV;
}

inline void DELAY_CONFIG_Reg::SetMOD_INV( const uint2 & aValue )
{
 its15MOD_INV = aValue;
}







}; // End of namespace Rtl16

#endif

