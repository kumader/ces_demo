///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- RegController
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class RegController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Jul 19 20:33:27 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Rtl16_RegController_
#define _Rtl16_RegController_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8
#define WIN32_LEAN_AND_MEAN
#include <ws2tcpip.h>
#else
#include <arpa/inet.h>
#endif

#include <string>

#include "TcpFrame_FrameController.h"
#include "TcpFrame_FrameStatistics.h"
#include "Rtl16_Virtual16BitReg.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Rtl16
namespace Rtl16
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class RegController
class RegController: public TcpFrame::FrameController, public TcpFrame::FrameStatistics
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        RegController( );

   /// Destructor
       virtual ~RegController( );

   ///Special Constructor 
        RegController( const std::string & aName
                     , const std::string & aPeerTcpAddress
                     , const uint2 & aPeerTcpPort
                     , const Common::UseLogger::LogLevel_e & aLogLevel       = Common::UseLogger::S_INFO
                     , const uint4 & aSecondsTimeout      = 0
                     , const uint4 & aMicroSecondsTimeout = 0
                     );

   /// Write human readable representation of content
        virtual void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        virtual void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       virtual bool operator == (const RegController & aRef) const;
   
   /// Less operator 
       virtual bool operator < (const RegController & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{

   //@}

   ///@name Comfort functions for reading and writing tof camera registers
   //@{
         bool    ReadRegister(Rtl16::Virtual16BitReg & aRegisterRef );
         bool    WriteRegister(const Rtl16::Virtual16BitReg & aRegister );

        
         //using uint2 values 
         bool    ReadRegister(const uint2 & a0Addr, uint2 & a0RegRef );
         bool    WriteRegister(const uint2 & a0Addr, const uint2 & a0Reg );

   //@}


private:
  
   //   nothing


}; // End of class RegController

//------------------------------ Inline Functions ----------------------
inline bool RegController::operator == (const RegController & aRef) const
{
   if ( ! TcpFrame::FrameController::operator == (aRef) )  return false;
   if ( ! TcpFrame::FrameStatistics::operator == (aRef) )  return false;

   return true;
}

inline bool RegController::operator < (const RegController & aRef) const
{
   if ( ! TcpFrame::FrameController::operator < (aRef) )  return false;
   if ( ! TcpFrame::FrameStatistics::operator < (aRef) )  return false;

   return true;
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const RegController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

}; // End of namespace Rtl16

#endif

