///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass 
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4027 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class TofCCController 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Jun 25 16:27:49 2017
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _MLX75123_TofCCController_
#define _MLX75123_TofCCController_

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

#include "Rtl16_RegController.h"
#include "MLX75123_IntegrationSet.h"



//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace MLX75123
namespace MLX75123
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class TofCCController
class TofCCController: public Rtl16::RegController
{
public:

       //enums
         //see SoftwareUserManualv4.pdf, chapter 6.1 General
         enum IntegrationTime_us_e
         {
              INTEGRATION_TIME_MIN = 1
            , INTEGRATION_TIME_1us = 1
            , INTEGRATION_TIME_10us = 10
            , INTEGRATION_TIME_25us = 25
            , INTEGRATION_TIME_50us = 50
            , INTEGRATION_TIME_100us = 100
            , INTEGRATION_TIME_150us = 150
            , INTEGRATION_TIME_200us = 200
            , INTEGRATION_TIME_250us = 250
            , INTEGRATION_TIME_300us = 300
            , INTEGRATION_TIME_400us = 400
            , INTEGRATION_TIME_500us = 500
            , INTEGRATION_TIME_600us = 600
            , INTEGRATION_TIME_700us = 700
            , INTEGRATION_TIME_800us = 800
            , INTEGRATION_TIME_900us = 900
            , INTEGRATION_TIME_1000us = 1000
            , INTEGRATION_TIME_1500us = 1500
            , INTEGRATION_TIME_2000us = 2000
            , INTEGRATION_TIME_2500us = 2500
            , INTEGRATION_TIME_3000us = 3000
            , INTEGRATION_TIME_3500us = 3500
            , LASER_CLASS_1_LIMIT_90percent_us  = 3500
            , INTEGRATION_TIME_4000us = 4000
            , INTEGRATION_TIME_4500us = 4500
            , INTEGRATION_TIME_5000us = 5000
            , INTEGRATION_TIME_5500us = 5500
            , INTEGRATION_TIME_6000us = 6000
            , INTEGRATION_TIME_6500us = 6500
            , LASER_CLASS_1_LIMIT_50percent_us  = 6500
            , INTEGRATION_TIME_7000us = 7000
            , INTEGRATION_TIME_7500us = 7500
            , INTEGRATION_TIME_8000us = 8000
            , INTEGRATION_TIME_8500us = 8500
            , INTEGRATION_TIME_9000us = 9000
            , INTEGRATION_TIME_9500us = 9500
            , INTEGRATION_TIME_10000us = 10000
            , INTEGRATION_TIME_MAX = 10000
         };

