///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class SetController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 17:33:51 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Cfl_SetController_
#define _Cfl_SetController_

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

#include "MLX75123_TofCCController.h"
#include "Cfl_CalibStatusSet.h"
#include "Cfl_ConfigurationSet.h"
#include "Cfl_ErrorSet.h"
#include "Cfl_FactorySet.h"
#include "Cfl_TemperatureSet.h"


//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Cfl
namespace Cfl
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class SetController
class SetController: public MLX75123::TofCCController
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        SetController( );

   /// Destructor
       virtual  ~SetController( );

   ///Special Constructor 
        SetController( const std::string & aName
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
       virtual bool operator == (const SetController & aRef) const;
   
   /// Less operator 
       virtual bool operator < (const SetController & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{

   //@}

   ///@name Comfort functions for reading and writing tof camera registers
   //@{
        //read all tof camera calib status flags at once
         Cfl::CalibStatusSet ReadCalibStatusSet( ); 
        //read all tof camera configuration parameters at once
         Cfl::ConfigurationSet ReadConfigurationSet( ); 
        //read all tof camera error flags at once
         Cfl::ErrorSet ReadErrorSet( ); 
        //read all tof camera factory parameters at once
         Cfl::FactorySet ReadFactorySet( ); 
        //read all tof camera temperatures at once
         Cfl::TemperatureSet   ReadTemperatureSet( ); 

        //write all tof camera configuration parameters at once
         bool WriteConfigurationSet( const Cfl::ConfigurationSet & aSet ); 

        //write current RegMap to Flash
         bool WriteRegMap2Flash();
        

         //OUTDATED: for compatibility only, use the Read functions
         Cfl::CalibStatusSet GetCalibStatusSet( );                //OUTDATED
         Cfl::ConfigurationSet GetConfigurationSet( );            //OUTDATED
         Cfl::ErrorSet GetErrorSet( );                            //OUTDATED
         Cfl::FactorySet GetFactorySet( );                        //OUTDATED
         Cfl::TemperatureSet   GetTemperatureSet( );              //OUTDATED
   //@}


private:
         //   All the Elements

}; // End of class SetController

//------------------------------ Inline Functions ----------------------
inline bool SetController::operator == (const SetController & aRef) const
{
   if ( ! Rtl16::RegController::operator == (aRef) )  return false;

   return true;
}

inline bool SetController::operator < (const SetController & aRef) const
{
   if ( ! Rtl16::RegController::operator < (aRef) )  return false;

   return true; 
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const SetController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}


//OUTDATED: for compatibility only

inline Cfl::CalibStatusSet SetController::GetCalibStatusSet( ) 
{
         return ReadCalibStatusSet( );
}

inline Cfl::ConfigurationSet SetController::GetConfigurationSet( ) 
{
         return ReadConfigurationSet( ); 
}

inline Cfl::ErrorSet SetController::GetErrorSet( ) 
{
         return ReadErrorSet( ); 
}

inline Cfl::FactorySet SetController::GetFactorySet( ) 
{
         return ReadFactorySet( ); 
}

inline Cfl::TemperatureSet SetController::GetTemperatureSet( ) 
{
         return ReadTemperatureSet( ); 
}




}; // End of namespace Cfl

#endif

