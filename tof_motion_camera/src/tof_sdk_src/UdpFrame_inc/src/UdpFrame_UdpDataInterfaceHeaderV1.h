///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2383 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class UdpDataInterfaceHeaderV1 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Apr 17 15:45:31 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _UdpFrame_UdpDataInterfaceHeaderV1_
#define _UdpFrame_UdpDataInterfaceHeaderV1_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }


/// The namespace UdpFrame
namespace UdpFrame
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class UdpDataInterfaceHeaderV1
class UdpDataInterfaceHeaderV1
{
public:

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        UdpDataInterfaceHeaderV1( );

   /// Destructor
        ~UdpDataInterfaceHeaderV1( );

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
       bool operator == (const UdpDataInterfaceHeaderV1 & aRef) const;
   
   /// Less operator 
       bool operator < (const UdpDataInterfaceHeaderV1 & aRef) const;

   ///@name Set and Get functions for all members 
   //@{
         // The member 0Version
         ///  The Get function for member 0Version
              uint2   Get0Version( ) const;
         ///  The Set function for member 0Version
              void    Set0Version( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2FrameCounter
         ///  The Get function for member 2FrameCounter
              uint2   Get2FrameCounter( ) const;
         ///  The Set function for member 2FrameCounter
              void    Set2FrameCounter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4PacketCounter
         ///  The Get function for member 4PacketCounter
              uint2   Get4PacketCounter( ) const;
         ///  The Set function for member 4PacketCounter
              void    Set4PacketCounter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6DataLength
         ///  The Get function for member 6DataLength
              uint2   Get6DataLength( ) const;
         ///  The Set function for member 6DataLength
              void    Set6DataLength( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8FrameSize
         ///  The Get function for member 8FrameSize
              uint4   Get8FrameSize( ) const;
         ///  The Set function for member 8FrameSize
              void    Set8FrameSize( const uint4 & aValue );
         //----------------------------------------------------
         // The member 12PacketCrc32
         ///  The Get function for member 12PacketCrc32
              uint4   Get12PacketCrc32( ) const;
         ///  The Set function for member 12PacketCrc32
              void    Set12PacketCrc32( const uint4 & aValue );
         //----------------------------------------------------
         // The member 16Flags
         ///  The Get function for member 16Flags
              uint4   Get16Flags( ) const;
         ///  The Set function for member 16Flags
              void    Set16Flags( const uint4 & aValue );
         //----------------------------------------------------
         // The member 20Reserved
         ///  The Get function for member 20Reserved
              uint4   Get20Reserved( ) const;
         ///  The Set function for member 20Reserved
              void    Set20Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 24Reserved
         ///  The Get function for member 24Reserved
              uint4   Get24Reserved( ) const;
         ///  The Set function for member 24Reserved
              void    Set24Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 28Reserved
         ///  The Get function for member 28Reserved
              uint4   Get28Reserved( ) const;
         ///  The Set function for member 28Reserved
              void    Set28Reserved( const uint4 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         uint2 its0Version;
         uint2 its2FrameCounter;
         uint2 its4PacketCounter;
         uint2 its6DataLength;
         uint4 its8FrameSize;
         uint4 its12PacketCrc32;
         uint4 its16Flags;
         uint4 its20Reserved;
         uint4 its24Reserved;
         uint4 its28Reserved;


}; // End of class UdpDataInterfaceHeaderV1

//------------------------------ Inline Functions ----------------------
inline bool UdpDataInterfaceHeaderV1::operator == (const UdpDataInterfaceHeaderV1 & aRef) const
{
   if ( ! (its0Version == aRef.its0Version) ) return false;
   if ( ! (its2FrameCounter == aRef.its2FrameCounter) ) return false;
   if ( ! (its4PacketCounter == aRef.its4PacketCounter) ) return false;
   if ( ! (its6DataLength == aRef.its6DataLength) ) return false;
   if ( ! (its8FrameSize == aRef.its8FrameSize) ) return false;
   if ( ! (its12PacketCrc32 == aRef.its12PacketCrc32) ) return false;
   if ( ! (its16Flags == aRef.its16Flags) ) return false;
   if ( ! (its20Reserved == aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved == aRef.its24Reserved) ) return false;
   if ( ! (its28Reserved == aRef.its28Reserved) ) return false;

   return true;
}

inline bool UdpDataInterfaceHeaderV1::operator < (const UdpDataInterfaceHeaderV1 & aRef) const
{
   if ( ! (its0Version < aRef.its0Version) ) return false;
   if ( ! (its2FrameCounter < aRef.its2FrameCounter) ) return false;
   if ( ! (its4PacketCounter < aRef.its4PacketCounter) ) return false;
   if ( ! (its6DataLength < aRef.its6DataLength) ) return false;
   if ( ! (its8FrameSize < aRef.its8FrameSize) ) return false;
   if ( ! (its12PacketCrc32 < aRef.its12PacketCrc32) ) return false;
   if ( ! (its16Flags < aRef.its16Flags) ) return false;
   if ( ! (its20Reserved < aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved < aRef.its24Reserved) ) return false;
   if ( ! (its28Reserved < aRef.its28Reserved) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const UdpDataInterfaceHeaderV1 & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 UdpDataInterfaceHeaderV1::Get0Version( ) const
{
 return its0Version;
}

inline void UdpDataInterfaceHeaderV1::Set0Version( const uint2 & aValue )
{
 its0Version = aValue;
}
inline uint2 UdpDataInterfaceHeaderV1::Get2FrameCounter( ) const
{
 return its2FrameCounter;
}

inline void UdpDataInterfaceHeaderV1::Set2FrameCounter( const uint2 & aValue )
{
 its2FrameCounter = aValue;
}
inline uint2 UdpDataInterfaceHeaderV1::Get4PacketCounter( ) const
{
 return its4PacketCounter;
}

inline void UdpDataInterfaceHeaderV1::Set4PacketCounter( const uint2 & aValue )
{
 its4PacketCounter = aValue;
}
inline uint2 UdpDataInterfaceHeaderV1::Get6DataLength( ) const
{
 return its6DataLength;
}

inline void UdpDataInterfaceHeaderV1::Set6DataLength( const uint2 & aValue )
{
 its6DataLength = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get8FrameSize( ) const
{
 return its8FrameSize;
}

inline void UdpDataInterfaceHeaderV1::Set8FrameSize( const uint4 & aValue )
{
 its8FrameSize = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get12PacketCrc32( ) const
{
 return its12PacketCrc32;
}

inline void UdpDataInterfaceHeaderV1::Set12PacketCrc32( const uint4 & aValue )
{
 its12PacketCrc32 = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get16Flags( ) const
{
 return its16Flags;
}

inline void UdpDataInterfaceHeaderV1::Set16Flags( const uint4 & aValue )
{
 its16Flags = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get20Reserved( ) const
{
 return its20Reserved;
}

inline void UdpDataInterfaceHeaderV1::Set20Reserved( const uint4 & aValue )
{
 its20Reserved = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get24Reserved( ) const
{
 return its24Reserved;
}

inline void UdpDataInterfaceHeaderV1::Set24Reserved( const uint4 & aValue )
{
 its24Reserved = aValue;
}
inline uint4 UdpDataInterfaceHeaderV1::Get28Reserved( ) const
{
 return its28Reserved;
}

inline void UdpDataInterfaceHeaderV1::Set28Reserved( const uint4 & aValue )
{
 its28Reserved = aValue;
}


}; // End of namespace UdpFrame

#endif