         //see SoftwareUserManualv4.pdf, chapter 6.1 General
         enum FrameRate_Hz_e
         {
              FRAME_RATE_MIN = 1
           ,  FRAME_RATE_1Hz = 1
           ,  FRAME_RATE_2Hz = 2
           ,  FRAME_RATE_3Hz = 3
           ,  FRAME_RATE_4Hz = 4
           ,  FRAME_RATE_5Hz = 5
           ,  FRAME_RATE_6Hz = 6
           ,  FRAME_RATE_7Hz = 7
           ,  FRAME_RATE_8Hz = 8
           ,  FRAME_RATE_9Hz = 9
           ,  FRAME_RATE_10Hz = 10
           ,  FRAME_RATE_11Hz = 11
           ,  FRAME_RATE_12Hz = 12
           ,  FRAME_RATE_13Hz = 13
           ,  FRAME_RATE_14Hz = 14
           ,  FRAME_RATE_15Hz = 15
           ,  FRAME_RATE_16Hz = 16
           ,  FRAME_RATE_17Hz = 17
           ,  FRAME_RATE_18Hz = 18
           ,  FRAME_RATE_19Hz = 19
           ,  FRAME_RATE_20Hz = 20
           ,  FRAME_RATE_21Hz = 21
           ,  FRAME_RATE_22Hz = 22
           ,  FRAME_RATE_23Hz = 23
           ,  FRAME_RATE_24Hz = 24
           ,  FRAME_RATE_25Hz = 25
           ,  FRAME_RATE_26Hz = 26
           ,  FRAME_RATE_27Hz = 27
           ,  FRAME_RATE_28Hz = 28
           ,  FRAME_RATE_29Hz = 29
           ,  FRAME_RATE_30Hz = 30
           ,  FRAME_RATE_31Hz = 31
           ,  FRAME_RATE_32Hz = 32
           ,  FRAME_RATE_33Hz = 33
           ,  FRAME_RATE_34Hz = 34
           ,  FRAME_RATE_35Hz = 35
           ,  FRAME_RATE_36Hz = 36
           ,  FRAME_RATE_37Hz = 37
           ,  FRAME_RATE_38Hz = 38
           ,  FRAME_RATE_39Hz = 39
           ,  FRAME_RATE_40Hz = 40
           ,  FRAME_RATE_41Hz = 41
           ,  FRAME_RATE_42Hz = 42
           ,  FRAME_RATE_43Hz = 43
           ,  FRAME_RATE_44Hz = 44
           ,  FRAME_RATE_45Hz = 45
           ,  FRAME_RATE_46Hz = 46
           ,  FRAME_RATE_47Hz = 47
           ,  FRAME_RATE_48Hz = 48
           ,  FRAME_RATE_49Hz = 49
           ,  FRAME_RATE_50Hz = 50
           ,  FRAME_RATE_51Hz = 51
           ,  FRAME_RATE_52Hz = 52
           ,  FRAME_RATE_53Hz = 53
           ,  FRAME_RATE_54Hz = 54
           ,  FRAME_RATE_55Hz = 55
           ,  FRAME_RATE_56Hz = 56
           ,  FRAME_RATE_57Hz = 57
           ,  FRAME_RATE_58Hz = 58
           ,  FRAME_RATE_59Hz = 59
           ,  FRAME_RATE_60Hz = 60
           ,  FRAME_RATE_61Hz = 61
           ,  FRAME_RATE_62Hz = 62
           ,  FRAME_RATE_63Hz = 63
           ,  FRAME_RATE_64Hz = 64
           ,  FRAME_RATE_65Hz = 65
           ,  FRAME_RATE_66Hz = 66
           ,  FRAME_RATE_67Hz = 67
           ,  FRAME_RATE_68Hz = 68
           ,  FRAME_RATE_69Hz = 69
           ,  FRAME_RATE_70Hz = 70
           ,  FRAME_RATE_71Hz = 71
           ,  FRAME_RATE_72Hz = 72
           ,  FRAME_RATE_73Hz = 73
           ,  FRAME_RATE_74Hz = 74
           ,  FRAME_RATE_75Hz = 75
           ,  FRAME_RATE_76Hz = 76
           ,  FRAME_RATE_77Hz = 77
           ,  FRAME_RATE_78Hz = 78
           ,  FRAME_RATE_79Hz = 79
           ,  FRAME_RATE_80Hz = 80
           ,  FRAME_RATE_81Hz = 81
           ,  FRAME_RATE_82Hz = 82
           ,  FRAME_RATE_83Hz = 83
           ,  FRAME_RATE_84Hz = 84
           ,  FRAME_RATE_85Hz = 85
           ,  FRAME_RATE_86Hz = 86
           ,  FRAME_RATE_87Hz = 87
           ,  FRAME_RATE_88Hz = 88
           ,  FRAME_RATE_89Hz = 89
           ,  FRAME_RATE_90Hz = 90
           ,  FRAME_RATE_91Hz = 91
           ,  FRAME_RATE_92Hz = 92
           ,  FRAME_RATE_93Hz = 93
           ,  FRAME_RATE_94Hz = 94
           ,  FRAME_RATE_95Hz = 95
           ,  FRAME_RATE_96Hz = 96
           ,  FRAME_RATE_97Hz = 97
           ,  FRAME_RATE_98Hz = 98
           ,  FRAME_RATE_99Hz = 99
           ,  FRAME_RATE_100Hz = 100
           ,  FRAME_RATE_MAX  = 100
         };

