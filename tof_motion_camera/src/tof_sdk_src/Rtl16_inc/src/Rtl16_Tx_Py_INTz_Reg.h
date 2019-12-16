///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Tx_Py_INTz_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Tx_Py_INTz_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Tx_Py_INTz_Reg_
#define _Rtl16_Tx_Py_INTz_Reg_

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

/// The definition of class Tx_Py_INTz_Reg
class Tx_Py_INTz_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          T1_P0_INT0 = 0x1026
         , T1_P0_INT1 = 0x1028
         , T1_P1_INT0 = 0x1034
         , T1_P1_INT1 = 0x1036
         , T1_P2_INT0 = 0x1042
         , T1_P2_INT1 = 0x1044
         , T1_P3_INT0 = 0x1050
         , T1_P3_INT1 = 0x1052
         , T2_P0_INT0 = 0x10a8
         , T2_P0_INT1 = 0x10aa
         , T2_P1_INT0 = 0x10b6
         , T2_P1_INT1 = 0x10b8
         , T2_P2_INT0 = 0x10c4
         , T2_P2_INT1 = 0x10c6
         , T2_P3_INT0 = 0x10d2
         , T2_P3_INT1 = 0x10d4 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Tx_Py_INTz_Reg( );

   /// Special Constructor 
        Tx_Py_INTz_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Tx_Py_INTz_Reg( );

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
       bool operator == (const Tx_Py_INTz_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Tx_Py_INTz_Reg & aRef) const;

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
         // The member 0Tx_Py_INTz_tmix
         ///  The Get function for member 0Tx_Py_INTz_tmix
              uint2   GetTx_Py_INTz_tmix( ) const;
         ///  The Set function for member 0Tx_Py_INTz_tmix
              void    SetTx_Py_INTz_tmix( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Tx_Py_INTz_tmix: 16;

};
};

}; // End of class Tx_Py_INTz_Reg

//------------------------------ Inline Functions ----------------------
inline bool Tx_Py_INTz_Reg::operator == (const Tx_Py_INTz_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Tx_Py_INTz_Reg::operator < (const Tx_Py_INTz_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Tx_Py_INTz_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Tx_Py_INTz_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Tx_Py_INTz_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Tx_Py_INTz_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Tx_Py_INTz_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Tx_Py_INTz_Reg::GetTx_Py_INTz_tmix( ) const
{
 return its0Tx_Py_INTz_tmix;
}

inline void Tx_Py_INTz_Reg::SetTx_Py_INTz_tmix( const uint2 & aValue )
{
 its0Tx_Py_INTz_tmix = aValue;
}







}; // End of namespace Rtl16

#endif

