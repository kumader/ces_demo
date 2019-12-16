///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ProcessorStatusReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ProcessorStatusReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ProcessorStatusReg_
#define _Rtl16_ProcessorStatusReg_

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

/// The definition of class ProcessorStatusReg
class ProcessorStatusReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ProcessorStatusReg( );

   /// Special Constructor 
        ProcessorStatusReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ProcessorStatusReg( );

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
       bool operator == (const ProcessorStatusReg & aRef) const;
   
   /// Less operator 
       bool operator < (const ProcessorStatusReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0ProcessorTemp_deg
         ///  The Get function for member 0ProcessorTemp_deg
              uint2   GetProcessorTemp_deg( ) const;
         ///  The Set function for member 0ProcessorTemp_deg
              void    SetProcessorTemp_deg( const uint2 & aValue );
         ///  The ConvertToString function for member 0ProcessorTemp_deg
              std::string    ConvertToStringProcessorTemp_deg( ) const;
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8ProcessorSpeed_10MHz
         ///  The Get function for member 8ProcessorSpeed_10MHz
              uint2   GetProcessorSpeed_10MHz( ) const;
         ///  The Set function for member 8ProcessorSpeed_10MHz
              void    SetProcessorSpeed_10MHz( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0ProcessorTemp_deg: 8;
         uint2 its8ProcessorSpeed_10MHz: 8;

};
};

}; // End of class ProcessorStatusReg

//------------------------------ Inline Functions ----------------------
inline bool ProcessorStatusReg::operator == (const ProcessorStatusReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ProcessorStatusReg::operator < (const ProcessorStatusReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ProcessorStatusReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ProcessorStatusReg::GetAddr( ) const
{
 return its0Addr;
}

inline void ProcessorStatusReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ProcessorStatusReg::GetProcessorTemp_deg( ) const
{
 return its0ProcessorTemp_deg;
}

inline void ProcessorStatusReg::SetProcessorTemp_deg( const uint2 & aValue )
{
 its0ProcessorTemp_deg = aValue;
}

inline uint2 ProcessorStatusReg::GetReg( ) const
{
 return its0Reg;
}

inline void ProcessorStatusReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 ProcessorStatusReg::GetProcessorSpeed_10MHz( ) const
{
 return its8ProcessorSpeed_10MHz;
}

inline void ProcessorStatusReg::SetProcessorSpeed_10MHz( const uint2 & aValue )
{
 its8ProcessorSpeed_10MHz = aValue;
}




inline std::string ProcessorStatusReg::ConvertToStringProcessorTemp_deg( ) const
{
 switch (its0ProcessorTemp_deg)
 {
 case 255: return "255:sensor not available"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