         //see MLX75123-Datasheet-Melexis.pdf, chapter 17. FMOD-Generator
         //for FIN:= 48MHz, encoding FOUT:=  (FIN << 8)  |  (N_DIV << 4) | R_DIV
         enum Fout_MHz_e
         {
              FIN48_FOUT12_0 = (48<<8) | (3<<4) | 6
            , FIN48_FOUT13_3 = (48<<8) | (5<<4) | 9
            , FIN48_FOUT13_7 = (48<<8) | (4<<4) | 7
            , FIN48_FOUT14_4 = (48<<8) | (3<<4) | 5
            , FIN48_FOUT15_0 = (48<<8) | (5<<4) | 8
            , FIN48_FOUT16_0 = (48<<8) | (4<<4) | 6
            , FIN48_FOUT17_1 = (48<<8) | (5<<4) | 7
            , FIN48_FOUT18_0 = (48<<8) | (3<<4) | 4
            , FIN48_FOUT19_2 = (48<<8) | (4<<4) | 5
            , FIN48_FOUT20_0 = (48<<8) | (5<<4) | 6
            , FIN48_FOUT20_5 = (48<<8) | (6<<4) | 7
            , FIN48_FOUT21_3 = (48<<8) | (8<<4) | 9
            , FIN48_FOUT24_0 = (48<<8) | (3<<4) | 3
            , FIN48_FOUT27_0 = (48<<8) | (9<<4) | 8
            , FIN48_FOUT27_4 = (48<<8) | (8<<4) | 7
            , FIN48_FOUT28_0 = (48<<8) | (7<<4) | 6
            , FIN48_FOUT28_8 = (48<<8) | (6<<4) | 5
            , FIN48_FOUT30_0 = (48<<8) | (5<<4) | 4
            , FIN48_FOUT30_8 = (48<<8) | (9<<4) | 7
            , FIN48_FOUT32_0 = (48<<8) | (4<<4) | 3
            , FIN48_FOUT33_6 = (48<<8) | (7<<4) | 5
            , FIN48_FOUT36_0 = (48<<8) | (6<<4) | 4
            , FIN48_FOUT38_4 = (48<<8) | (8<<4) | 5
            , FIN48_FOUT40_0 = (48<<8) | (10<<4)| 6         //CHANGED: ROH 2019-09-27
         };

         //MLX75123 supports 2 frame tables
         enum FrameTable_e
         {
           T1 = 0
          ,T2 = 1
          ,T_MAX = 1
         };

   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        TofCCController( );

   /// Destructor
        virtual ~TofCCController( );

