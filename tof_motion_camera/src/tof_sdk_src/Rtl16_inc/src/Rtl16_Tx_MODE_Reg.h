///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Tx_MODE_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Tx_MODE_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Tx_MODE_Reg_
#define _Rtl16_Tx_MODE_Reg_

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

/// The definition of class Tx_MODE_Reg
class Tx_MODE_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Fout_MHz_e
          {
          FIN48_FOUT24_0 = (48<<8) | (3<<4) | 3
         , FIN48_FOUT18_0 = (48<<8) | (3<<4) | 4
         , FIN48_FOUT14_4 = (48<<8) | (3<<4) | 5
         , FIN48_FOUT12_0 = (48<<8) | (3<<4) | 6
         , FIN48_FOUT32_0 = (48<<8) | (4<<4) | 3
         , FIN48_FOUT19_2 = (48<<8) | (4<<4) | 5
         , FIN48_FOUT16_0 = (48<<8) | (4<<4) | 6
         , FIN48_FOUT13_7 = (48<<8) | (4<<4) | 7
         , FIN48_FOUT40_0 = (48<<8) | (5<<4) | 3
         , FIN48_FOUT30_0 = (48<<8) | (5<<4) | 4
         , FIN48_FOUT20_0 = (48<<8) | (5<<4) | 6
         , FIN48_FOUT17_1 = (48<<8) | (5<<4) | 7
         , FIN48_FOUT15_0 = (48<<8) | (5<<4) | 8
         , FIN48_FOUT13_3 = (48<<8) | (5<<4) | 9
         , FIN48_FOUT36_0 = (48<<8) | (6<<4) | 4
         , FIN48_FOUT28_8 = (48<<8) | (6<<4) | 5
         , FIN48_FOUT20_5 = (48<<8) | (6<<4) | 7
         , FIN48_FOUT33_6 = (48<<8) | (7<<4) | 5
         , FIN48_FOUT28_0 = (48<<8) | (7<<4) | 6
         , FIN48_FOUT38_4 = (48<<8) | (8<<4) | 5
         , FIN48_FOUT27_4 = (48<<8) | (8<<4) | 7
         , FIN48_FOUT21_3 = (48<<8) | (8<<4) | 9
         , FIN48_FOUT30_8 = (48<<8) | (9<<4) | 7
         , FIN48_FOUT27_0 = (48<<8) | (9<<4) | 8 
          };


          enum Register_e
          {
          T1_MODE = 0x1018
         , T2_MODE = 0x109a 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Tx_MODE_Reg( );

   /// Special Constructor 
        Tx_MODE_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Tx_MODE_Reg( );

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
       bool operator == (const Tx_MODE_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Tx_MODE_Reg & aRef) const;

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
         // The member 0Tx_TRIGGER
         ///  The Get function for member 0Tx_TRIGGER
              uint2   GetTx_TRIGGER( ) const;
         ///  The Set function for member 0Tx_TRIGGER
              void    SetTx_TRIGGER( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2Tx_FSYNC
         ///  The Get function for member 2Tx_FSYNC
              uint2   GetTx_FSYNC( ) const;
         ///  The Set function for member 2Tx_FSYNC
              void    SetTx_FSYNC( const uint2 & aValue );
         //----------------------------------------------------
         // The member 3Tx_PIXCLK
         ///  The Get function for member 3Tx_PIXCLK
              uint2   GetTx_PIXCLK( ) const;
         ///  The Set function for member 3Tx_PIXCLK
              void    SetTx_PIXCLK( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4Tx_HSYNC
         ///  The Get function for member 4Tx_HSYNC
              uint2   GetTx_HSYNC( ) const;
         ///  The Set function for member 4Tx_HSYNC
              void    SetTx_HSYNC( const uint2 & aValue );
         //----------------------------------------------------
         // The member 5Tx_VSYNC
         ///  The Get function for member 5Tx_VSYNC
              uint2   GetTx_VSYNC( ) const;
         ///  The Set function for member 5Tx_VSYNC
              void    SetTx_VSYNC( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6Tx_NDIV
         ///  The Get function for member 6Tx_NDIV
              uint2   GetTx_NDIV( ) const;
         ///  The Set function for member 6Tx_NDIV
              void    SetTx_NDIV( const uint2 & aValue );
         //----------------------------------------------------
         // The member 9Tx_RDIV
         ///  The Get function for member 9Tx_RDIV
              uint2   GetTx_RDIV( ) const;
         ///  The Set function for member 9Tx_RDIV
              void    SetTx_RDIV( const uint2 & aValue );
         //----------------------------------------------------
         // The member 13Tx_MOD_DUTY_CYCLE
         ///  The Get function for member 13Tx_MOD_DUTY_CYCLE
              uint2   GetTx_MOD_DUTY_CYCLE( ) const;
         ///  The Set function for member 13Tx_MOD_DUTY_CYCLE
              void    SetTx_MOD_DUTY_CYCLE( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Tx_TRIGGER: 2;
         uint2 its2Tx_FSYNC: 1;
         uint2 its3Tx_PIXCLK: 1;
         uint2 its4Tx_HSYNC: 1;
         uint2 its5Tx_VSYNC: 1;
         uint2 its6Tx_NDIV: 3;
         uint2 its9Tx_RDIV: 3;
         uint2 its12Reserved: 1;
         uint2 its13Tx_MOD_DUTY_CYCLE: 3;

};
};

}; // End of class Tx_MODE_Reg

//------------------------------ Inline Functions ----------------------
inline bool Tx_MODE_Reg::operator == (const Tx_MODE_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Tx_MODE_Reg::operator < (const Tx_MODE_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Tx_MODE_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Tx_MODE_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Tx_MODE_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Tx_MODE_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Tx_MODE_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_TRIGGER( ) const
{
 return its0Tx_TRIGGER;
}

inline void Tx_MODE_Reg::SetTx_TRIGGER( const uint2 & aValue )
{
 its0Tx_TRIGGER = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_FSYNC( ) const
{
 return its2Tx_FSYNC;
}

inline void Tx_MODE_Reg::SetTx_FSYNC( const uint2 & aValue )
{
 its2Tx_FSYNC = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_PIXCLK( ) const
{
 return its3Tx_PIXCLK;
}

inline void Tx_MODE_Reg::SetTx_PIXCLK( const uint2 & aValue )
{
 its3Tx_PIXCLK = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_HSYNC( ) const
{
 return its4Tx_HSYNC;
}

inline void Tx_MODE_Reg::SetTx_HSYNC( const uint2 & aValue )
{
 its4Tx_HSYNC = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_VSYNC( ) const
{
 return its5Tx_VSYNC;
}

inline void Tx_MODE_Reg::SetTx_VSYNC( const uint2 & aValue )
{
 its5Tx_VSYNC = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_NDIV( ) const
{
 return its6Tx_NDIV;
}

inline void Tx_MODE_Reg::SetTx_NDIV( const uint2 & aValue )
{
 its6Tx_NDIV = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_RDIV( ) const
{
 return its9Tx_RDIV;
}

inline void Tx_MODE_Reg::SetTx_RDIV( const uint2 & aValue )
{
 its9Tx_RDIV = aValue;
}

inline uint2 Tx_MODE_Reg::GetTx_MOD_DUTY_CYCLE( ) const
{
 return its13Tx_MOD_DUTY_CYCLE;
}

inline void Tx_MODE_Reg::SetTx_MOD_DUTY_CYCLE( const uint2 & aValue )
{
 its13Tx_MOD_DUTY_CYCLE = aValue;
}







}; // End of namespace Rtl16

#endif

