///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The implementation for class TofCCController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Jun 25 16:27:49 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "MLX75123_TofCCController.h"
#include "Common_LogFormat.h"

#include "Rtl16_BaseBoardTempReg.h"
#include "Rtl16_LedBoardTempReg.h"
#include "Rtl16_MainBoardTempReg.h"
#include "Rtl16_ProcessorStatusReg.h"
#include "Rtl16_StatusReg.h"
#include "Rtl16_Status2Reg.h"
#include "Rtl16_MaxLedTempReg.h"
#include "Rtl16_ADC_DELAY_FT_Reg.h"
#include "Rtl16_Tx_IDLETIMEy_Reg.h"
#include "Rtl16_Tx_MODE_Reg.h"
#include "Rtl16_Tx_Py_INTz_Reg.h"
#include "Rtl16_TimClockReg.h"
#include "Rtl16_IllPowerReg.h"
#include "Rtl16_MixhVoltageReg.h"
#include "Rtl16_Tx_ROI_START_Reg.h"
#include "Rtl16_Tx_ROI_SIZE_Reg.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace MLX75123;
using namespace Rtl16;

//------------------------------ Constructor -------------------

TofCCController::TofCCController ( ) 
: RegController ( )

{
  /// nothing
}


//------------------------------ Special Constructor -------------------

TofCCController::TofCCController( const std::string & aName
                              , const std::string & aPeerTcpAddress
                              , const uint2 & aPeerTcpPort
                              , const Common::UseLogger::LogLevel_e & aLogLevel
                              , const uint4 & aSecondsTimeout
                              , const uint4 & aMicroSecondsTimeout
                              )
