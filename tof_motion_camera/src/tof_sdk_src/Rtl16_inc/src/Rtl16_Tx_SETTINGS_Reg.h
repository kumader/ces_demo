///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Tx_SETTINGS_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Tx_SETTINGS_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Tx_SETTINGS_Reg_
#define _Rtl16_Tx_SETTINGS_Reg_

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

/// The definition of class Tx_SETTINGS_Reg
class Tx_SETTINGS_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          T1_SETTINGS = 0x1012
         , T2_SETTINGS = 0x1094 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Tx_SETTINGS_Reg( );

   /// Special Constructor 
        Tx_SETTINGS_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Tx_SETTINGS_Reg( );

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
       bool operator == (const Tx_SETTINGS_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Tx_SETTINGS_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Tx_PHASE_COUNT
         ///  The Get function for member 0Tx_PHASE_COUNT
              uint2   GetTx_PHASE_COUNT( ) const;
         ///  The Set function for member 0Tx_PHASE_COUNT
              void    SetTx_PHASE_COUNT( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4Tx_QUIET
         ///  The Get function for member 4Tx_QUIET
              uint2   GetTx_QUIET( ) const;
         ///  The Set function for member 4Tx_QUIET
              void    SetTx_QUIET( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6Tx_FLIP_MIRROR
         ///  The Get function for member 6Tx_FLIP_MIRROR
              uint2   GetTx_FLIP_MIRROR( ) const;
         ///  The Set function for member 6Tx_FLIP_MIRROR
              void    SetTx_FLIP_MIRROR( const uint2 & aValue );
         //----------------------------------------------------
         // The member 10Tx_EN_META1
         ///  The Get function for member 10Tx_EN_META1
              uint2   GetTx_EN_META1( ) const;
         ///  The Set function for member 10Tx_EN_META1
              void    SetTx_EN_META1( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11Tx_EN_META2
         ///  The Get function for member 11Tx_EN_META2
              uint2   GetTx_EN_META2( ) const;
         ///  The Set function for member 11Tx_EN_META2
              void    SetTx_EN_META2( const uint2 & aValue );
         //----------------------------------------------------
         // The member 13Tx_EN_TEST_ROW
         ///  The Get function for member 13Tx_EN_TEST_ROW
              uint2   GetTx_EN_TEST_ROW( ) const;
         ///  The Set function for member 13Tx_EN_TEST_ROW
              void    SetTx_EN_TEST_ROW( const uint2 & aValue );
         //----------------------------------------------------
         // The member 14Tx_EN_TEST_ADC
         ///  The Get function for member 14Tx_EN_TEST_ADC
              uint2   GetTx_EN_TEST_ADC( ) const;
         ///  The Set function for member 14Tx_EN_TEST_ADC
              void    SetTx_EN_TEST_ADC( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Tx_PHASE_COUNT: 3;
         uint2 its3Reserved: 1;
         uint2 its4Tx_QUIET: 2;
         uint2 its6Tx_FLIP_MIRROR: 2;
         uint2 its8Reserved: 1;
         uint2 its9Reserved: 1;
         uint2 its10Tx_EN_META1: 1;
         uint2 its11Tx_EN_META2: 1;
         uint2 its12Reserved: 1;
         uint2 its13Tx_EN_TEST_ROW: 1;
         uint2 its14Tx_EN_TEST_ADC: 1;
         uint2 its15Reserved: 1;

};
};

}; // End of class Tx_SETTINGS_Reg

//------------------------------ Inline Functions ----------------------
inline bool Tx_SETTINGS_Reg::operator == (const Tx_SETTINGS_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Tx_SETTINGS_Reg::operator < (const Tx_SETTINGS_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Tx_SETTINGS_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Tx_SETTINGS_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Tx_SETTINGS_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Tx_SETTINGS_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_PHASE_COUNT( ) const
{
 return its0Tx_PHASE_COUNT;
}

inline void Tx_SETTINGS_Reg::SetTx_PHASE_COUNT( const uint2 & aValue )
{
 its0Tx_PHASE_COUNT = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_QUIET( ) const
{
 return its4Tx_QUIET;
}

inline void Tx_SETTINGS_Reg::SetTx_QUIET( const uint2 & aValue )
{
 its4Tx_QUIET = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_FLIP_MIRROR( ) const
{
 return its6Tx_FLIP_MIRROR;
}

inline void Tx_SETTINGS_Reg::SetTx_FLIP_MIRROR( const uint2 & aValue )
{
 its6Tx_FLIP_MIRROR = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_EN_META1( ) const
{
 return its10Tx_EN_META1;
}

inline void Tx_SETTINGS_Reg::SetTx_EN_META1( const uint2 & aValue )
{
 its10Tx_EN_META1 = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_EN_META2( ) const
{
 return its11Tx_EN_META2;
}

inline void Tx_SETTINGS_Reg::SetTx_EN_META2( const uint2 & aValue )
{
 its11Tx_EN_META2 = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_EN_TEST_ROW( ) const
{
 return its13Tx_EN_TEST_ROW;
}

inline void Tx_SETTINGS_Reg::SetTx_EN_TEST_ROW( const uint2 & aValue )
{
 its13Tx_EN_TEST_ROW = aValue;
}

inline uint2 Tx_SETTINGS_Reg::GetTx_EN_TEST_ADC( ) const
{
 return its14Tx_EN_TEST_ADC;
}

inline void Tx_SETTINGS_Reg::SetTx_EN_TEST_ADC( const uint2 & aValue )
{
 its14Tx_EN_TEST_ADC = aValue;
}







}; // End of namespace Rtl16

#endif

