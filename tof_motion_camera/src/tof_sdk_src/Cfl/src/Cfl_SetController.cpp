///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4153 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class SetController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Mon Aug 14 17:33:51 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"

#include <sstream>   
#include <cstdio>

#include "Cfl_SetController.h"
#include "Common_LogFormat.h"

//CalibStatusSet
#include "Rtl16_CalibStatusReg.h"
#include "Rtl16_CalibStatus2Reg.h"

//ConfiguarationSet
#include "Rtl16_ImageDataFormatReg.h"
#include "Rtl16_HardwareConfigurationReg.h"
#include "Rtl16_Mode0Reg.h"
#include "Rtl16_Eth0ConfigReg.h"
#include "Rtl16_Eth0Gateway0Reg.h"
#include "Rtl16_Eth0Gateway1Reg.h"
#include "Rtl16_Eth0Ip0Reg.h"
#include "Rtl16_Eth0Ip1Reg.h"
#include "Rtl16_Eth0Snm0Reg.h"
#include "Rtl16_Eth0Snm1Reg.h"
#include "Rtl16_Eth0UdpStreamIp0Reg.h"
#include "Rtl16_Eth0UdpStreamIp1Reg.h"
#include "Rtl16_Eth0TcpCtrlPortReg.h"
#include "Rtl16_Eth0UdpStreamPortReg.h"


//ErrorSet
#include "Rtl16_StatusReg.h"
#include "Rtl16_Status2Reg.h"


//FactorySet
#include "Rtl16_SerialNumberHighWordReg.h"
#include "Rtl16_SerialNumberLowWordReg.h"
#include "Rtl16_BootStatusReg.h"
#include "Rtl16_FirmwareInfoReg.h"
#include "Rtl16_BuildDayHourReg.h"
#include "Rtl16_BuildMinuteSecondReg.h"
#include "Rtl16_BuildYearMonthReg.h"
#include "Rtl16_FactoryHourMinuteReg.h"
#include "Rtl16_FactoryTimezoneReg.h"
#include "Rtl16_FactoryYearReg.h"
#include "Rtl16_FactoryMonthDayReg.h"
#include "Rtl16_DeviceTypeReg.h"
#include "Rtl16_FactoryMacAddr0Reg.h"
#include "Rtl16_FactoryMacAddr1Reg.h"
#include "Rtl16_FactoryMacAddr2Reg.h"

//TemperatureSet
#include "Rtl16_BaseBoardTempReg.h"
#include "Rtl16_LedBoardTempReg.h"
#include "Rtl16_MainBoardTempReg.h"
#include "Rtl16_ProcessorStatusReg.h"
#include "Rtl16_StatusReg.h"
#include "Rtl16_Status2Reg.h"
#include "Rtl16_MaxLedTempReg.h"


//Save RegMap 
#include "Rtl16_CmdEnablePasswdReg.h"
#include "Rtl16_CmdExecReg.h"



//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace MLX75123;
using namespace Rtl16;
using namespace Cfl;

//------------------------------ Constructor -------------------

SetController::SetController ( ) 
: TofCCController ( )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

SetController::SetController( const std::string & aName
                            , const std::string & aPeerTcpAddress
                            , const uint2 & aPeerTcpPort
                            , const Common::UseLogger::LogLevel_e & aLogLevel
                            , const uint4 & aSecondsTimeout
                            , const uint4 & aMicroSecondsTimeout
                              )
: MLX75123::TofCCController (
  aName
, aPeerTcpAddress
, aPeerTcpPort
, aLogLevel
, aSecondsTimeout
, aMicroSecondsTimeout 
)
{
 ///nothing
}

//------------------------------ Destructor ----------------------------

SetController::~SetController (  ) 
{
  /// nothing
}


bool SetController::WriteRegMap2Flash( )
{

 LOGLOG()<<"write RegMap to flash"<<std::endl;

 CmdEnablePasswdReg r1;
 CmdExecReg r2;

 r1.SetPasswordForCriticalOperations(Rtl16::CmdEnablePasswdReg::REGISTERMAP_FLASH_OPERATIONS);
 r2.SetInitiateAnOperation(Rtl16::CmdExecReg::SAVE_REGMAP_FLASH);

 WriteRegister(r1);
 WriteRegister(r2);

 return true;
}



