///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ADC_DELAY_FT_Reg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ADC_DELAY_FT_Reg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ADC_DELAY_FT_Reg_
#define _Rtl16_ADC_DELAY_FT_Reg_

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

/// The definition of class ADC_DELAY_FT_Reg
class ADC_DELAY_FT_Reg: public Virtual16BitReg
{
public:

   //enums

          enum Register_e
          {
          ADC_DELAY_FT = 0x1010 
          };



   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ADC_DELAY_FT_Reg( );

   /// Special Constructor 
        ADC_DELAY_FT_Reg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ADC_DELAY_FT_Reg( );

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
       bool operator == (const ADC_DELAY_FT_Reg & aRef) const;
   
   /// Less operator 
       bool operator < (const ADC_DELAY_FT_Reg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0FRAME_TABLE
         ///  The Get function for member 0FRAME_TABLE
              uint2   GetFRAME_TABLE( ) const;
         ///  The Set function for member 0FRAME_TABLE
              void    SetFRAME_TABLE( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 1PROG_DELAY
         ///  The Get function for member 1PROG_DELAY
              uint2   GetPROG_DELAY( ) const;
         ///  The Set function for member 1PROG_DELAY
              void    SetPROG_DELAY( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6EN_PROG_DELAY
         ///  The Get function for member 6EN_PROG_DELAY
              uint2   GetEN_PROG_DELAY( ) const;
         ///  The Set function for member 6EN_PROG_DELAY
              void    SetEN_PROG_DELAY( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0FRAME_TABLE: 1;
         uint2 its1PROG_DELAY: 5;
         uint2 its6EN_PROG_DELAY: 1;

};
};

}; // End of class ADC_DELAY_FT_Reg

//------------------------------ Inline Functions ----------------------
inline bool ADC_DELAY_FT_Reg::operator == (const ADC_DELAY_FT_Reg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ADC_DELAY_FT_Reg::operator < (const ADC_DELAY_FT_Reg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ADC_DELAY_FT_Reg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ADC_DELAY_FT_Reg::GetAddr( ) const
{
 return its0Addr;
}

inline void ADC_DELAY_FT_Reg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ADC_DELAY_FT_Reg::GetFRAME_TABLE( ) const
{
 return its0FRAME_TABLE;
}

inline void ADC_DELAY_FT_Reg::SetFRAME_TABLE( const uint2 & aValue )
{
 its0FRAME_TABLE = aValue;
}

inline uint2 ADC_DELAY_FT_Reg::GetReg( ) const
{
 return its0Reg;
}

inline void ADC_DELAY_FT_Reg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 ADC_DELAY_FT_Reg::GetPROG_DELAY( ) const
{
 return its1PROG_DELAY;
}

inline void ADC_DELAY_FT_Reg::SetPROG_DELAY( const uint2 & aValue )
{
 its1PROG_DELAY = aValue;
}

inline uint2 ADC_DELAY_FT_Reg::GetEN_PROG_DELAY( ) const
{
 return its6EN_PROG_DELAY;
}

inline void ADC_DELAY_FT_Reg::SetEN_PROG_DELAY( const uint2 & aValue )
{
 its6EN_PROG_DELAY = aValue;
}







}; // End of namespace Rtl16

#endif

