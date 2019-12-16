///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- BLOCK_DISABLE_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class BLOCK_DISABLE_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_BLOCK_DISABLE_Reg_
#define _Rtl16_BLOCK_DISABLE_Reg_

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

/// The definition of class BLOCK_DISABLE_Reg
class BLOCK_DISABLE_Reg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        BLOCK_DISABLE_Reg( );

   /// Special Constructor 
        BLOCK_DISABLE_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~BLOCK_DISABLE_Reg( );

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
       bool operator == (const BLOCK_DISABLE_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const BLOCK_DISABLE_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0DIS_BG
         ///  The Get function for member 0DIS_BG
              uint2   GetDIS_BG( ) const;
         ///  The Set function for member 0DIS_BG
              void    SetDIS_BG( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 1DIS_PLL
         ///  The Get function for member 1DIS_PLL
              uint2   GetDIS_PLL( ) const;
         ///  The Set function for member 1DIS_PLL
              void    SetDIS_PLL( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2DIS_75023_BUFFERS
         ///  The Get function for member 2DIS_75023_BUFFERS
              uint2   GetDIS_75023_BUFFERS( ) const;
         ///  The Set function for member 2DIS_75023_BUFFERS
              void    SetDIS_75023_BUFFERS( const uint2 & aValue );
         //----------------------------------------------------
         // The member 3DIS_VIDEO_BUFFERS
         ///  The Get function for member 3DIS_VIDEO_BUFFERS
              uint2   GetDIS_VIDEO_BUFFERS( ) const;
         ///  The Set function for member 3DIS_VIDEO_BUFFERS
              void    SetDIS_VIDEO_BUFFERS( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6DIS_ADC_BG
         ///  The Get function for member 6DIS_ADC_BG
              uint2   GetDIS_ADC_BG( ) const;
         ///  The Set function for member 6DIS_ADC_BG
              void    SetDIS_ADC_BG( const uint2 & aValue );
         //----------------------------------------------------
         // The member 7DIS_ADC_REF
         ///  The Get function for member 7DIS_ADC_REF
              uint2   GetDIS_ADC_REF( ) const;
         ///  The Set function for member 7DIS_ADC_REF
              void    SetDIS_ADC_REF( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0DIS_BG: 1;
         uint2 its1DIS_PLL: 1;
         uint2 its2DIS_75023_BUFFERS: 1;
         uint2 its3DIS_VIDEO_BUFFERS: 1;
         uint2 its4Reserved: 1;
         uint2 its5Reserved: 1;
         uint2 its6DIS_ADC_BG: 1;
         uint2 its7DIS_ADC_REF: 1;
         uint2 its8Reserved: 1;
         uint2 its9Reserved: 1;
         uint2 its10Reserved: 1;
         uint2 its11Reserved: 1;
         uint2 its12Reserved: 1;
         uint2 its13Reserved: 1;
         uint2 its14Reserved: 1;
         uint2 its15Reserved: 1;

};
};

}; // End of class BLOCK_DISABLE_Reg

//------------------------------ Inline Functions ----------------------
inline bool BLOCK_DISABLE_Reg::operator == (const BLOCK_DISABLE_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool BLOCK_DISABLE_Reg::operator < (const BLOCK_DISABLE_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const BLOCK_DISABLE_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 BLOCK_DISABLE_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void BLOCK_DISABLE_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_BG( ) const
{
 return its0DIS_BG;
}

inline void BLOCK_DISABLE_Reg::SetDIS_BG( const uint2 & aValue )
{
 its0DIS_BG = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void BLOCK_DISABLE_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_PLL( ) const
{
 return its1DIS_PLL;
}

inline void BLOCK_DISABLE_Reg::SetDIS_PLL( const uint2 & aValue )
{
 its1DIS_PLL = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_75023_BUFFERS( ) const
{
 return its2DIS_75023_BUFFERS;
}

inline void BLOCK_DISABLE_Reg::SetDIS_75023_BUFFERS( const uint2 & aValue )
{
 its2DIS_75023_BUFFERS = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_VIDEO_BUFFERS( ) const
{
 return its3DIS_VIDEO_BUFFERS;
}

inline void BLOCK_DISABLE_Reg::SetDIS_VIDEO_BUFFERS( const uint2 & aValue )
{
 its3DIS_VIDEO_BUFFERS = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_ADC_BG( ) const
{
 return its6DIS_ADC_BG;
}

inline void BLOCK_DISABLE_Reg::SetDIS_ADC_BG( const uint2 & aValue )
{
 its6DIS_ADC_BG = aValue;
}

inline uint2 BLOCK_DISABLE_Reg::GetDIS_ADC_REF( ) const
{
 return its7DIS_ADC_REF;
}

inline void BLOCK_DISABLE_Reg::SetDIS_ADC_REF( const uint2 & aValue )
{
 its7DIS_ADC_REF = aValue;
}







}; // End of namespace Rtl16

#endif