: Rtl16::RegController (
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

TofCCController::~TofCCController (  ) 
{
  /// nothing
}


//------------------------------ Helper Functions ----------------------------
uint2  TofCCController::GetFin_MHz( ) 
{

 TimClockReg r;
 ReadRegister(r);
 return r.GetReg() / 100;
}

TofCCController::FrameTable_e  TofCCController::GetFrameTable( )
{
 ADC_DELAY_FT_Reg r;
 ReadRegister(r);

 if (! r.GetFRAME_TABLE()) return TofCCController::T1;
 return TofCCController::T2;
}

bool  TofCCController::GetDivs( const FrameTable_e & aFrameTable, uint2& aNDiv, uint2& aRDiv)
{
  switch (aFrameTable)  
  {
   case T1: {
           Tx_MODE_Reg t(Tx_MODE_Reg::T1_MODE, 0);
           ReadRegister(t);   
           aNDiv=t.GetTx_NDIV() + 3;
           aRDiv=t.GetTx_RDIV() + 3;
           return true;
           }
           break;
   case T2: { 
           Tx_MODE_Reg t(Tx_MODE_Reg::T2_MODE, 0);
           ReadRegister(t);
           aNDiv=t.GetTx_NDIV() + 3;
           aRDiv=t.GetTx_RDIV() + 3;
           return true;
           }
           break; 
  }//switch

 LOG_ASSERT(false, "GetDivs:frame table not supported: "<<aFrameTable);
 return false;
}

float  TofCCController::CalcFout_MHz(const uint2& aFin, const uint2& aNDiv, const uint2& aRDiv) 
{
 LOG_ASSERT(aRDiv, "CalcFout_MHz: rdiv == 0");
 return ( aFin * aNDiv ) / ( 2.0 * aRDiv);
} 

float  TofCCController::GetFout_MHz(const uint2& aFin, const FrameTable_e & aFrameTable) 
{
 uint2 ndiv=0;
 uint2 rdiv=0;
 GetDivs(aFrameTable, ndiv, rdiv);
 return CalcFout_MHz(aFin, ndiv,rdiv);
} 

uint4  TofCCController::GetFrameIdleTime_tmix(const FrameTable_e & aFrameTable) 
{
 uint2 tx_frame_idletime0, tx_frame_idletime1;
 
  switch (aFrameTable) 
  {
   case T1: { 
           ReadRegister(Tx_IDLETIMEy_Reg::T1_IDLETIME0, tx_frame_idletime0);
           ReadRegister(Tx_IDLETIMEy_Reg::T1_IDLETIME1, tx_frame_idletime1);
           }
           break;
   case T2: {
           ReadRegister(Tx_IDLETIMEy_Reg::T2_IDLETIME0, tx_frame_idletime0);
           ReadRegister(Tx_IDLETIMEy_Reg::T2_IDLETIME1, tx_frame_idletime1);
           }
           break; 
  }//switch


 return ( (tx_frame_idletime1 << 16) | tx_frame_idletime0 ); 

} 


uint4  TofCCController::GetIntegrationTimePhase0_tmix(const FrameTable_e & aFrameTable) 
{
 uint2 tx_px_int0, tx_px_int1;
 
  switch (aFrameTable)  
  {
   case T1: { 
           ReadRegister(Tx_Py_INTz_Reg::T1_P0_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T1_P0_INT1, tx_px_int1);

           } 
           break;
   case T2: {
           ReadRegister(Tx_Py_INTz_Reg::T2_P0_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T2_P0_INT1, tx_px_int1);
           }
           break; 
  }//switch


 return ( (tx_px_int1 << 16) | tx_px_int0 ); 

} 

uint4  TofCCController::GetIntegrationTimePhase1_tmix(const FrameTable_e & aFrameTable) 
{
 uint2 tx_px_int0, tx_px_int1;
 
  switch (aFrameTable)  
  {
   case T1: { 
           ReadRegister(Tx_Py_INTz_Reg::T1_P1_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T1_P1_INT1, tx_px_int1);

           } 
           break;
   case T2: {
           ReadRegister(Tx_Py_INTz_Reg::T2_P1_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T2_P1_INT1, tx_px_int1);
           }
           break; 
  }//switch


 return ( (tx_px_int1 << 16) | tx_px_int0 ); 

} 


uint4  TofCCController::GetIntegrationTimePhase2_tmix(const FrameTable_e & aFrameTable) 
{
 uint2 tx_px_int0, tx_px_int1;
 
  switch (aFrameTable)  
  {
   case T1: { 
           ReadRegister(Tx_Py_INTz_Reg::T1_P2_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T1_P2_INT1, tx_px_int1);

           } 
           break;
   case T2: {
           ReadRegister(Tx_Py_INTz_Reg::T2_P2_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T2_P2_INT1, tx_px_int1);
           }
           break; 
  }//switch


 return ( (tx_px_int1 << 16) | tx_px_int0 ); 

} 


uint4  TofCCController::GetIntegrationTimePhase3_tmix(const FrameTable_e & aFrameTable) 
{
 uint2 tx_px_int0, tx_px_int1;
 
  switch (aFrameTable)  
  {
   case T1: { 
           ReadRegister(Tx_Py_INTz_Reg::T1_P3_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T1_P3_INT1, tx_px_int1);

           } 
           break;
   case T2: {
           ReadRegister(Tx_Py_INTz_Reg::T2_P3_INT0, tx_px_int0);
           ReadRegister(Tx_Py_INTz_Reg::T2_P3_INT1, tx_px_int1);
           }
           break; 
  }//switch


 return ( (tx_px_int1 << 16) | tx_px_int0 ); 

} 

uint4  TofCCController::CalcReadoutTime_tmix(const uint2& aFin, const float& aFout, const uint2& aCols, const uint2& aRows) 
{
 LOG_ASSERT(aFin, "GetReadoutTime_tmix: fin == 0");
 return (aRows * aCols * aFout / aFin);
} 

float  TofCCController::Get4FrameRate_Hz(const uint2& aFin, const FrameTable_e & aFrameTable, const uint2& aCols, const uint2& aRows) 
{
 //FIXME: need to add times of phase setup, preheat, phase idle, assume they are 0 here
 uint4 tx_p0_int = GetIntegrationTimePhase0_tmix(aFrameTable);
 uint4 tx_p1_int = GetIntegrationTimePhase1_tmix(aFrameTable);
 uint4 tx_p2_int = GetIntegrationTimePhase2_tmix(aFrameTable);
 uint4 tx_p3_int = GetIntegrationTimePhase3_tmix(aFrameTable);

 uint4 tx_frame_idle = GetFrameIdleTime_tmix(aFrameTable);

 float fout = GetFout_MHz(aFin, aFrameTable);
 uint4 four_tx_readout = 4 * CalcReadoutTime_tmix(aFin, fout, aCols, aRows);

 LOG_ASSERT(fout, "GetFrameRate_Hz: fout == 0");
 return 1000000.0 / ( (tx_p0_int + tx_p1_int + tx_p2_int + tx_p3_int + tx_frame_idle + four_tx_readout) /fout)  ;
} 


bool  TofCCController::GetROI(const FrameTable_e & aFrameTable, uint2& aColsRef, uint2& aRowsRef) 
{
 
  switch (aFrameTable)  
  {
   case T1: { 
            Rtl16::Tx_ROI_START_Reg t1_roi_start(Tx_ROI_START_Reg::T1_ROI_START, 0);
            Rtl16::Tx_ROI_SIZE_Reg t1_roi_size(Tx_ROI_SIZE_Reg::T1_ROI_SIZE, 0);
            ReadRegister(t1_roi_start);
            ReadRegister(t1_roi_size);

            aColsRef = 16 * (t1_roi_start.GetTx_ROI_START_X() + t1_roi_size.GetTx_ROI_SIZE_X());
            aRowsRef = t1_roi_start.GetTx_ROI_START_Y() + t1_roi_size.GetTx_ROI_SIZE_Y();

           return true;

           } 
           break;

   case T2: {
            Rtl16::Tx_ROI_START_Reg t2_roi_start(Tx_ROI_START_Reg::T2_ROI_START, 0);
            Rtl16::Tx_ROI_SIZE_Reg t2_roi_size(Tx_ROI_SIZE_Reg::T2_ROI_SIZE, 0);
            ReadRegister(t2_roi_start);
            ReadRegister(t2_roi_size);

            aColsRef = 16 * (t2_roi_start.GetTx_ROI_START_X() + t2_roi_size.GetTx_ROI_SIZE_X());
            aRowsRef = t2_roi_start.GetTx_ROI_START_Y() + t2_roi_size.GetTx_ROI_SIZE_Y();

           return true;

           }
           break; 
  }//switch


 return false;

} 






//NOTE: 1 FIXME left in helper functions: Get4FrameRate_Hz


//------------------------------ Member Functions ----------------------------
bool   TofCCController::Get4PhaseIntegration(  IntegrationTime_us_e & anIntegrationTimeRef_us
                                           ,   FrameRate_Hz_e & aFrameRateRef_Hz
                                           ,   Fout_MHz_e & aFoutRef_MHz
                                          )
{
 uint2 fin = GetFin_MHz( );
 TofCCController::FrameTable_e ft = GetFrameTable( );

 uint2 ndiv=0;
 uint2 rdiv=0;
 GetDivs(ft, ndiv, rdiv);

//for FIN:= 48MHz, encoding FOUT:=  (FIN << 8)  |  (N_DIV << 4) | R_DIV
 aFoutRef_MHz = Fout_MHz_e( (fin << 8)  |  (ndiv << 4) | rdiv);

 LOG_ASSERT(rdiv, "Get4PhaseIntegration: rdiv == 0");
 float fout = ( fin * ndiv ) / ( 2.0 * rdiv);
 LOG_ASSERT(fout, "Get4PhaseIntegration: fout == 0");
 float tmix = 1.0 /  fout;

 //FIXME: read out only phase 0, assume other phases are equally configured
 uint4 tmpTmixValue = 0;
 tmpTmixValue = GetIntegrationTimePhase0_tmix(ft);
 anIntegrationTimeRef_us = IntegrationTime_us_e(uint2(tmix * tmpTmixValue)); 


 uint2 cols=0, rows=0;
 GetROI(ft, cols, rows);

 aFrameRateRef_Hz = FrameRate_Hz_e(uint2(Get4FrameRate_Hz(fin, ft, cols, rows + 2)));  //HARDCODED: implies 2 lines of metadata

return true;
}


IntegrationSet  TofCCController::Get4PhaseIntegrationSettings( ) 
{

 IntegrationSet p;

 uint2 fin = GetFin_MHz();
 p.SetFin_MHz(fin);

 TofCCController::FrameTable_e ft = GetFrameTable( );


 //ROI
 uint2 cols=0, rows=0;
 GetROI(ft, cols, rows);
 
 p.SetFrameRate_Hz(Get4FrameRate_Hz(fin, ft, cols, rows + 2 )); //HARDCODED: implies 2 lines of metadata

 float fout = GetFout_MHz(fin, ft);
 p.SetFout_MHz(fout);

 LOG_ASSERT(fout, "Get4PhaseIntegrationSettings: fout == 0");
 float tmix = 1.0 /  fout;  
 p.SetTmix_us(tmix);


 //FIXME: take also setup and preheat times

 uint4 active_tmix = 0;
 uint4 tmpTmixValue = 0;
 tmpTmixValue = GetIntegrationTimePhase0_tmix(ft);
 active_tmix += tmpTmixValue;
 p.SetIntegrationTimePhase0_tmix(tmpTmixValue);

 tmpTmixValue = GetIntegrationTimePhase1_tmix(ft);
 active_tmix += tmpTmixValue;
 p.SetIntegrationTimePhase1_tmix(tmpTmixValue);

 tmpTmixValue = GetIntegrationTimePhase2_tmix(ft);
 active_tmix += tmpTmixValue;
 p.SetIntegrationTimePhase2_tmix(tmpTmixValue);

 tmpTmixValue = GetIntegrationTimePhase3_tmix(ft);
 active_tmix += tmpTmixValue;
 p.SetIntegrationTimePhase3_tmix(tmpTmixValue);

 uint4 passive_tmix = 0;
 tmpTmixValue = GetFrameIdleTime_tmix(ft);
 passive_tmix += tmpTmixValue;
 p.SetFrameIdleTime_tmix(tmpTmixValue);



 tmpTmixValue = CalcReadoutTime_tmix(fin, fout, cols, rows + 2);   //HARDCODED: 2 lines of metadata
 passive_tmix += 4* tmpTmixValue;
 p.SetReadoutTime_tmix(tmpTmixValue);

 uint2 illpower = 0;
 IllPowerReg r1;
 ReadRegister(r1);
 p.SetIllPower_percent(illpower = r1.GetIllPower_percent());
 
 const float C_POWER_PEAK = 65; //FIXME: schematics of laserboard 5A@13V

 LOG_ASSERT(active_tmix + passive_tmix, "Get4PhaseIntegrationSettings: active_tmix + passive_tmix == 0");
 p.SetLaserPower_W( (active_tmix / float(active_tmix + passive_tmix))  * 0.5 * C_POWER_PEAK * (illpower / 100.0));

 MixhVoltageReg r2;
 ReadRegister(r2);
 p.SetMixhVoltage_V(r2.GetMixhVoltage_V10() / 10.0);


 return p;
}



bool   TofCCController::Set4PhaseIntegration(  const IntegrationTime_us_e & anIntegrationTime_us
                                           , const FrameRate_Hz_e & aFrameRate_Hz
                                           , const Fout_MHz_e & aFout_MHz
                                          )
{
 //using Design-by-Contract checks

 //prepare aModulationFrequency_MHz
 uint4 fin  = aFout_MHz >> 8;
 DEBUGLOG() << "fin="<<fin<<std::endl;
 LOG_ASSERT( ((fin >= 40) && (fin <= 80)) , "unexpected fin outside [40 MHz, 80MHz]");
 uint2 ndiv = (aFout_MHz >> 4) & 0xf;
 DEBUGLOG() << "ndiv="<<ndiv<<std::endl;
 LOG_ASSERT( ((ndiv >= 3) && (ndiv <= 10)) , "unexpected ndiv outside [3, 10]");
 uint2 rdiv = (aFout_MHz) & 0xf;
 DEBUGLOG() << "rdiv="<<rdiv<<std::endl;
 LOG_ASSERT( ((rdiv >= 3) && (rdiv <= 10)) , "unexpected rdiv outside [3, 10]");
 uint4 fout = ( fin * ndiv) / (2.0 * rdiv);     //PROTECTED
 DEBUGLOG() << "fout="<<fout<<std::endl;
 LOG_ASSERT( ((fout >= 12) && (fout <= 40)) , "unexpected fout outside [12 MHz, 40MHz]");

 //prepare  

 //prepare anIntegrationTime_us
 uint4 tx_px_int = anIntegrationTime_us * fout;
 DEBUGLOG() << "tx_px_int="<<tx_px_int<<std::endl;
 LOG_ASSERT( (tx_px_int > 0) , "unexpected phase integration tmix pulses tx_px_int == 0");
 uint2 tx_px_int0 = tx_px_int & 0xffff;
 uint2 tx_px_int1 = (tx_px_int >>16) & 0xffff;

 //prepare aFourPhasesFrameRate_Hz
 //FIXME: hardcoded ROI
 const uint2 C_ALL_ROWS_METADATA2 = 242;
 const uint2 C_ALL_COLS = 320;

 uint4 four_tx_readout = 4 * (C_ALL_ROWS_METADATA2 * C_ALL_COLS * fout / fin); //PROTECTED  //FIXME: need to add ROI of chip pixels and metadata here
 DEBUGLOG() << "four_tx_readout="<<four_tx_readout<<std::endl;

 // aFrameRate_Hz := (1000000.0 * fout) / ( ( 4 * tx_px_int) + tx_frame_idle + four_tx_readout) )
 LOG_ASSERT(aFrameRate_Hz  != 0, "unexpected aFrameRate_Hz == 0");

 //take care on underflow
 uint4 tx_frame_idle_part1 = ( 1000000 * fout) / (aFrameRate_Hz);
 INFOLOG() << "all tmix periods :"<<tx_frame_idle_part1<<std::endl;
 uint4 tx_frame_idle_part2 = ( 4 * tx_px_int) + four_tx_readout;
 INFOLOG() << "used tmix periods:"<<tx_frame_idle_part2<<std::endl;
 LOG_ASSERT(tx_frame_idle_part1 >=tx_frame_idle_part2, "too many occupied tmix periods, reduce frame rate and/or integration time");
 uint4 tx_frame_idle = tx_frame_idle_part1 - tx_frame_idle_part2 ;   //PROTECTED
 INFOLOG() << "free tmix periods:"<<tx_frame_idle<<std::endl;

 uint2 tx_frame_idle0 = tx_frame_idle & 0xffff;
 uint2 tx_frame_idle1 = (tx_frame_idle >>16) & 0xffff;

 //which frame table ?
 FrameTable_e ft; 
 ADC_DELAY_FT_Reg r;
 ReadRegister(r);

 if (! r.GetFRAME_TABLE()) ft = TofCCController::T1;
 else ft = TofCCController::T2;


  switch (ft)
  {
   case T1: 
         {
         //T1 is active, so write into T2
	 //set integration time
         WriteRegister(Tx_Py_INTz_Reg::T2_P0_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T2_P0_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T2_P1_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T2_P1_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T2_P2_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T2_P2_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T2_P3_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T2_P3_INT1, tx_px_int1);

	 //set frame idle time
         WriteRegister(Tx_IDLETIMEy_Reg::T2_IDLETIME0, tx_frame_idle0);
         WriteRegister(Tx_IDLETIMEy_Reg::T2_IDLETIME1, tx_frame_idle1);
	 //set modulation frequency, do not read current tx_mode setting from tof camera, use default values
	 Tx_MODE_Reg tr; 
	 tr.SetTx_NDIV(ndiv - 3);
	 tr.SetTx_RDIV(rdiv - 3);
	 WriteRegister(Tx_MODE_Reg::T2_MODE, tr.GetReg());

         //ROI settings
//TBD         WriteRegister(Tx_ROI_START_Reg::T2_ROI_START, 0x0);   //HARDCODED: 0
//TBD         WriteRegister(Tx_ROI_SIZE_Reg::T2_ROI_SIZE, 0xf014);  //HARDCODED: 320x240

	 //switch frame table, keep adc settings //FIXED: ROH 2019-09-27
         r.SetFRAME_TABLE(T2);
         WriteRegister(r);  
         }
         break;
   case T2: 
         {
         //T2 is active, so write into T1
	 //set integration time
         WriteRegister(Tx_Py_INTz_Reg::T1_P0_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T1_P0_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T1_P1_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T1_P1_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T1_P2_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T1_P2_INT1, tx_px_int1);
         WriteRegister(Tx_Py_INTz_Reg::T1_P3_INT0, tx_px_int0);
         WriteRegister(Tx_Py_INTz_Reg::T1_P3_INT1, tx_px_int1);

	 //set frame idle time
         WriteRegister(Tx_IDLETIMEy_Reg::T1_IDLETIME0, tx_frame_idle0);
         WriteRegister(Tx_IDLETIMEy_Reg::T1_IDLETIME1, tx_frame_idle1);
	 //set modulation frequency, do not read current tx_mode setting from tof camera, use default values
         Tx_MODE_Reg tr; 
	 tr.SetTx_NDIV(ndiv - 3);
	 tr.SetTx_RDIV(rdiv - 3);
         WriteRegister(Tx_MODE_Reg::T1_MODE, tr.GetReg());

         //ROI settings
//TBD         WriteRegister(Tx_ROI_START_Reg::T1_ROI_START, 0x0);   //HARDCODED: 0
//TBD         WriteRegister(Tx_ROI_SIZE_Reg::T1_ROI_SIZE, 0xf014);  //HARDCODED: 320x240

	 //switch frame table, keep adc settings //FIXED: ROH 2019-09-27
         r.SetFRAME_TABLE(T1);
         WriteRegister(r);  
         }
         break; 
  }//switch

  //switch the TIMCLOCK 
  WriteRegister(TimClockReg::TIMCLOCK, fin * 100);

return true;
}

//------------------------------ Logging ------------------------------
void TofCCController::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}

void TofCCController::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "MLX75123_TofCCController" );
   {
    aLogFormat . LogElement( aStreamRef, "Rtl16_TofCCController" );
    Rtl16::RegController::Log(aStreamRef, aLogFormat);
   }
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
