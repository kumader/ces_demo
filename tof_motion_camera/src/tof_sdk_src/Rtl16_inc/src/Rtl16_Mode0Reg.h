///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Mode0Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Mode0Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Mode0Reg_
#define _Rtl16_Mode0Reg_

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

/// The definition of class Mode0Reg
class Mode0Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Mode0Reg( );

   /// Special Constructor 
        Mode0Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Mode0Reg( );

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
       bool operator == (const Mode0Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Mode0Reg & aRef) const;

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
         // The member 4ManualTrigger
         ///  The Get function for member 4ManualTrigger
              uint2   GetManualTrigger( ) const;
         ///  The Set function for member 4ManualTrigger
              void    SetManualTrigger( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6ClearStatusErrorBits
         ///  The Get function for member 6ClearStatusErrorBits
              uint2   GetClearStatusErrorBits( ) const;
         ///  The Set function for member 6ClearStatusErrorBits
              void    SetClearStatusErrorBits( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0Reserved: 1;
         uint2 its1Reserved: 1;
         uint2 its2Reserved: 1;
         uint2 its3Reserved: 1;
         uint2 its4ManualTrigger: 1;
         uint2 its5Reserved: 1;
         uint2 its6ClearStatusErrorBits: 1;

};
};

}; // End of class Mode0Reg

//------------------------------ Inline Functions ----------------------
inline bool Mode0Reg::operator == (const Mode0Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Mode0Reg::operator < (const Mode0Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Mode0Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Mode0Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Mode0Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Mode0Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Mode0Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Mode0Reg::GetManualTrigger( ) const
{
 return its4ManualTrigger;
}

inline void Mode0Reg::SetManualTrigger( const uint2 & aValue )
{
 its4ManualTrigger = aValue;
}

inline uint2 Mode0Reg::GetClearStatusErrorBits( ) const
{
 return its6ClearStatusErrorBits;
}

inline void Mode0Reg::SetClearStatusErrorBits( const uint2 & aValue )
{
 its6ClearStatusErrorBits = aValue;
}







}; // End of namespace Rtl16

#endif

