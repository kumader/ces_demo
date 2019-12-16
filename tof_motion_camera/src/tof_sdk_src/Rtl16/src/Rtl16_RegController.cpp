///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- RegController
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class RegController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Wed Jul 19 20:33:27 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Rtl16_RegController.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Rtl16;

//------------------------------ Constructor -------------------

RegController::RegController ( ) 
: TcpFrame::FrameController ( )
, TcpFrame::FrameStatistics ( )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

RegController::RegController( const std::string & aName
                            , const std::string & aPeerTcpAddress
                            , const uint2 & aPeerTcpPort
                            , const Common::UseLogger::LogLevel_e & aLogLevel
                            , const uint4 & aSecondsTimeout
                            , const uint4 & aMicroSecondsTimeout
                              )
: TcpFrame::FrameController (
  aName
, aPeerTcpAddress
, aPeerTcpPort
, aLogLevel
, aSecondsTimeout
, aMicroSecondsTimeout 
)
, TcpFrame::FrameStatistics ( )
{
 ///nothing
}

//------------------------------ Destructor ----------------------------

RegController::~RegController (  ) 
{
  /// nothing
}

bool RegController::ReadRegister(Rtl16::Virtual16BitReg & aRegisterRef )
{
 TcpFrame::FrameStatistics::Start();

 uint2 regValue;
 LOG_ASSERT(TcpFrame::FrameController::ReadRegister(aRegisterRef.GetAddr(),regValue),"ReadRegister() failed");
 TcpFrame::FrameStatistics::Update(sizeof(regValue));
 DEBUGLOG() << "R "<<aRegisterRef.GetAddr()<<" "<<std::hex<<"0x"<<regValue<<std::dec<<" "<<regValue<<std::endl;

 aRegisterRef.SetReg(regValue);

 return true;
}

bool RegController::WriteRegister(const Rtl16::Virtual16BitReg & aRegister )
{
 TcpFrame::FrameStatistics::Start();
 LOG_ASSERT(TcpFrame::FrameController::WriteRegister(aRegister.GetAddr(),aRegister.GetReg()),"WriteRegister() failed");
 TcpFrame::FrameStatistics::Update(sizeof(aRegister.GetReg()));
 DEBUGLOG() << "W "<<aRegister.GetAddr()<<" "<<std::hex<<"0x"<<aRegister.GetReg()<<std::dec<<" "<<aRegister.GetReg()<<std::endl;
 return true;
}


bool RegController::ReadRegister(const uint2 & aAddr, uint2 & aRegRef)
{
 TcpFrame::FrameStatistics::Start();

 LOG_ASSERT(TcpFrame::FrameController::ReadRegister(aAddr,aRegRef),"ReadRegister() failed");
 TcpFrame::FrameStatistics::Update(sizeof(aRegRef));
 DEBUGLOG() << "R "<<aAddr<<" "<<std::hex<<"0x"<<aRegRef<<std::dec<<" "<<aRegRef<<std::endl;

 return true;
}

bool RegController::WriteRegister(const uint2 & aAddr, const uint2 & aReg)
{
 TcpFrame::FrameStatistics::Start();
 LOG_ASSERT(TcpFrame::FrameController::WriteRegister(aAddr,aReg),"WriteRegister() failed");
 TcpFrame::FrameStatistics::Update(sizeof(aReg));
 DEBUGLOG() << "W "<<aAddr<<" "<<std::hex<<"0x"<<aReg<<std::dec<<" "<<aReg<<std::endl;
 return true;
}

//------------------------------ Logging ------------------------------
void RegController::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void RegController::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Rtl16_RegController" );
   {
    aLogFormat . LogElement( aStreamRef, "TcpFrame_FrameController" );
    TcpFrame::FrameController::Log(aStreamRef, aLogFormat);
    aLogFormat . LogElement( aStreamRef, "TcpFrame_FrameStatistics" );
    TcpFrame::FrameStatistics::Log(aStreamRef, aLogFormat);
   }
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