   ///Special Constructor 
        TofCCController( const std::string & aName
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
       virtual bool operator == (const TofCCController & aRef) const;
   
   /// Less operator 
       virtual bool operator < (const TofCCController & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{

   //@}

   ///@name Comfort functions for reading and writing tof camera registers
   //@{

         //get all tof camera integration settings at once
         MLX75123::IntegrationSet   Get4PhaseIntegrationSettings( ) ; 

         //set all MLX75123 registers for 4 phase integration, see MLX75123-Datasheet-Melexis.pdf, chapter 17. FMOD-Generator
         bool   Set4PhaseIntegration(  const IntegrationTime_us_e & anIntegrationTime_us
                                     , const FrameRate_Hz_e & aFrameRate_Hz
                                     , const Fout_MHz_e & aFout_MHz
                                    ) ; 

         //get MLX75123 registers for 4 phase integration, see MLX75123-Datasheet-Melexis.pdf, chapter 17. FMOD-Generator
         bool   Get4PhaseIntegration(  IntegrationTime_us_e & anIntegrationTimeRef_us
                                     , FrameRate_Hz_e & aFrameRateRef_Hz
                                     , Fout_MHz_e & aFoutRef_MHz
                                    ) ; 
         //convert string to enum
         static bool  ConvertFromString_Fout_MHz_e(Fout_MHz_e  & theResult, const std::string & aString);
   //@}


private:
         //   All the Elements
         //see MLX75123-Datasheet-Melexis.pdf, chapter 17. FMOD-Generator
         float   Get4FrameRate_Hz(const uint2& aFin, const FrameTable_e & aFrameTable, const uint2& aCols, const uint2& aRows) ; 
         float   CalcFout_MHz(const uint2& aFin, const uint2& aNDiv, const uint2& aRDiv) ; 
         float   GetFout_MHz(const uint2& aFin, const FrameTable_e & aFrameTable) ; 
         uint2   GetFin_MHz( ) ; 
         uint4   GetIntegrationTimePhase0_tmix(const FrameTable_e & aFrameTable) ; 
         uint4   GetIntegrationTimePhase1_tmix(const FrameTable_e & aFrameTable) ; 
         uint4   GetIntegrationTimePhase2_tmix(const FrameTable_e & aFrameTable) ; 
         uint4   GetIntegrationTimePhase3_tmix(const FrameTable_e & aFrameTable) ; 
         uint4   GetFrameIdleTime_tmix(const FrameTable_e & aFrameTable) ; 
         uint4   CalcReadoutTime_tmix(const uint2& aFin, const float& aFout, const uint2& aCols, const uint2& aRows); 
         bool    GetDivs( const FrameTable_e& aFrameTable, uint2& aNDiv, uint2&aRDiv ) ; 
         FrameTable_e   GetFrameTable( ) ;
         bool   GetROI(const FrameTable_e & aFrameTable, uint2& aColsRef, uint2& aRowsRef);


}; // End of class TofCCController

//------------------------------ Inline Functions ----------------------
inline bool TofCCController::operator == (const TofCCController & aRef) const
{
   if ( ! Rtl16::RegController::operator == (aRef) )  return false;

   return true;
}

inline bool TofCCController::operator < (const TofCCController & aRef) const
{
   if ( ! Rtl16::RegController::operator < (aRef) )  return false;

   return true; 
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const TofCCController & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}

inline bool TofCCController::ConvertFromString_Fout_MHz_e(Fout_MHz_e  & theResult, const std::string & aString)
{
 
  //conversion from string to enum
  if      (aString == "FIN48_FOUT12_0")  { theResult = TofCCController::FIN48_FOUT12_0;   return true; }
  else if (aString == "FIN48_FOUT13_3")  { theResult = TofCCController::FIN48_FOUT13_3;   return true; }
  else if (aString == "FIN48_FOUT13_7")  { theResult = TofCCController::FIN48_FOUT13_7;   return true; }
  else if (aString == "FIN48_FOUT14_4")  { theResult = TofCCController::FIN48_FOUT14_4;   return true; }
  else if (aString == "FIN48_FOUT15_0")  { theResult = TofCCController::FIN48_FOUT15_0;   return true; }
  else if (aString == "FIN48_FOUT16_0")  { theResult = TofCCController::FIN48_FOUT16_0;   return true; }
  else if (aString == "FIN48_FOUT17_1")  { theResult = TofCCController::FIN48_FOUT17_1;   return true; }
  else if (aString == "FIN48_FOUT18_0")  { theResult = TofCCController::FIN48_FOUT18_0;   return true; }
  else if (aString == "FIN48_FOUT19_2")  { theResult = TofCCController::FIN48_FOUT19_2;   return true; }
  else if (aString == "FIN48_FOUT20_0")  { theResult = TofCCController::FIN48_FOUT20_0;   return true; }
  else if (aString == "FIN48_FOUT20_5")  { theResult = TofCCController::FIN48_FOUT20_5;   return true; }
  else if (aString == "FIN48_FOUT21_3")  { theResult = TofCCController::FIN48_FOUT21_3;   return true; }
  else if (aString == "FIN48_FOUT24_0")  { theResult = TofCCController::FIN48_FOUT24_0;   return true; }
  else if (aString == "FIN48_FOUT27_0")  { theResult = TofCCController::FIN48_FOUT27_0;   return true; }
  else if (aString == "FIN48_FOUT27_4")  { theResult = TofCCController::FIN48_FOUT27_4;   return true; }
  else if (aString == "FIN48_FOUT28_0")  { theResult = TofCCController::FIN48_FOUT28_0;   return true; }
  else if (aString == "FIN48_FOUT28_8")  { theResult = TofCCController::FIN48_FOUT28_8;   return true; }
  else if (aString == "FIN48_FOUT30_0")  { theResult = TofCCController::FIN48_FOUT30_0;   return true; }
  else if (aString == "FIN48_FOUT30_8")  { theResult = TofCCController::FIN48_FOUT30_8;   return true; }
  else if (aString == "FIN48_FOUT32_0")  { theResult = TofCCController::FIN48_FOUT32_0;   return true; }
  else if (aString == "FIN48_FOUT33_6")  { theResult = TofCCController::FIN48_FOUT33_6;   return true; }
  else if (aString == "FIN48_FOUT36_0")  { theResult = TofCCController::FIN48_FOUT36_0;   return true; }
  else if (aString == "FIN48_FOUT38_4")  { theResult = TofCCController::FIN48_FOUT38_4;   return true; }
  else if (aString == "FIN48_FOUT40_0")  { theResult = TofCCController::FIN48_FOUT40_0;   return true; }
 else return false;
}

}; // End of namespace MLX75123

#endif

