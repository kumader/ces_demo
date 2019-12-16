///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ImgProcConfig2Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ImgProcConfig2Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ImgProcConfig2Reg_
#define _Rtl16_ImgProcConfig2Reg_

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

/// The definition of class ImgProcConfig2Reg
class ImgProcConfig2Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ImgProcConfig2Reg( );

   /// Special Constructor 
        ImgProcConfig2Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ImgProcConfig2Reg( );

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
       bool operator == (const ImgProcConfig2Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const ImgProcConfig2Reg & aRef) const;

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
         // The member 4EnableVerticalStripesWorkaround
         ///  The Get function for member 4EnableVerticalStripesWorkaround
              uint2   GetEnableVerticalStripesWorkaround( ) const;
         ///  The Set function for member 4EnableVerticalStripesWorkaround
              void    SetEnableVerticalStripesWorkaround( const uint2 & aValue );
         ///  The ConvertToString function for member 4EnableVerticalStripesWorkaround
              std::string    ConvertToStringEnableVerticalStripesWorkaround( ) const;

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its1Reserved: 1;
         uint2 its2Reserved: 1;
         uint2 its3Reserved: 1;
         uint2 its4EnableVerticalStripesWorkaround: 1;

};
};

}; // End of class ImgProcConfig2Reg

//------------------------------ Inline Functions ----------------------
inline bool ImgProcConfig2Reg::operator == (const ImgProcConfig2Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ImgProcConfig2Reg::operator < (const ImgProcConfig2Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ImgProcConfig2Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ImgProcConfig2Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void ImgProcConfig2Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ImgProcConfig2Reg::GetReg( ) const
{
 return its0Reg;
}

inline void ImgProcConfig2Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 ImgProcConfig2Reg::GetEnableVerticalStripesWorkaround( ) const
{
 return its4EnableVerticalStripesWorkaround;
}

inline void ImgProcConfig2Reg::SetEnableVerticalStripesWorkaround( const uint2 & aValue )
{
 its4EnableVerticalStripesWorkaround = aValue;
}




inline std::string ImgProcConfig2Reg::ConvertToStringEnableVerticalStripesWorkaround( ) const
{
 switch (its4EnableVerticalStripesWorkaround)
 {
 case 1: return "1:Enable Vertical Stripes Workaround fore Melexis Sensor/Companion Chip on both Distance and Amplitude Images"; break; 
 default: return "unknown value"; 
 }//switch
}





}; // End of namespace Rtl16

#endif

