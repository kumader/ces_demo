///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- MixhVoltageReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class MixhVoltageReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_MixhVoltageReg_
#define _Rtl16_MixhVoltageReg_

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

/// The definition of class MixhVoltageReg
class MixhVoltageReg: public Virtual16BitReg
{
public:

   //enums

          enum Voltage_e
          {
          VOLT_0_9 = 9
         , VOLT_1_0 = 10
         , VOLT_1_1 = 11
         , VOLT_1_2 = 12
         , VOLT_1_3 = 13
         , VOLT_1_4 = 14
         , VOLT_1_5 = 15
         , VOLT_1_6 = 16
         , VOLT_1_7 = 17
         , VOLT_1_8 = 18
         , VOLT_1_9 = 19
         , VOLT_2_0 = 20
         , VOLT_2_1 = 21
         , VOLT_2_2 = 22 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        MixhVoltageReg( );

   /// Special Constructor 
        MixhVoltageReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~MixhVoltageReg( );

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
       bool operator == (const MixhVoltageReg & aRef) const;
   
   /// Less operator 
       bool operator < (const MixhVoltageReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0MixhVoltage_V10
         ///  The Get function for member 0MixhVoltage_V10
              uint2   GetMixhVoltage_V10( ) const;
         ///  The Set function for member 0MixhVoltage_V10
              void    SetMixhVoltage_V10( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0MixhVoltage_V10: 16;

};
};

}; // End of class MixhVoltageReg

//------------------------------ Inline Functions ----------------------
inline bool MixhVoltageReg::operator == (const MixhVoltageReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool MixhVoltageReg::operator < (const MixhVoltageReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const MixhVoltageReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 MixhVoltageReg::GetAddr( ) const
{
 return its0Addr;
}

inline void MixhVoltageReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 MixhVoltageReg::GetMixhVoltage_V10( ) const
{
 return its0MixhVoltage_V10;
}

inline void MixhVoltageReg::SetMixhVoltage_V10( const uint2 & aValue )
{
 its0MixhVoltage_V10 = aValue;
}

inline uint2 MixhVoltageReg::GetReg( ) const
{
 return its0Reg;
}

inline void MixhVoltageReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

