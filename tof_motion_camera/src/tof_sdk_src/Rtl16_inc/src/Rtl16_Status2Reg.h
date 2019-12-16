///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- Status2Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class Status2Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_Status2Reg_
#define _Rtl16_Status2Reg_

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

/// The definition of class Status2Reg
class Status2Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        Status2Reg( );

   /// Special Constructor 
        Status2Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~Status2Reg( );

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
       bool operator == (const Status2Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const Status2Reg & aRef) const;

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
         // The member 0SerdesError
         ///  The Get function for member 0SerdesError
              uint2   GetSerdesError( ) const;
         ///  The Set function for member 0SerdesError
              void    SetSerdesError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 1CaptureError
         ///  The Get function for member 1CaptureError
              uint2   GetCaptureError( ) const;
         ///  The Set function for member 1CaptureError
              void    SetCaptureError( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2CaptureTimeout
         ///  The Get function for member 2CaptureTimeout
              uint2   GetCaptureTimeout( ) const;
         ///  The Set function for member 2CaptureTimeout
              void    SetCaptureTimeout( const uint2 & aValue );
         //----------------------------------------------------
         // The member 3ApplicationProcessorTooHot
         ///  The Get function for member 3ApplicationProcessorTooHot
              uint2   GetApplicationProcessorTooHot( ) const;
         ///  The Set function for member 3ApplicationProcessorTooHot
              void    SetApplicationProcessorTooHot( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0SerdesError: 1;
         uint2 its1CaptureError: 1;
         uint2 its2CaptureTimeout: 1;
         uint2 its3ApplicationProcessorTooHot: 1;

};
};

}; // End of class Status2Reg

//------------------------------ Inline Functions ----------------------
inline bool Status2Reg::operator == (const Status2Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool Status2Reg::operator < (const Status2Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const Status2Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 Status2Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void Status2Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 Status2Reg::GetReg( ) const
{
 return its0Reg;
}

inline void Status2Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 Status2Reg::GetSerdesError( ) const
{
 return its0SerdesError;
}

inline void Status2Reg::SetSerdesError( const uint2 & aValue )
{
 its0SerdesError = aValue;
}

inline uint2 Status2Reg::GetCaptureError( ) const
{
 return its1CaptureError;
}

inline void Status2Reg::SetCaptureError( const uint2 & aValue )
{
 its1CaptureError = aValue;
}

inline uint2 Status2Reg::GetCaptureTimeout( ) const
{
 return its2CaptureTimeout;
}

inline void Status2Reg::SetCaptureTimeout( const uint2 & aValue )
{
 its2CaptureTimeout = aValue;
}

inline uint2 Status2Reg::GetApplicationProcessorTooHot( ) const
{
 return its3ApplicationProcessorTooHot;
}

inline void Status2Reg::SetApplicationProcessorTooHot( const uint2 & aValue )
{
 its3ApplicationProcessorTooHot = aValue;
}







}; // End of namespace Rtl16

#endif

