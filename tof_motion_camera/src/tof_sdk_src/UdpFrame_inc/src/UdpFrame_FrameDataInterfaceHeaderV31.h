///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FrameDataInterfaceHeaderV31 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Jun 17 08:43:13 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _UdpFrame_FrameDataInterfaceHeaderV31_
#define _UdpFrame_FrameDataInterfaceHeaderV31_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include <string>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace UdpFrame
namespace UdpFrame
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class FrameDataInterfaceHeaderV31
class FrameDataInterfaceHeaderV31
{
public:

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        FrameDataInterfaceHeaderV31( );

   /// Destructor
        ~FrameDataInterfaceHeaderV31( );

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
       bool operator == (const FrameDataInterfaceHeaderV31 & aRef) const;
   
   /// Less operator 
       bool operator < (const FrameDataInterfaceHeaderV31 & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         // The member 0Reserved
         ///  The Get function for member 0Reserved
              uint2   Get0Reserved( ) const;
         ///  The Set function for member 0Reserved
              void    Set0Reserved( const uint2 & aValue );
         //----------------------------------------------------
         // The member 2HeaderVersion
         ///  The Get function for member 2HeaderVersion
              uint2   Get2HeaderVersion( ) const;
         ///  The Set function for member 2HeaderVersion
              void    Set2HeaderVersion( const uint2 & aValue );
         //----------------------------------------------------
         // The member 4ImageWidth
         ///  The Get function for member 4ImageWidth
              uint2   Get4ImageWidth( ) const;
         ///  The Set function for member 4ImageWidth
              void    Set4ImageWidth( const uint2 & aValue );
         //----------------------------------------------------
         // The member 6ImageHeight
         ///  The Get function for member 6ImageHeight
              uint2   Get6ImageHeight( ) const;
         ///  The Set function for member 6ImageHeight
              void    Set6ImageHeight( const uint2 & aValue );
         //----------------------------------------------------
         // The member 8NofChannels
         ///  The Get function for member 8NofChannels
              uint1   Get8NofChannels( ) const;
         ///  The Set function for member 8NofChannels
              void    Set8NofChannels( const uint1 & aValue );
         //----------------------------------------------------
         // The member 9BytesPerPixel
         ///  The Get function for member 9BytesPerPixel
              uint1   Get9BytesPerPixel( ) const;
         ///  The Set function for member 9BytesPerPixel
              void    Set9BytesPerPixel( const uint1 & aValue );
         //----------------------------------------------------
         // The member 10ImageFormat
         ///  The Get function for member 10ImageFormat
              uint2   Get10ImageFormat( ) const;
         ///  The Set function for member 10ImageFormat
              void    Set10ImageFormat( const uint2 & aValue );
         //----------------------------------------------------
         // The member 12Timestamp
         ///  The Get function for member 12Timestamp
              uint4   Get12Timestamp( ) const;
         ///  The Set function for member 12Timestamp
              void    Set12Timestamp( const uint4 & aValue );
         //----------------------------------------------------
         // The member 16FrameCounter
         ///  The Get function for member 16FrameCounter
              uint2   Get16FrameCounter( ) const;
         ///  The Set function for member 16FrameCounter
              void    Set16FrameCounter( const uint2 & aValue );
         //----------------------------------------------------
         // The member 18PreMetaData
         ///  The Get function for member 18PreMetaData
              uint1   Get18PreMetaData( ) const;
         ///  The Set function for member 18PreMetaData
              void    Set18PreMetaData( const uint1 & aValue );
         //----------------------------------------------------
         // The member 19PostMetaData
         ///  The Get function for member 19PostMetaData
              uint1   Get19PostMetaData( ) const;
         ///  The Set function for member 19PostMetaData
              void    Set19PostMetaData( const uint1 & aValue );
         //----------------------------------------------------
         // The member 20Reserved
         ///  The Get function for member 20Reserved
              uint4   Get20Reserved( ) const;
         ///  The Set function for member 20Reserved
              void    Set20Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 24Reserved
         ///  The Get function for member 24Reserved
              uint2   Get24Reserved( ) const;
         ///  The Set function for member 24Reserved
              void    Set24Reserved( const uint2 & aValue );
         //----------------------------------------------------
         // The member 26MainTemp
         ///  The Get function for member 26MainTemp
              uint1   Get26MainTemp( ) const;
         ///  The Set function for member 26MainTemp
              void    Set26MainTemp( const uint1 & aValue );
         //----------------------------------------------------
         // The member 27LedTemp
         ///  The Get function for member 27LedTemp
              uint1   Get27LedTemp( ) const;
         ///  The Set function for member 27LedTemp
              void    Set27LedTemp( const uint1 & aValue );
         //----------------------------------------------------
         // The member 28FirmwareVersion
         ///  The Get function for member 28FirmwareVersion
              uint2   Get28FirmwareVersion( ) const;
         ///  The Set function for member 28FirmwareVersion
              void    Set28FirmwareVersion( const uint2 & aValue );
         //----------------------------------------------------
         // The member 30MagicV31
         ///  The Get function for member 30MagicV31
              uint2   Get30MagicV31( ) const;
         ///  The Set function for member 30MagicV31
              void    Set30MagicV31( const uint2 & aValue );
         //----------------------------------------------------
         // The member 32IntegrationTime
         ///  The Get function for member 32IntegrationTime
              uint2   Get32IntegrationTime( ) const;
         ///  The Set function for member 32IntegrationTime
              void    Set32IntegrationTime( const uint2 & aValue );
         //----------------------------------------------------
         // The member 34ModulationFreq
         ///  The Get function for member 34ModulationFreq
              uint2   Get34ModulationFreq( ) const;
         ///  The Set function for member 34ModulationFreq
              void    Set34ModulationFreq( const uint2 & aValue );
         //----------------------------------------------------
         // The member 36Temp3
         ///  The Get function for member 36Temp3
              uint1   Get36Temp3( ) const;
         ///  The Set function for member 36Temp3
              void    Set36Temp3( const uint1 & aValue );
         //----------------------------------------------------
         // The member 37ColorMode
         ///  The Get function for member 37ColorMode
              uint1   Get37ColorMode( ) const;
         ///  The Set function for member 37ColorMode
              void    Set37ColorMode( const uint1 & aValue );
         //----------------------------------------------------
         // The member 38ColorSensorWidth
         ///  The Get function for member 38ColorSensorWidth
              uint2   Get38ColorSensorWidth( ) const;
         ///  The Set function for member 38ColorSensorWidth
              void    Set38ColorSensorWidth( const uint2 & aValue );
         //----------------------------------------------------
         // The member 40ColorSensorHeight
         ///  The Get function for member 40ColorSensorHeight
              uint2   Get40ColorSensorHeight( ) const;
         ///  The Set function for member 40ColorSensorHeight
              void    Set40ColorSensorHeight( const uint2 & aValue );
         //----------------------------------------------------
         // The member 42Reserved
         ///  The Get function for member 42Reserved
              uint4   Get42Reserved( ) const;
         ///  The Set function for member 42Reserved
              void    Set42Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 46Reserved
         ///  The Get function for member 46Reserved
              uint2   Get46Reserved( ) const;
         ///  The Set function for member 46Reserved
              void    Set46Reserved( const uint2 & aValue );
         //----------------------------------------------------
         // The member 48RawPhaseContent
         ///  The Get function for member 48RawPhaseContent
              uint4   Get48RawPhaseContent( ) const;
         ///  The Set function for member 48RawPhaseContent
              void    Set48RawPhaseContent( const uint4 & aValue );
         //----------------------------------------------------
         // The member 52Reserved
         ///  The Get function for member 52Reserved
              uint2   Get52Reserved( ) const;
         ///  The Set function for member 52Reserved
              void    Set52Reserved( const uint2 & aValue );
         //----------------------------------------------------
         // The member 54Reserved
         ///  The Get function for member 54Reserved
              uint4   Get54Reserved( ) const;
         ///  The Set function for member 54Reserved
              void    Set54Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 58Reserved
         ///  The Get function for member 58Reserved
              uint4   Get58Reserved( ) const;
         ///  The Set function for member 58Reserved
              void    Set58Reserved( const uint4 & aValue );
         //----------------------------------------------------
         // The member 62Crc16
         ///  The Get function for member 62Crc16
              uint2   Get62Crc16( ) const;
         ///  The Set function for member 62Crc16
              void    Set62Crc16( const uint2 & aValue );
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         uint2 its0Reserved;
         uint2 its2HeaderVersion;
         uint2 its4ImageWidth;
         uint2 its6ImageHeight;
         uint1 its8NofChannels;
         uint1 its9BytesPerPixel;
         uint2 its10ImageFormat;
         uint4 its12Timestamp;
         uint2 its16FrameCounter;
         uint1 its18PreMetaData;
         uint1 its19PostMetaData;
         uint4 its20Reserved;
         uint2 its24Reserved;
         uint1 its26MainTemp;
         uint1 its27LedTemp;
         uint2 its28FirmwareVersion;
         uint2 its30MagicV31;
         uint2 its32IntegrationTime;
         uint2 its34ModulationFreq;
         uint1 its36Temp3;
         uint1 its37ColorMode;
         uint2 its38ColorSensorWidth;
         uint2 its40ColorSensorHeight;
         uint4 its42Reserved;
         uint2 its46Reserved;
         uint4 its48RawPhaseContent;
         uint2 its52Reserved;
         uint4 its54Reserved;
         uint4 its58Reserved;
         uint2 its62Crc16;


}; // End of class FrameDataInterfaceHeaderV31

//------------------------------ Inline Functions ----------------------
inline bool FrameDataInterfaceHeaderV31::operator == (const FrameDataInterfaceHeaderV31 & aRef) const
{
   if ( ! (its0Reserved == aRef.its0Reserved) ) return false;
   if ( ! (its2HeaderVersion == aRef.its2HeaderVersion) ) return false;
   if ( ! (its4ImageWidth == aRef.its4ImageWidth) ) return false;
   if ( ! (its6ImageHeight == aRef.its6ImageHeight) ) return false;
   if ( ! (its8NofChannels == aRef.its8NofChannels) ) return false;
   if ( ! (its9BytesPerPixel == aRef.its9BytesPerPixel) ) return false;
   if ( ! (its10ImageFormat == aRef.its10ImageFormat) ) return false;
   if ( ! (its12Timestamp == aRef.its12Timestamp) ) return false;
   if ( ! (its16FrameCounter == aRef.its16FrameCounter) ) return false;
   if ( ! (its18PreMetaData == aRef.its18PreMetaData) ) return false;
   if ( ! (its19PostMetaData == aRef.its19PostMetaData) ) return false;
   if ( ! (its20Reserved == aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved == aRef.its24Reserved) ) return false;
   if ( ! (its26MainTemp == aRef.its26MainTemp) ) return false;
   if ( ! (its27LedTemp == aRef.its27LedTemp) ) return false;
   if ( ! (its28FirmwareVersion == aRef.its28FirmwareVersion) ) return false;
   if ( ! (its30MagicV31 == aRef.its30MagicV31) ) return false;
   if ( ! (its32IntegrationTime == aRef.its32IntegrationTime) ) return false;
   if ( ! (its34ModulationFreq == aRef.its34ModulationFreq) ) return false;
   if ( ! (its36Temp3 == aRef.its36Temp3) ) return false;
   if ( ! (its37ColorMode == aRef.its37ColorMode) ) return false;
   if ( ! (its38ColorSensorWidth == aRef.its38ColorSensorWidth) ) return false;
   if ( ! (its40ColorSensorHeight == aRef.its40ColorSensorHeight) ) return false;
   if ( ! (its42Reserved == aRef.its42Reserved) ) return false;
   if ( ! (its46Reserved == aRef.its46Reserved) ) return false;
   if ( ! (its48RawPhaseContent == aRef.its48RawPhaseContent) ) return false;
   if ( ! (its52Reserved == aRef.its52Reserved) ) return false;
   if ( ! (its54Reserved == aRef.its54Reserved) ) return false;
   if ( ! (its58Reserved == aRef.its58Reserved) ) return false;
   if ( ! (its62Crc16 == aRef.its62Crc16) ) return false;

   return true;
}

inline bool FrameDataInterfaceHeaderV31::operator < (const FrameDataInterfaceHeaderV31 & aRef) const
{
   if ( ! (its0Reserved < aRef.its0Reserved) ) return false;
   if ( ! (its2HeaderVersion < aRef.its2HeaderVersion) ) return false;
   if ( ! (its4ImageWidth < aRef.its4ImageWidth) ) return false;
   if ( ! (its6ImageHeight < aRef.its6ImageHeight) ) return false;
   if ( ! (its8NofChannels < aRef.its8NofChannels) ) return false;
   if ( ! (its9BytesPerPixel < aRef.its9BytesPerPixel) ) return false;
   if ( ! (its10ImageFormat < aRef.its10ImageFormat) ) return false;
   if ( ! (its12Timestamp < aRef.its12Timestamp) ) return false;
   if ( ! (its16FrameCounter < aRef.its16FrameCounter) ) return false;
   if ( ! (its18PreMetaData < aRef.its18PreMetaData) ) return false;
   if ( ! (its19PostMetaData < aRef.its19PostMetaData) ) return false;
   if ( ! (its20Reserved < aRef.its20Reserved) ) return false;
   if ( ! (its24Reserved < aRef.its24Reserved) ) return false;
   if ( ! (its26MainTemp < aRef.its26MainTemp) ) return false;
   if ( ! (its27LedTemp < aRef.its27LedTemp) ) return false;
   if ( ! (its28FirmwareVersion < aRef.its28FirmwareVersion) ) return false;
   if ( ! (its30MagicV31 < aRef.its30MagicV31) ) return false;
   if ( ! (its32IntegrationTime < aRef.its32IntegrationTime) ) return false;
   if ( ! (its34ModulationFreq < aRef.its34ModulationFreq) ) return false;
   if ( ! (its36Temp3 < aRef.its36Temp3) ) return false;
   if ( ! (its37ColorMode < aRef.its37ColorMode) ) return false;
   if ( ! (its38ColorSensorWidth < aRef.its38ColorSensorWidth) ) return false;
   if ( ! (its40ColorSensorHeight < aRef.its40ColorSensorHeight) ) return false;
   if ( ! (its42Reserved < aRef.its42Reserved) ) return false;
   if ( ! (its46Reserved < aRef.its46Reserved) ) return false;
   if ( ! (its48RawPhaseContent < aRef.its48RawPhaseContent) ) return false;
   if ( ! (its52Reserved < aRef.its52Reserved) ) return false;
   if ( ! (its54Reserved < aRef.its54Reserved) ) return false;
   if ( ! (its58Reserved < aRef.its58Reserved) ) return false;
   if ( ! (its62Crc16 < aRef.its62Crc16) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FrameDataInterfaceHeaderV31 & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline uint2 FrameDataInterfaceHeaderV31::Get0Reserved( ) const
{
 return its0Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set0Reserved( const uint2 & aValue )
{
 its0Reserved = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get2HeaderVersion( ) const
{
 return its2HeaderVersion;
}

inline void FrameDataInterfaceHeaderV31::Set2HeaderVersion( const uint2 & aValue )
{
 its2HeaderVersion = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get4ImageWidth( ) const
{
 return its4ImageWidth;
}

inline void FrameDataInterfaceHeaderV31::Set4ImageWidth( const uint2 & aValue )
{
 its4ImageWidth = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get6ImageHeight( ) const
{
 return its6ImageHeight;
}

inline void FrameDataInterfaceHeaderV31::Set6ImageHeight( const uint2 & aValue )
{
 its6ImageHeight = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get8NofChannels( ) const
{
 return its8NofChannels;
}

inline void FrameDataInterfaceHeaderV31::Set8NofChannels( const uint1 & aValue )
{
 its8NofChannels = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get9BytesPerPixel( ) const
{
 return its9BytesPerPixel;
}

inline void FrameDataInterfaceHeaderV31::Set9BytesPerPixel( const uint1 & aValue )
{
 its9BytesPerPixel = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get10ImageFormat( ) const
{
 return its10ImageFormat;
}

inline void FrameDataInterfaceHeaderV31::Set10ImageFormat( const uint2 & aValue )
{
 its10ImageFormat = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get12Timestamp( ) const
{
 return its12Timestamp;
}

inline void FrameDataInterfaceHeaderV31::Set12Timestamp( const uint4 & aValue )
{
 its12Timestamp = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get16FrameCounter( ) const
{
 return its16FrameCounter;
}

inline void FrameDataInterfaceHeaderV31::Set16FrameCounter( const uint2 & aValue )
{
 its16FrameCounter = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get18PreMetaData( ) const
{
 return its18PreMetaData;
}

inline void FrameDataInterfaceHeaderV31::Set18PreMetaData( const uint1 & aValue )
{
 its18PreMetaData = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get19PostMetaData( ) const
{
 return its19PostMetaData;
}

inline void FrameDataInterfaceHeaderV31::Set19PostMetaData( const uint1 & aValue )
{
 its19PostMetaData = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get20Reserved( ) const
{
 return its20Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set20Reserved( const uint4 & aValue )
{
 its20Reserved = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get24Reserved( ) const
{
 return its24Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set24Reserved( const uint2 & aValue )
{
 its24Reserved = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get26MainTemp( ) const
{
 return its26MainTemp;
}

inline void FrameDataInterfaceHeaderV31::Set26MainTemp( const uint1 & aValue )
{
 its26MainTemp = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get27LedTemp( ) const
{
 return its27LedTemp;
}

inline void FrameDataInterfaceHeaderV31::Set27LedTemp( const uint1 & aValue )
{
 its27LedTemp = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get28FirmwareVersion( ) const
{
 return its28FirmwareVersion;
}

inline void FrameDataInterfaceHeaderV31::Set28FirmwareVersion( const uint2 & aValue )
{
 its28FirmwareVersion = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get30MagicV31( ) const
{
 return its30MagicV31;
}

inline void FrameDataInterfaceHeaderV31::Set30MagicV31( const uint2 & aValue )
{
 its30MagicV31 = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get32IntegrationTime( ) const
{
 return its32IntegrationTime;
}

inline void FrameDataInterfaceHeaderV31::Set32IntegrationTime( const uint2 & aValue )
{
 its32IntegrationTime = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get34ModulationFreq( ) const
{
 return its34ModulationFreq;
}

inline void FrameDataInterfaceHeaderV31::Set34ModulationFreq( const uint2 & aValue )
{
 its34ModulationFreq = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get36Temp3( ) const
{
 return its36Temp3;
}

inline void FrameDataInterfaceHeaderV31::Set36Temp3( const uint1 & aValue )
{
 its36Temp3 = aValue;
}

inline uint1 FrameDataInterfaceHeaderV31::Get37ColorMode( ) const
{
 return its37ColorMode;
}

inline void FrameDataInterfaceHeaderV31::Set37ColorMode( const uint1 & aValue )
{
 its37ColorMode = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get38ColorSensorWidth( ) const
{
 return its38ColorSensorWidth;
}

inline void FrameDataInterfaceHeaderV31::Set38ColorSensorWidth( const uint2 & aValue )
{
 its38ColorSensorWidth = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get40ColorSensorHeight( ) const
{
 return its40ColorSensorHeight;
}

inline void FrameDataInterfaceHeaderV31::Set40ColorSensorHeight( const uint2 & aValue )
{
 its40ColorSensorHeight = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get42Reserved( ) const
{
 return its42Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set42Reserved( const uint4 & aValue )
{
 its42Reserved = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get46Reserved( ) const
{
 return its46Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set46Reserved( const uint2 & aValue )
{
 its46Reserved = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get48RawPhaseContent( ) const
{
 return its48RawPhaseContent;
}

inline void FrameDataInterfaceHeaderV31::Set48RawPhaseContent( const uint4 & aValue )
{
 its48RawPhaseContent = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get52Reserved( ) const
{
 return its52Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set52Reserved( const uint2 & aValue )
{
 its52Reserved = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get54Reserved( ) const
{
 return its54Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set54Reserved( const uint4 & aValue )
{
 its54Reserved = aValue;
}

inline uint4 FrameDataInterfaceHeaderV31::Get58Reserved( ) const
{
 return its58Reserved;
}

inline void FrameDataInterfaceHeaderV31::Set58Reserved( const uint4 & aValue )
{
 its58Reserved = aValue;
}

inline uint2 FrameDataInterfaceHeaderV31::Get62Crc16( ) const
{
 return its62Crc16;
}

inline void FrameDataInterfaceHeaderV31::Set62Crc16( const uint2 & aValue )
{
 its62Crc16 = aValue;
}






}; // End of namespace UdpFrame

#endif

