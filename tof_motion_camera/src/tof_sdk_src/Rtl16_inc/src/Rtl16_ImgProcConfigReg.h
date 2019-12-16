///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- ImgProcConfigReg
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class ImgProcConfigReg 
//              used /usr/local/bin/Rtl16_CppClassCoder.pl to create this file
//              created Sun Mar 31 17:03:18 2019
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_ImgProcConfigReg_
#define _Rtl16_ImgProcConfigReg_

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

/// The definition of class ImgProcConfigReg
class ImgProcConfigReg: public Virtual16BitReg
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        ImgProcConfigReg( );

   /// Special Constructor 
        ImgProcConfigReg( const uint2& a0AddrValue, const uint2& a0RegValue );

   /// Destructor
        ~ImgProcConfigReg( );

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
       bool operator == (const ImgProcConfigReg & aRef) const;
   
   /// Less operator 
       bool operator < (const ImgProcConfigReg & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         // The member 0Addr
         ///  The Get function for member 0Addr
              uint2   GetAddr( ) const;
         ///  The Set function for member 0Addr
              void    SetAddr( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0EnableMedianFilter
         ///  The Get function for member 0EnableMedianFilter
              uint2   GetEnableMedianFilter( ) const;
         ///  The Set function for member 0EnableMedianFilter
              void    SetEnableMedianFilter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 0Reg
         ///  The Get function for member 0Reg
              uint2   GetReg( ) const;
         ///  The Set function for member 0Reg
              void    SetReg( const uint2 & aValue );
         //----------------------------------------------------
         // The member 3EnableBilateralFilter
         ///  The Get function for member 3EnableBilateralFilter
              uint2   GetEnableBilateralFilter( ) const;
         ///  The Set function for member 3EnableBilateralFilter
              void    SetEnableBilateralFilter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4EnableSlidingAverage
         ///  The Get function for member 4EnableSlidingAverage
              uint2   GetEnableSlidingAverage( ) const;
         ///  The Set function for member 4EnableSlidingAverage
              void    SetEnableSlidingAverage( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6EnableWigglingCompensation
         ///  The Get function for member 6EnableWigglingCompensation
              uint2   GetEnableWigglingCompensation( ) const;
         ///  The Set function for member 6EnableWigglingCompensation
              void    SetEnableWigglingCompensation( const uint2 & aValue );
         //----------------------------------------------------
         // The member 7EnableFPPNCompensation
         ///  The Get function for member 7EnableFPPNCompensation
              uint2   GetEnableFPPNCompensation( ) const;
         ///  The Set function for member 7EnableFPPNCompensation
              void    SetEnableFPPNCompensation( const uint2 & aValue );
         //----------------------------------------------------
         // The member 10EnableFrameAverageFilter
         ///  The Get function for member 10EnableFrameAverageFilter
              uint2   GetEnableFrameAverageFilter( ) const;
         ///  The Set function for member 10EnableFrameAverageFilter
              void    SetEnableFrameAverageFilter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 11EnableTemperatureCompensation
         ///  The Get function for member 11EnableTemperatureCompensation
              uint2   GetEnableTemperatureCompensation( ) const;
         ///  The Set function for member 11EnableTemperatureCompensation
              void    SetEnableTemperatureCompensation( const uint2 & aValue );
         //----------------------------------------------------
         // The member 13EnableOffsetViaDistOffset0
         ///  The Get function for member 13EnableOffsetViaDistOffset0
              uint2   GetEnableOffsetViaDistOffset0( ) const;
         ///  The Set function for member 13EnableOffsetViaDistOffset0
              void    SetEnableOffsetViaDistOffset0( const uint2 & aValue );

   //@}

private:
  

   //   All the Elements
        uint2 its0Addr;
union {
        uint2 its0Reg;       
struct {
         uint2 its0EnableMedianFilter: 1;
         uint2 its1Reserved: 1;
         uint2 its2Reserved: 1;
         uint2 its3EnableBilateralFilter: 1;
         uint2 its4EnableSlidingAverage: 1;
         uint2 its5Reserved: 1;
         uint2 its6EnableWigglingCompensation: 1;
         uint2 its7EnableFPPNCompensation: 1;
         uint2 its8Reserved: 1;
         uint2 its9Reserved: 1;
         uint2 its10EnableFrameAverageFilter: 1;
         uint2 its11EnableTemperatureCompensation: 1;
         uint2 its12Reserved: 1;
         uint2 its13EnableOffsetViaDistOffset0: 1;

};
};

}; // End of class ImgProcConfigReg

//------------------------------ Inline Functions ----------------------
inline bool ImgProcConfigReg::operator == (const ImgProcConfigReg & aRef) const
{
   if ( ! (its0Addr == aRef.its0Addr) ) return false;
   if ( ! (its0Reg == aRef.its0Reg) ) return false;

   return true;
}

inline bool ImgProcConfigReg::operator < (const ImgProcConfigReg & aRef) const
{
   if ( ! (its0Addr < aRef.its0Addr) ) return false;
   if ( ! (its0Reg < aRef.its0Reg) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const ImgProcConfigReg & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 ImgProcConfigReg::GetAddr( ) const
{
 return its0Addr;
}

inline void ImgProcConfigReg::SetAddr( const uint2 & aValue )
{
 its0Addr = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableMedianFilter( ) const
{
 return its0EnableMedianFilter;
}

inline void ImgProcConfigReg::SetEnableMedianFilter( const uint2 & aValue )
{
 its0EnableMedianFilter = aValue;
}

inline uint2 ImgProcConfigReg::GetReg( ) const
{
 return its0Reg;
}

inline void ImgProcConfigReg::SetReg( const uint2 & aValue )
{
 its0Reg = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableBilateralFilter( ) const
{
 return its3EnableBilateralFilter;
}

inline void ImgProcConfigReg::SetEnableBilateralFilter( const uint2 & aValue )
{
 its3EnableBilateralFilter = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableSlidingAverage( ) const
{
 return its4EnableSlidingAverage;
}

inline void ImgProcConfigReg::SetEnableSlidingAverage( const uint2 & aValue )
{
 its4EnableSlidingAverage = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableWigglingCompensation( ) const
{
 return its6EnableWigglingCompensation;
}

inline void ImgProcConfigReg::SetEnableWigglingCompensation( const uint2 & aValue )
{
 its6EnableWigglingCompensation = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableFPPNCompensation( ) const
{
 return its7EnableFPPNCompensation;
}

inline void ImgProcConfigReg::SetEnableFPPNCompensation( const uint2 & aValue )
{
 its7EnableFPPNCompensation = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableFrameAverageFilter( ) const
{
 return its10EnableFrameAverageFilter;
}

inline void ImgProcConfigReg::SetEnableFrameAverageFilter( const uint2 & aValue )
{
 its10EnableFrameAverageFilter = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableTemperatureCompensation( ) const
{
 return its11EnableTemperatureCompensation;
}

inline void ImgProcConfigReg::SetEnableTemperatureCompensation( const uint2 & aValue )
{
 its11EnableTemperatureCompensation = aValue;
}

inline uint2 ImgProcConfigReg::GetEnableOffsetViaDistOffset0( ) const
{
 return its13EnableOffsetViaDistOffset0;
}

inline void ImgProcConfigReg::SetEnableOffsetViaDistOffset0( const uint2 & aValue )
{
 its13EnableOffsetViaDistOffset0 = aValue;
}







}; // End of namespace Rtl16

#endif

