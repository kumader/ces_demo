///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Tx_IDLETIMEy_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Tx_IDLETIMEy_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Tx_IDLETIMEy_Reg_
#define _Rtl16_Tx_IDLETIMEy_Reg_

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

/// The definition of class Tx_IDLETIMEy_Reg
class Tx_IDLETIMEy_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          T1_IDLETIME0 = 0x1014
         , T1_IDLETIME1 = 0x1016
         , T2_IDLETIME0 = 0x1096
         , T2_IDLETIME1 = 0x1098 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Tx_IDLETIMEy_Reg( );

   /// Special Constructor 
        Tx_IDLETIMEy_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Tx_IDLETIMEy_Reg( );

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
       bool operator == (const Tx_IDLETIMEy_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Tx_IDLETIMEy_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0IDLETIME_tmix
         ///  The Get function for member 0IDLETIME_tmix
              uint2   GetIDLETIME_tmix( ) const;
         ///  The Set function for member 0IDLETIME_tmix
              void    SetIDLETIME_tmix( const uint2 & aValue );
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
         uint2 its0IDLETIME_tmix: 16;

};
};

}; // End of class Tx_IDLETIMEy_Reg

//------------------------------ Inline Functions ----------------------
inline bool Tx_IDLETIMEy_Reg::operator == (const Tx_IDLETIMEy_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Tx_IDLETIMEy_Reg::operator < (const Tx_IDLETIMEy_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Tx_IDLETIMEy_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Tx_IDLETIMEy_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Tx_IDLETIMEy_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Tx_IDLETIMEy_Reg::GetIDLETIME_tmix( ) const
{
 return its0IDLETIME_tmix;
}

inline void Tx_IDLETIMEy_Reg::SetIDLETIME_tmix( const uint2 & aValue )
{
 its0IDLETIME_tmix = aValue;
}

inline uint2 Tx_IDLETIMEy_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Tx_IDLETIMEy_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}







}; // End of namespace Rtl16

#endif

