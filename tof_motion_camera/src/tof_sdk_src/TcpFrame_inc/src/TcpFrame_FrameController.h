///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class FrameController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Fri Apr 21 10:43:46 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _TcpFrame_FrameController_
#define _TcpFrame_FrameController_

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


/// The namespace TcpFrame
namespace TcpFrame
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
                      , const std::string & aPeerTcpAddress
                      , const uint2 & aPeerTcpPort
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
         // The member PeerTcpAddress
         ///  The Get function for member PeerTcpAddress
              std::string   GetPeerTcpAddress( ) const;
         ///  The Set function for member PeerTcpAddress
              void    SetPeerTcpAddress( const std::string & aValue );
         //----------------------------------------------------
         // The member MicroSecondsTimeout
         ///  The Get function for member MicroSecondsTimeout
              uint4   GetMicroSecondsTimeout( ) const;
         ///  The Set function for member MicroSecondsTimeout
              void    SetMicroSecondsTimeout( const uint4 & aValue );
         //----------------------------------------------------
         // The member SecondsTimeout
         ///  The Get function for member SecondsTimeout
              uint4   GetSecondsTimeout( ) const;
         ///  The Set function for member SecondsTimeout
              void    SetSecondsTimeout( const uint4 & aValue );
         //----------------------------------------------------
         // The member TcpSocket
         ///  The Get function for member TcpSocket
              IO::Socket   GetTcpSocket( ) const;
         ///  The Set function for member TcpSocket
              void    SetTcpSocket( const IO::Socket & aValue );
         //----------------------------------------------------
         // The member PeerTcpPort
         ///  The Get function for member PeerTcpPort
              uint2   GetPeerTcpPort( ) const;
         ///  The Set function for member PeerTcpPort
              void    SetPeerTcpPort( const uint2 & aValue );
         //----------------------------------------------------
         // The member TcpSelect
         ///  The Get function for member TcpSelect
              IO::SelectWithSockets   GetTcpSelect( ) const;
         ///  The Set function for member TcpSelect
              void    SetTcpSelect( const IO::SelectWithSockets & aValue );
         //----------------------------------------------------
         // The ReadRegister function
              bool ReadRegister( const uint2 & aRegisterAddress, uint2 & RegisterValueRef );  
         // The WriteRegister function
              bool WriteRegister( const uint2 & aRegisterAddress, const uint2 & RegisterValueRef );

   //@}

private:
  
   // The CRC16ccitt function
         uint2 CRC16ccitt( uint1 * aBuffer, const uint2 & aBufferSize ) const;

   //   All the Elements

         std::string itsPeerTcpAddress;
         uint4 itsMicroSecondsTimeout;
         uint4 itsSecondsTimeout;
         IO::Socket itsTcpSocket;
         uint2 itsPeerTcpPort;
         IO::SelectWithSockets itsTcpSelect;


}; // End of class FrameController

//------------------------------ Inline Functions ----------------------
inline bool FrameController::operator == (const FrameController & aRef) const
{
   if ( ! (itsPeerTcpAddress == aRef.itsPeerTcpAddress) ) return false;
   if ( ! (itsMicroSecondsTimeout == aRef.itsMicroSecondsTimeout) ) return false;
   if ( ! (itsSecondsTimeout == aRef.itsSecondsTimeout) ) return false;
   if ( ! (itsTcpSocket == aRef.itsTcpSocket) ) return false;
   if ( ! (itsPeerTcpPort == aRef.itsPeerTcpPort) ) return false;
   if ( ! (itsTcpSelect == aRef.itsTcpSelect) ) return false;

   return true;
}

inline bool FrameController::operator < (const FrameController & aRef) const
{
   if ( ! (itsPeerTcpAddress < aRef.itsPeerTcpAddress) ) return false;
   if ( ! (itsMicroSecondsTimeout < aRef.itsMicroSecondsTimeout) ) return false;
   if ( ! (itsSecondsTimeout < aRef.itsSecondsTimeout) ) return false;
   if ( ! (itsTcpSocket < aRef.itsTcpSocket) ) return false;
   if ( ! (itsPeerTcpPort < aRef.itsPeerTcpPort) ) return false;
   if ( ! (itsTcpSelect < aRef.itsTcpSelect) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const FrameController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline std::string FrameController::GetPeerTcpAddress( ) const
{
 return itsPeerTcpAddress;
}

inline void FrameController::SetPeerTcpAddress( const std::string & aValue )
{
 itsPeerTcpAddress = aValue;
}
inline uint4 FrameController::GetMicroSecondsTimeout( ) const
{
 return itsMicroSecondsTimeout;
}

inline void FrameController::SetMicroSecondsTimeout( const uint4 & aValue )
{
 itsMicroSecondsTimeout = aValue;
}
inline uint4 FrameController::GetSecondsTimeout( ) const
{
 return itsSecondsTimeout;
}

inline void FrameController::SetSecondsTimeout( const uint4 & aValue )
{
 itsSecondsTimeout = aValue;
}
inline IO::Socket FrameController::GetTcpSocket( ) const
{
 return itsTcpSocket;
}

inline void FrameController::SetTcpSocket( const IO::Socket & aValue )
{
 itsTcpSocket = aValue;
}
inline uint2 FrameController::GetPeerTcpPort( ) const
{
 return itsPeerTcpPort;
}

inline void FrameController::SetPeerTcpPort( const uint2 & aValue )
{
 itsPeerTcpPort = aValue;
}
inline IO::SelectWithSockets FrameController::GetTcpSelect( ) const
{
 return itsTcpSelect;
}

inline void FrameController::SetTcpSelect( const IO::SelectWithSockets & aValue )
{
 itsTcpSelect = aValue;
}


}; // End of namespace TcpFrame

#endif