CalibStatusSet  SetController::ReadCalibStatusSet( )
{

 CalibStatusSet c;

 CalibStatusReg r1;
 ReadRegister(r1);
 c.SetCalibErrorOccured(r1.GetErrorOccured());
 c.SetNoFPPNCalibrationDataInNVRAM(r1.GetNoFPPNCalibrationDataInNVRAM());
 c.SetNoLensCalibrationDataInNVRAM(r1.GetNoLensCalibrationDataInNVRAM());
 c.SetStatus(r1.GetStatus());


 CalibStatus2Reg r2;
 ReadRegister(r2);
 c.SetNoWigglingCalibrationInNVRAM(r2.GetNoWigglingCalibration());

 return c;
}


ConfigurationSet  SetController::ReadConfigurationSet( )
{

 ConfigurationSet c;

 ImageDataFormatReg r1;
 ReadRegister(r1);
 c.SetImageDataFormat(r1.GetImageDataFormat());

 HardwareConfigurationReg r2;
 ReadRegister(r2);
 c.SetLensOpeningAngleIdentifier(r2.GetLensOpeningAngleIdentifier());

 Mode0Reg r3;
 ReadRegister(r3);
 c.SetIsInManualTrigger(r3.GetManualTrigger());

 Eth0ConfigReg r4;
 ReadRegister(r4);
 c.SetEnableDHCPFlag(r4.GetEnableDHCP());
 c.SetEnableUdpStreamingFlag(r4.GetEnableUdpStreaming());
 c.SetIgnoreCrcForUdpStreamingFlag(r4.GetIgnoreCrcForUdpStreaming());

 
 Eth0Ip1Reg r5;
 ReadRegister(r5);
 
 Eth0Ip0Reg r6;
 ReadRegister(r6);

 {
 std::ostringstream tmpStream;
 tmpStream << r5.GetIpAddressHighByte() << "." << r5.GetIpAddressLowByte() << "." << r6.GetIpAddressHighByte() << "." <<r6.GetIpAddressLowByte();
 c.SetIpAddress(tmpStream.str());
 }

 Eth0Snm1Reg r7;
 ReadRegister(r7);
 
 Eth0Snm0Reg r8;
 ReadRegister(r8);

 {
 std::ostringstream tmpStream;
 tmpStream << r7.GetIpAddressHighByte() << "." << r7.GetIpAddressLowByte() << "." << r8.GetIpAddressHighByte() << "." <<r8.GetIpAddressLowByte();
 c.SetNetmask(tmpStream.str());
 }

 Eth0Gateway1Reg r9;
 ReadRegister(r9);
 
 Eth0Gateway0Reg r10;
 ReadRegister(r10);

 {
 std::ostringstream tmpStream;
 tmpStream << r9.GetIpAddressHighByte() << "." << r9.GetIpAddressLowByte() << "." << r10.GetIpAddressHighByte() << "." <<r10.GetIpAddressLowByte();
 c.SetGateway(tmpStream.str());
 }

 Eth0TcpCtrlPortReg r11;
 ReadRegister(r11);
 c.SetTcpCtrlPort(r11.GetTcpCtrlPort());

 Eth0UdpStreamIp1Reg r12;
 ReadRegister(r12);
 
 Eth0UdpStreamIp0Reg r13;
 ReadRegister(r13);

 {
 std::ostringstream tmpStream;
 tmpStream << r12.GetIpAddressHighByte() << "." << r12.GetIpAddressLowByte() << "." << r13.GetIpAddressHighByte() << "." <<r13.GetIpAddressLowByte();
 c.SetUdpStreamAddress(tmpStream.str());
 }

 Eth0UdpStreamPortReg r14;
 ReadRegister(r14);
 c.SetUdpStreamPort(r14.GetUdpStreamPort());

 return c;
}


