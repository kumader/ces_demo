///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CmdExecResultReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CmdExecResultReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CmdExecResultReg_
#define _Rtl16_CmdExecResultReg_

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

/// The definition of class CmdExecResultReg
class CmdExecResultReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CmdExecResultReg( );

   /// Special Constructor 
        CmdExecResultReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CmdExecResultReg( );

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
       bool operator == (const CmdExecResultReg & aRef) const;
   
   /// Less operator 
       bool operator < (const CmdExecResultReg & aRef) const;

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
         // The member 0ResultCode
         ///  The Get function for member 0ResultCode
              uint2   GetResultCode( ) const;
         ///  The Set function for member 0ResultCode
              void    SetResultCode( const uint2 & aValue );
         ///  The ConvertToString function for member 0ResultCode
              std::string    ConvertToStringResultCode( ) const;

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0ResultCode: 16;

};
};

}; // End of class CmdExecResultReg

//------------------------------ Inline Functions ----------------------
inline bool CmdExecResultReg::operator == (const CmdExecResultReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CmdExecResultReg::operator < (const CmdExecResultReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CmdExecResultReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CmdExecResultReg::GetAddr( ) const
{
 return its0Addr;
}

inline void CmdExecResultReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CmdExecResultReg::GetReg( ) const
{
 return its0Reg;
}

inline void CmdExecResultReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 CmdExecResultReg::GetResultCode( ) const
{
 return its0ResultCode;
}

inline void CmdExecResultReg::SetResultCode( const uint2 & aValue )
{
 its0ResultCode = aValue;
}




inline std::string CmdExecResultReg::ConvertToStringResultCode( ) const
{
 switch (its0ResultCode)
 {
 case 1: return "1:Success"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

