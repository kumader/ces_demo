///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 3851 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The implementation for class Logger
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Jul 13 21:14:41 2004
//              automatically generated code
//              manually modified
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header$"
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "Common_Logger.h"
#include "Common_LogFormat.h"
#include "Common_PreciseTimeValue.h"
#include "Common_UseLogger.h"
#include <cstdio>
//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace Common;


//TST static ostringstream cnull(0);

 bool Logger::itsDrop = false;
 string Logger::itsName = "";

//------------------------------ Constructor -------------------
Logger::Logger ( )
:itsErrorFlag (false)
{
//// nothing
}

Logger::Logger (const string & aName)
:itsErrorFlag (false)
{

itsName = aName;

}


//------------------------------ Destructor ----------------------------

Logger::~Logger (  )
{
 if (!itsDrop)
 {
   //fast cout
   fprintf(stdout, "%s", itsStreamBuffer.str().c_str());
   fflush(stdout);
 }//if

 //throw excpetion on error()
 if (itsErrorFlag) throw "~Logger: error() called";
}

//------------------------------ Logging ------------------------------
void Logger::Log( ostream & aStreamRef ) const
{
   LogFormat tmpLogFormat( 10, LogFormat::TEXT_BLOCK );
   Log( aStreamRef, tmpLogFormat );
}


void Logger::Log( ostream & aStreamRef, LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "Common_Logger" );
   {
      aLogFormat . LogElement( aStreamRef, "Drop" );
      aLogFormat . LogDecValue( aStreamRef, itsDrop );
      aLogFormat . LogElement( aStreamRef, "Name" );
      aLogFormat . LogDecValue( aStreamRef, itsName );
   }
   aLogFormat . LogEndStruct( aStreamRef );
}


string Logger::Timestamp( void )
{

   PreciseTimeValue tmpTime;
   tmpTime.GetPresentTime ( );
   return tmpTime.ConvertToString(PreciseTimeValue::PTV_TIME);

}


string Logger::Datestamp( void )
{
   PreciseTimeValue tmpTime;
   tmpTime.GetPresentTime ( );
   return tmpTime.ConvertToString(PreciseTimeValue::PTV_DATE);
}


string Logger::DateTimestamp( void )
{
   PreciseTimeValue tmpTime;
   tmpTime.GetPresentTime ( );
   return tmpTime.ConvertToString(PreciseTimeValue::PTV_DATE_TIME);
}


ostringstream & Logger::debug( const UseLogger & anObject )
{


    itsStreamBuffer  <<  anObject.GetCycle()   << 
			       " "                   <<
			       DateTimestamp()       <<
			       "\e[33m"              <<
			       " DBG "               <<
			       GetName()             <<
			       anObject.GetName()    <<
			       ": "                  << 
			       "\e[0m";            

   return itsStreamBuffer;
}


ostringstream & Logger::error( const UseLogger & anObject )
{

   itsStreamBuffer <<  anObject.GetCycle()    << 
                       " "                    <<
                       DateTimestamp()        <<
                       "\e[31m"               <<
                       " ERR "                <<
		       GetName()              <<
                       anObject.GetName()     <<
                       ": "                   <<
                       "\e[0m ";
  itsErrorFlag = true;		       
  return itsStreamBuffer;		       
}


ostringstream & Logger::warn( const UseLogger & anObject )
{
   itsStreamBuffer       <<  anObject.GetCycle()    << 
                                   " "                    <<
                                   DateTimestamp()        << 
                                   "\e[31m"               <<
                                   " WRN "                <<
		                   GetName()              <<
                                   anObject.GetName()     <<
                                   ": "                   <<
                                   "\e[0m";              
   return itsStreamBuffer;				   
}


ostringstream & Logger::trace(const UseLogger & anObject)
{
    itsStreamBuffer       <<  anObject.GetCycle()    << 
                                    " "                    <<
                                    DateTimestamp()        <<
                                    "\e[34m"               <<
                                    " TRA "                <<
		                    GetName()              <<
                                    anObject.GetName()     <<
                                    ": "                   <<
                                    "\e[0m";
    return itsStreamBuffer;				    
}


ostringstream & Logger::info( const UseLogger & anObject)
{
    itsStreamBuffer       <<  anObject.GetCycle()    <<
                                    "\e[32m"               <<
                                    " INF "                <<
		                    GetName()              <<
                                    anObject.GetName()     <<
                                    ": "                   <<
                                    "\e[0m";
    return itsStreamBuffer;				    
}


ostringstream & Logger::log( const UseLogger & anObject)
{
   itsStreamBuffer       <<  anObject.GetCycle()    <<
                                    " "                    <<
                                    DateTimestamp()        <<
                                    "\e[36m"               <<
                                    " LOG "                <<
		                    GetName()              <<
                                    anObject.GetName()     <<
                                    ": "                   <<
                                    "\e[0m";
   return itsStreamBuffer;				    
}

ostringstream & Logger::raw( )
{
   return itsStreamBuffer;
}

//End of File