bool  SetController::WriteConfigurationSet( const Cfl::ConfigurationSet & aSet )
{

{
 ImageDataFormatReg r1;
 r1.SetImageDataFormat(aSet.GetImageDataFormat());
 WriteRegister(r1);
}

{
 HardwareConfigurationReg r2;
 r2.SetLensOpeningAngleIdentifier(aSet.GetLensOpeningAngleIdentifier());
 WriteRegister(r2);
}
 
//SKIPPED: register Mode0 is considered readonly here, manual trigger needs to be triggered via MLX75123 controller only

{
 Eth0ConfigReg r4;
 r4.SetEnableDHCP(aSet.GetEnableDHCPFlag());
 r4.SetEnableUdpStreaming(aSet.GetEnableUdpStreamingFlag());
 r4.SetIgnoreCrcForUdpStreaming(aSet.GetIgnoreCrcForUdpStreamingFlag());
 WriteRegister(r4);
}

{
 Eth0Ip1Reg r5;
 Eth0Ip0Reg r6;
 std::string tmpAddress = aSet.GetIpAddress();
 uint2 ip1high, ip1low, ip0high, ip0low;
 int return_result = sscanf(tmpAddress.c_str(), "%hu.%hu.%hu.%hu", &ip1high, &ip1low, &ip0high, &ip0low);
 LOG_ASSERT(return_result, "WriteConfigurationSet: failed sscanf:" <<tmpAddress); 

 r5.SetIpAddressHighByte(ip1high);
 r5.SetIpAddressLowByte(ip1low);
 r6.SetIpAddressHighByte(ip0high);
 r6.SetIpAddressLowByte(ip0low);
 WriteRegister(r6);
 WriteRegister(r5);
}

{
 Eth0Snm1Reg r7;
 Eth0Snm0Reg r8;
 std::string tmpAddress = aSet.GetNetmask();
 uint2 ip1high, ip1low, ip0high, ip0low;
 int return_result = sscanf(tmpAddress.c_str(), "%hu.%hu.%hu.%hu", &ip1high, &ip1low, &ip0high, &ip0low);
 LOG_ASSERT(return_result, "WriteConfigurationSet: failed sscanf:" <<tmpAddress);

 r7.SetIpAddressHighByte(ip1high);
 r7.SetIpAddressLowByte(ip1low);
 r8.SetIpAddressHighByte(ip0high);
 r8.SetIpAddressLowByte(ip0low);
 WriteRegister(r8);
 WriteRegister(r7);
}

{
 Eth0TcpCtrlPortReg r11;
 r11.SetTcpCtrlPort(aSet.GetTcpCtrlPort());
 WriteRegister(r11);
}

{
 Eth0UdpStreamPortReg r14;
 r14.SetUdpStreamPort(aSet.GetUdpStreamPort());
 WriteRegister(r14);
}


//NOTE: these are the last commands we can write here, then the contact to the camera may be lost
//NOTE: instantiate new controllers, if you changed this configuration parameters
{
 Eth0UdpStreamIp1Reg r12;
 Eth0UdpStreamIp0Reg r13;
 std::string tmpAddress = aSet.GetUdpStreamAddress();
 uint2 ip1high, ip1low, ip0high, ip0low;
 int return_result = sscanf(tmpAddress.c_str(), "%hu.%hu.%hu.%hu", &ip1high, &ip1low, &ip0high, &ip0low);
 LOG_ASSERT(return_result, "WriteConfigurationSet: failed sscanf:" <<tmpAddress);

 r12.SetIpAddressHighByte(ip1high);
 r12.SetIpAddressLowByte(ip1low);
 r13.SetIpAddressHighByte(ip0high);
 r13.SetIpAddressLowByte(ip0low);
 WriteRegister(r13);
 WriteRegister(r12);
}

{
 Eth0Gateway1Reg r9;
 Eth0Gateway0Reg r10;
 std::string tmpAddress = aSet.GetGateway();
 uint2 ip1high, ip1low, ip0high, ip0low;
 int return_result = sscanf(tmpAddress.c_str(), "%hu.%hu.%hu.%hu", &ip1high, &ip1low, &ip0high, &ip0low);
 LOG_ASSERT(return_result, "WriteConfigurationSet: failed sscanf:" <<tmpAddress);

 r9.SetIpAddressHighByte(ip1high);
 r9.SetIpAddressLowByte(ip1low);
 r10.SetIpAddressHighByte(ip0high);
 r10.SetIpAddressLowByte(ip0low);
 WriteRegister(r10);
 WriteRegister(r9);
}

 return true;
}








ErrorSet  SetController::ReadErrorSet( )
{

 ErrorSet e;

 StatusReg r1;
 ReadRegister(r1);
 e.SetIlluminationTemperatureSensorError(r1.GetIlluminationTemperatureSensorError());
 e.SetTofSensorTemperatureSensorError(r1.GetTofSensorTemperatureSensorError());
 e.SetIlluminationError(r1.GetIlluminationError());
 e.SetTofCCTemperatureError(r1.GetTofCCTemperatureError());
 e.SetTofCCPLLConfigurationError(r1.GetTofCCPLLConfigurationError());
 e.SetIlluminationOverTemperature(r1.GetIlluminationOverTemperature());
 e.SetCalibrationDataMissing(r1.GetCalibrationDataMissing());


 Status2Reg r2;
 ReadRegister(r2);
 e.SetSerdesError(r2.GetSerdesError());
 e.SetCaptureError(r2.GetCaptureError());
 e.SetCaptureTimeout(r2.GetCaptureTimeout());
 e.SetApplicationProcessorTooHot(r2.GetApplicationProcessorTooHot());

 return e;
}



