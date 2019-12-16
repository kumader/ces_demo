///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CmdExecReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class CmdExecReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_CmdExecReg_
#define _Rtl16_CmdExecReg_

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

/// The definition of class CmdExecReg
class CmdExecReg: public Virtual16BitReg
{
public:

   //enums

          enum Operation_e
          {
          READ_FACTORY_REGMAP = 0x909a
         , READ_REGMAP_FLASH = 0x9e20
         , CLEAR_REGMAP_FLASH = 0xc2ae
         , SAVE_REGMAP_FLASH = 0xdd9e 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        CmdExecReg( );

   /// Special Constructor 
        CmdExecReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~CmdExecReg( );

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
       bool operator == (const CmdExecReg & aRef) const;
   
   /// Less operator 
       bool operator < (const CmdExecReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0InitiateAnOperation
         ///  The Get function for member 0InitiateAnOperation
              uint2   GetInitiateAnOperation( ) const;
         ///  The Set function for member 0InitiateAnOperation
              void    SetInitiateAnOperation( const uint2 & aValue );
         ///  The ConvertToString function for member 0InitiateAnOperation
              std::string    ConvertToStringInitiateAnOperation( ) const;
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
         uint2 its0InitiateAnOperation: 16;

};
};

}; // End of class CmdExecReg

//------------------------------ Inline Functions ----------------------
inline bool CmdExecReg::operator == (const CmdExecReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool CmdExecReg::operator < (const CmdExecReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const CmdExecReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 CmdExecReg::GetAddr( ) const
{
 return its0Addr;
}

inline void CmdExecReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 CmdExecReg::GetInitiateAnOperation( ) const
{
 return its0InitiateAnOperation;
}

inline void CmdExecReg::SetInitiateAnOperation( const uint2 & aValue )
{
 its0InitiateAnOperation = aValue;
}

inline uint2 CmdExecReg::GetReg( ) const
{
 return its0Reg;
}

inline void CmdExecReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}




inline std::string CmdExecReg::ConvertToStringInitiateAnOperation( ) const
{
 switch (its0InitiateAnOperation)
 {
 case 0xdd9e: return "Save RegMap in flash"; break;
 case 0xc2ae: return "Clear RegMap in Flash"; break;
 case 0x9e20: return "Read RegMap from flash"; break;
 case 0x909a: return "Read factory RegMap"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

