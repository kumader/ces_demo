///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The implementation for class SelectWithSockets
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 13:25:18 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "IO_SelectWithSockets.h"
#include "IO_Socket.h"
#include "Common_LogFormat.h"
//#include <sys/time.h>
#include <errno.h>

//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace IO;

//------------------------------ Constructor -------------------

SelectWithSockets::SelectWithSockets ( )
: Select ( )
, itsSocketMap ( )
{
///nothing
}


SelectWithSockets::SelectWithSockets (const std::string & aName , const LogLevel_e & aLogLevel)
: Select ( aName, aLogLevel )
, itsSocketMap ( )
{
///nothing
}

//------------------------------ Destructor ----------------------------

SelectWithSockets::~SelectWithSockets (  )
{
/// nothing
}

//add socket 
void SelectWithSockets::Add(const Socket & aSocket)
{
 Select::Add(aSocket.GetFD());
 itsSocketMap.insert( pair<int, IO::Socket> (aSocket.GetFD(), aSocket) );
}

void SelectWithSockets::Remove(const Socket & aSocket)
{
 Select::Remove(aSocket.GetFD());
 itsSocketMap.erase(aSocket.GetFD());
}




//non blocking
int SelectWithSockets::Can_Read(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, SocketList_t & theSocketList) const
{
   FDList_t tmpFDList;
   int result_read = Select::Can_Read(aSecondsTimeout, aMicrosecondsTimeout, tmpFDList);

   if (result_read < 0)
   {
   return result_read;
   }

 //create resulting SocketList for caller
   theSocketList.clear();

   cFDListIterator_t iteratorList;

   for(iteratorList = tmpFDList.begin(); iteratorList != tmpFDList.end(); ++iteratorList)
   {
       cSocketMapIterator_t iteratorMap = itsSocketMap.find(*iteratorList);
       LOG_ASSERT(iteratorMap != itsSocketMap.end(), "Can_Read: inconsistency in socket map, map key "<<*iteratorList<<" not found" );

       theSocketList.push_back(iteratorMap->second);
   }                                              //for

   return result_read;

}


//blocking
int SelectWithSockets::Can_Read(SocketList_t & theSocketList) const
{
   FDList_t tmpFDList;
   int result_read = Select::Can_Read(tmpFDList);

   if (result_read < 0)
   {
   return result_read;
   }

 //create resulting SocketList for caller
   theSocketList.clear();

   cFDListIterator_t iteratorList;

   for(iteratorList = tmpFDList.begin(); iteratorList != tmpFDList.end(); ++iteratorList)
   {
       cSocketMapIterator_t iteratorMap = itsSocketMap.find(*iteratorList);
       LOG_ASSERT(iteratorMap != itsSocketMap.end(), "Can_Read: inconsistency in socket map, map key "<<*iteratorList<<" not found" );

       theSocketList.push_back(iteratorMap->second);
   }                                              //for

   return result_read;

}


//non-blocking can_write
int SelectWithSockets::Can_Write(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, SocketList_t & theSocketList) const
{
   FDList_t tmpFDList;
   int result_read = Select::Can_Write(aSecondsTimeout, aMicrosecondsTimeout, tmpFDList);

   if (result_read < 0)
   {
   return result_read;
   }

 //create resulting SocketList for caller
   theSocketList.clear();

   cFDListIterator_t iteratorList;

   for(iteratorList = tmpFDList.begin(); iteratorList != tmpFDList.end(); ++iteratorList)
   {
       cSocketMapIterator_t iteratorMap = itsSocketMap.find(*iteratorList);
       LOG_ASSERT(iteratorMap != itsSocketMap.end(), "Can_Write: inconsistency in socket map, map key "<<*iteratorList<<" not found"  ); 

       theSocketList.push_back(iteratorMap->second);
   }                                              //for

   return result_read;
}

//blocking can_write
int SelectWithSockets::Can_Write(SocketList_t & theSocketList) const
{
   FDList_t tmpFDList;
   int result_read = Select::Can_Write(tmpFDList);

   if (result_read < 0)
   {
   return result_read;
   }

 //create resulting SocketList for caller
   theSocketList.clear();

   cFDListIterator_t iteratorList;

   for(iteratorList = tmpFDList.begin(); iteratorList != tmpFDList.end(); ++iteratorList)
   {
       cSocketMapIterator_t iteratorMap = itsSocketMap.find(*iteratorList);
       LOG_ASSERT(iteratorMap != itsSocketMap.end(), "Can_Write: inconsistency in socket map, map key "<<*iteratorList<<" not found"  ); 

       theSocketList.push_back(iteratorMap->second);
   }                                              //for

   return result_read;
}



//------------------------------ Logging ------------------------------
void SelectWithSockets::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}


void SelectWithSockets::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
  aLogFormat . LogBeginStruct( aStreamRef, "IO_SelectWithSockets" );
   aLogFormat . LogElement( aStreamRef, "IO_Select" );
    Select::Log(aStreamRef, aLogFormat); 

   aLogFormat . LogElement( aStreamRef, "SocketMap" );
   aLogFormat . LogBeginStruct( aStreamRef, "SocketMap_t" );
   {
     cSocketMapIterator_t iteratorMap;
     for(iteratorMap =  itsSocketMap.begin(); iteratorMap != itsSocketMap.end(); ++iteratorMap)
     {
        aLogFormat . LogMapElement(aStreamRef, "FD", iteratorMap->first );
        iteratorMap ->second.Log(aStreamRef, aLogFormat);
     }                                           //for
   }                                              //if
   aLogFormat . LogEndStruct( aStreamRef );
  aLogFormat . LogEndStruct( aStreamRef );
}


//End of File
