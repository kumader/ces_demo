///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CmdEnablePasswdReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CmdEnablePasswdReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CmdEnablePasswdReg_
#define _Rtl16_CmdEnablePasswdReg_

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

/// The definition of class CmdEnablePasswdReg
class CmdEnablePasswdReg: public Virtual16BitReg
{
public:

   //enums

          enum Password_e
          {
          REGISTERMAP_FLASH_OPERATIONS = 0x4877
         , TEST_COMMAND = 0x5e6b 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CmdEnablePasswdReg( );

   /// Special Constructor 
        CmdEnablePasswdReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CmdEnablePasswdReg( );

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
       bool operator == (const CmdEnablePasswdReg & aRef) const;
   
   /// Less operator 
       bool operator < (const CmdEnablePasswdReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0PasswordForCriticalOperations
         ///  The Get function for member 0PasswordForCriticalOperations
              uint2   GetPasswordForCriticalOperations( ) const;
         ///  The Set function for member 0PasswordForCriticalOperations
              void    SetPasswordForCriticalOperations( const uint2 & aValue );
         ///  The ConvertToString function for member 0PasswordForCriticalOperations
              std::string    ConvertToStringPasswordForCriticalOperations( ) const;
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
         uint2 its0PasswordForCriticalOperations: 16;

};
};

}; // End of class CmdEnablePasswdReg

//------------------------------ Inline Functions ----------------------
inline bool CmdEnablePasswdReg::operator == (const CmdEnablePasswdReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CmdEnablePasswdReg::operator < (const CmdEnablePasswdReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CmdEnablePasswdReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CmdEnablePasswdReg::GetAddr( ) const
{
 return its0Addr;
}

inline void CmdEnablePasswdReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CmdEnablePasswdReg::GetPasswordForCriticalOperations( ) const
{
 return its0PasswordForCriticalOperations;
}

inline void CmdEnablePasswdReg::SetPasswordForCriticalOperations( const uint2 & aValue )
{
 its0PasswordForCriticalOperations = aValue;
}

inline uint2 CmdEnablePasswdReg::GetReg( ) const
{
 return its0Reg;
}

inline void CmdEnablePasswdReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string CmdEnablePasswdReg::ConvertToStringPasswordForCriticalOperations( ) const
{
 switch (its0PasswordForCriticalOperations)
 {
 case 0x5e6b: return "Test commands"; break;
 case 0x4877: return "Register map flash operations"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

