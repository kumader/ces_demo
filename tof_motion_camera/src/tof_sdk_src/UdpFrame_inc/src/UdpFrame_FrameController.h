///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2383 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FrameController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Apr 17 14:27:18 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _UdpFrame_FrameController_
#define _UdpFrame_FrameController_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#include "IO_Socket.h"
#include "IO_SelectWithSockets.h"
#include "Common_UseLogger.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }


/// The namespace UdpFrame
namespace UdpFrame
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class FrameController
class FrameController : public Common::UseLogger
{
public:

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor (USE ONLY FOR REGRESSIONTEST)
        FrameController( );

   /// Destructor
        virtual ~FrameController( );

   ///Special Constructor 
        FrameController( const std::string & aName
                      , const uint2 & aLocalUdpPort
                      , const Common::UseLogger::LogLevel_e & aLogLevel       = Common::UseLogger::S_INFO
                      , const uint4 & aSecondsTimeout      = 0
                      , const uint4 & aMicroSecondsTimeout = 0
                      );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const FrameController & aRef) const;
   
   /// Less operator 
       bool operator < (const FrameController & aRef) const;

   ///@name Set and Get functions for all members 
   //@{
         // The member UdpSocket
         ///  The Get function for member UdpSocket
              IO::Socket   GetUdpSocket( ) const;
         ///  The Set function for member UdpSocket
              void    SetUdpSocket( const IO::Socket & aValue );
         //----------------------------------------------------
         // The member UdpSelect
         ///  The Get function for member UdpSelect
              IO::SelectWithSockets   GetUdpSelect( ) const;
         ///  The Set function for member UdpSelect
              void    SetUdpSelect( const IO::SelectWithSockets & aValue );
         //----------------------------------------------------
         // The member SecondsTimeout
         ///  The Get function for member SecondsTimeout
              uint4   GetSecondsTimeout( ) const;
         ///  The Set function for member SecondsTimeout
              void    SetSecondsTimeout( const uint4 & aValue );
         //----------------------------------------------------
         // The member MicroSecondsTimeout
         ///  The Get function for member MicroSecondsTimeout
              uint4   GetMicroSecondsTimeout( ) const;
         ///  The Set function for member MicroSecondsTimeout
              void    SetMicroSecondsTimeout( const uint4 & aValue );
         //----------------------------------------------------
         // The member LocalUdpPort
         ///  The Get function for member LocalUdpPort
              uint2   GetLocalUdpPort( ) const;
         ///  The Set function for member LocalUdpPort
              void    SetLocalUdpPort( const uint2 & aValue );
         //----------------------------------------------------

         ///  The GetFrame function
         bool GetFrame (uint1 * aFramePtr, const uint4 & aFrameSize, uint4 & aFrameOffsetRef);

   //@}

private:

   //   All the Elements

         IO::Socket itsUdpSocket;
         IO::SelectWithSockets itsUdpSelect;
         uint4 itsSecondsTimeout;
         uint4 itsMicroSecondsTimeout;
         uint2 itsLocalUdpPort;


}; // End of class FrameController

//------------------------------ Inline Functions ----------------------
inline bool FrameController::operator == (const FrameController & aRef) const
{
   if ( ! (itsUdpSocket == aRef.itsUdpSocket) ) return false;
   if ( ! (itsUdpSelect == aRef.itsUdpSelect) ) return false;
   if ( ! (itsSecondsTimeout == aRef.itsSecondsTimeout) ) return false;
   if ( ! (itsMicroSecondsTimeout == aRef.itsMicroSecondsTimeout) ) return false;
   if ( ! (itsLocalUdpPort == aRef.itsLocalUdpPort) ) return false;

   return true;
}

inline bool FrameController::operator < (const FrameController & aRef) const
{
   if ( ! (itsUdpSocket < aRef.itsUdpSocket) ) return false;
   if ( ! (itsUdpSelect < aRef.itsUdpSelect) ) return false;
   if ( ! (itsSecondsTimeout < aRef.itsSecondsTimeout) ) return false;
   if ( ! (itsMicroSecondsTimeout < aRef.itsMicroSecondsTimeout) ) return false;
   if ( ! (itsLocalUdpPort < aRef.itsLocalUdpPort) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FrameController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline IO::Socket FrameController::GetUdpSocket( ) const
{
 return itsUdpSocket;
}

inline void FrameController::SetUdpSocket( const IO::Socket & aValue )
{
 itsUdpSocket = aValue;
}
inline IO::SelectWithSockets FrameController::GetUdpSelect( ) const
{
 return itsUdpSelect;
}

inline void FrameController::SetUdpSelect( const IO::SelectWithSockets & aValue )
{
 itsUdpSelect = aValue;
}
inline uint4 FrameController::GetSecondsTimeout( ) const
{
 return itsSecondsTimeout;
}

inline void FrameController::SetSecondsTimeout( const uint4 & aValue )
{
 itsSecondsTimeout = aValue;
}
inline uint4 FrameController::GetMicroSecondsTimeout( ) const
{
 return itsMicroSecondsTimeout;
}

inline void FrameController::SetMicroSecondsTimeout( const uint4 & aValue )
{
 itsMicroSecondsTimeout = aValue;
}
inline uint2 FrameController::GetLocalUdpPort( ) const
{
 return itsLocalUdpPort;
}

inline void FrameController::SetLocalUdpPort( const uint2 & aValue )
{
 itsLocalUdpPort = aValue;
}


}; // End of namespace UdpFrame

#endif