FactorySet  SetController::ReadFactorySet( )
{

 FactorySet f;
 
 SerialNumberHighWordReg r1;
 ReadRegister(r1);
 uint4 highword = r1.GetSerialNumberHighWord();

 SerialNumberLowWordReg r2;
 ReadRegister(r2);
 uint4 lowword = r2.GetSerialNumberLowWord();

 f.SetSerialNumber( (highword << 16) + lowword );

 BootStatusReg r3;
 ReadRegister(r3);
 f.SetFirmwareLoadCounter(r3.GetFirmwareLoadCounter());

 FirmwareInfoReg r4;
 ReadRegister(r4);

 {
 std::ostringstream tmpStream;
 tmpStream << r4.GetRevisionMajor() << "." << r4.GetRevisionMinor() << "." << r4.GetRevisionNonFunctional();
 f.SetFirmwareRevisionInfo(tmpStream.str());
 }

 BuildDayHourReg r5;
 ReadRegister(r5);
 BuildMinuteSecondReg r6;
 ReadRegister(r6);
 BuildYearMonthReg r7;
 ReadRegister(r7);

 {
 std::ostringstream tmpStream;
 tmpStream << r7.GetYear() << "-" << r7.GetMonth() << "-" << r5.GetDay() << "-" << r5.GetHour() << ":" << r6.GetMinute() << ":" << r6.GetSecond();
 f.SetFirmwareBuildInfo(tmpStream.str());
 }

 FactoryHourMinuteReg r8;
 ReadRegister(r8);
 FactoryTimezoneReg r9;
 ReadRegister(r9);
 FactoryYearReg r10;
 ReadRegister(r10);
 FactoryMonthDayReg r11;
 ReadRegister(r11);

 {
 std::ostringstream tmpStream;
 tmpStream << r10.GetProductionYear() << "-" << r11.GetProductionMonth() << "-" << r11.GetProductionDay() << "-" << r8.GetProductionHour() << ":" << r8.GetProductionMinute() << "(" << r9.GetProductionTimezone()<<")";
 f.SetFactoryBuildInfo(tmpStream.str());
 }

 DeviceTypeReg r12;
 ReadRegister(r12);
 f.SetHardwareSpecificIdentification(r12.GetHardwareSpecificIdentification());

 FactoryMacAddr0Reg r13;
 ReadRegister(r13);

 FactoryMacAddr1Reg r14;
 ReadRegister(r14);

 FactoryMacAddr2Reg r15;
 ReadRegister(r15);

 {
 std::ostringstream tmpStream;
 tmpStream << std::hex << r15.GetByte5()<<":"<< r15.GetByte4() << ":" << r14.GetByte3()<<":"<< r14.GetByte2()  << ":" << r13.GetByte1()<<":"<< r13.GetByte0(); 
 f.SetFactoryMacAddress(tmpStream.str());
 }

 return f;
}



TemperatureSet  SetController::ReadTemperatureSet( )
{

 TemperatureSet t;
 
 BaseBoardTempReg r1;
 ReadRegister(r1);
 t.SetBaseboardTemp_deg(r1.GetBaseBoardTemp_deg100() / 100.0);

 LedBoardTempReg r2;
 ReadRegister(r2);
 t.SetLaserboardTemp_deg(r2.GetLedBoardTemp_deg100() / 100.0);

 MainBoardTempReg r3;
 ReadRegister(r3);
 t.SetMainboardTemp_deg(r3.GetMainBoardTemp_deg100() / 100.0);

 ProcessorStatusReg r4;
 ReadRegister(r4);
 t.SetProcessorTemp_deg(r4.GetProcessorTemp_deg());
 t.SetProcessorSpeed_MHz(r4.GetProcessorSpeed_10MHz() * 10);

 Status2Reg r5;
 ReadRegister(r5);
 t.SetProcessorTooHotFlag(r5.GetApplicationProcessorTooHot());
 
 StatusReg r6;
 ReadRegister(r6);
 t.SetLaserboardOverTempFlag(r6.GetIlluminationOverTemperature());
 t.SetLaserboardTempErrorFlag(r6.GetIlluminationTemperatureSensorError());

 MaxLedTempReg r7;
 ReadRegister(r7);
 t.SetLaserboardTempLimit_deg(r7.GetMaxLedTemp_deg100() / 100.0);

 
 return t;
}


//------------------------------ Logging ------------------------------
void SetController::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void SetController::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Cfl_SetController" );
   {
    aLogFormat . LogElement( aStreamRef, "MLX75123_TofCCController" );
    MLX75123::TofCCController::Log(aStreamRef, aLogFormat);
   }
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
