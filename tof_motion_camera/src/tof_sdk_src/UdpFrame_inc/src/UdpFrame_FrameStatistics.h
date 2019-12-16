///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2383 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FrameStatistics 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Apr 17 20:00:37 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _UdpFrame_FrameStatistics_
#define _UdpFrame_FrameStatistics_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#include "Common_PreciseTimeValue.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }


/// The namespace UdpFrame
namespace UdpFrame
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class FrameStatistics
class FrameStatistics
{
public:

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FrameStatistics( );

   /// Destructor
        ~FrameStatistics( );

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
       bool operator == (const FrameStatistics & aRef) const;
   
   /// Less operator 
       bool operator < (const FrameStatistics & aRef) const;

   ///@name Set and Get functions for all members 
   //@{
         // The member T1
         ///  The Get function for member T1
              Common::PreciseTimeValue   GetT1( ) const;
         ///  The Set function for member T1
              void    SetT1( const Common::PreciseTimeValue & aValue );
         //----------------------------------------------------
         // The member NofBytes
         ///  The Get function for member NofBytes
              sint8   GetNofBytes( ) const;
         ///  The Set function for member NofBytes
              void    SetNofBytes( const sint8 & aValue );
         //----------------------------------------------------
         // The member T2
         ///  The Get function for member T2
              Common::PreciseTimeValue   GetT2( ) const;
         ///  The Set function for member T2
              void    SetT2( const Common::PreciseTimeValue & aValue );
         //----------------------------------------------------

         // The Start Function
              void    Start(  );
         //----------------------------------------------------
         // The Update Function
              void    Update( const sint8 & aNofBytes  );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         Common::PreciseTimeValue itsT1;
         sint8 itsNofBytes;
         Common::PreciseTimeValue itsT2;


}; // End of class FrameStatistics

//------------------------------ Inline Functions ----------------------
inline bool FrameStatistics::operator == (const FrameStatistics & aRef) const
{
   if ( ! (itsT1 == aRef.itsT1) ) return false;
   if ( ! (itsNofBytes == aRef.itsNofBytes) ) return false;
   if ( ! (itsT2 == aRef.itsT2) ) return false;

   return true;
}

inline bool FrameStatistics::operator < (const FrameStatistics & aRef) const
{
   if ( ! (itsT1 < aRef.itsT1) ) return false;
   if ( ! (itsNofBytes < aRef.itsNofBytes) ) return false;
   if ( ! (itsT2 < aRef.itsT2) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FrameStatistics & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline Common::PreciseTimeValue FrameStatistics::GetT1( ) const
{
 return itsT1;
}

inline void FrameStatistics::SetT1( const Common::PreciseTimeValue & aValue )
{
 itsT1 = aValue;
}
inline sint8 FrameStatistics::GetNofBytes( ) const
{
 return itsNofBytes;
}

inline void FrameStatistics::SetNofBytes( const sint8 & aValue )
{
 itsNofBytes = aValue;
}
inline Common::PreciseTimeValue FrameStatistics::GetT2( ) const
{
 return itsT2;
}

inline void FrameStatistics::SetT2( const Common::PreciseTimeValue & aValue )
{
 itsT2 = aValue;
}


}; // End of namespace UdpFrame

#endif

