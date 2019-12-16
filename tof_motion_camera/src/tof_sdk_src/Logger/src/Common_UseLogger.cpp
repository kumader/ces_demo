///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2862 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The implementation for class UseLogger
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Jul 24 07:42:06 2004
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header$"
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_UseLogger.h"
#include "Common_LogFormat.h"

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;

//------------------------------ Constructor -------------------
///Default constructor
///Values are set to anything
///NOTE: this constructor is only for testing
UseLogger::UseLogger ( )
: itsCycle ( 91 )
, itsLogLevel ( S_INFO )
, itsName ( "Unknown" )

{
//// nothing
}


UseLogger::UseLogger (const uint4 & aCycle, const LogLevel_e & aLogLevel, const string & aName)
: itsCycle ( aCycle )
, itsLogLevel ( aLogLevel )
, itsName ( aName )
{
//// nothing
}


//------------------------------ Destructor ----------------------------

UseLogger::~UseLogger (  )
{
//// nothing
//Cleanup
//
if (itsLogLevel == UseLogger::S_DEBUG)
std::cerr << "DESTROY: "
          << GetCycle()
          << " UseLogger "
          << GetName()
          << std::endl;
}

//------------------------------ Conversion ------------------------------
bool UseLogger::ConvertFromString( LogLevel_e & theResult, const std::string & aString)
{

  if (aString == "S_NO_LOGGING") { theResult = UseLogger::S_NO_LOGGING;	return true; }
  else if (aString == "S_ERROR") { theResult = UseLogger::S_ERROR;	        return true; }
  else if (aString == "S_WARN")  { theResult = UseLogger::S_WARN;	        return true; }
  else if (aString == "S_INFO")  { theResult = UseLogger::S_INFO;	        return true; }
  else if (aString == "S_DEBUG") { theResult = UseLogger::S_DEBUG;            return true; }	
  else return false; 
}
	
//------------------------------ Logging ------------------------------
std::string
UseLogger::ConvertToString( LogLevel_e aLogLevel )
{
   switch (aLogLevel)
   {
      case UseLogger::S_NO_LOGGING:    return "S_NO_LOGGING";
      break;
      case UseLogger::S_ERROR:         return "S_ERROR";
      break;
      case UseLogger::S_WARN:          return "S_WARN";
      break;
      case UseLogger::S_INFO:          return "S_INFO";
      break;
      case UseLogger::S_DEBUG:         return "S_DEBUG";
      break;
      default:                           return "UNKNOWN LOGLEVEL";
      break;
   }                                              //switch
}


void UseLogger::Log( ostream & aStreamRef ) const
{
   LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}


void UseLogger::Log( ostream & aStreamRef, LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Common_UseLogger" );
   {
      aLogFormat . LogElement( aStreamRef, "Cycle" );
      aLogFormat . LogDecValue( aStreamRef, itsCycle );
      aLogFormat . LogElement( aStreamRef, "LogLevel" );
      aLogFormat . LogDecValue( aStreamRef, ConvertToString(itsLogLevel) );
      aLogFormat . LogElement( aStreamRef, "Name" );
      aLogFormat . LogDecValue( aStreamRef, itsName );
   }
   aLogFormat . LogEndStruct( aStreamRef );
}

//End of File
