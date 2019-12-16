///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The implementation for class Select
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 13:25:18 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "stdafx.h"
#include "IO_Select.h"
#include "Common_LogFormat.h"
//#include <sys/time.h>
#include <errno.h>
#include <string.h>



//------------------------------ Using Namespaces ----------------------
using namespace std;
using namespace IO;

//------------------------------ Constructor -------------------

Select::Select ( )
: Common::UseLogger ( )
, itsMaxFD ( -92 )
, itsFDList ( )
{
   FD_ZERO ( & itsFD_SET );
}


Select::Select (const std::string & aName , const LogLevel_e & aLogLevel)
: Common::UseLogger ( 0, aLogLevel, aName )
, itsMaxFD ( -1 )
, itsFDList ( )
{

   FD_ZERO ( & itsFD_SET );

}

Select::Select (const std::string & aName , const LogLevel_e & aLogLevel,  const FDList_t & anFDList )
: Common::UseLogger ( 0, aLogLevel, aName )
, itsMaxFD ( -1 )
, itsFDList (  )
{

   FD_ZERO ( & itsFD_SET );

   cFDListIterator_t iteratorList;
   for(iteratorList = anFDList.begin(); iteratorList != anFDList.end(); ++iteratorList)
   {
    Select::Add(*iteratorList);   //updates FDList
   } //for
}

//------------------------------ Destructor ----------------------------

Select::~Select (  )
{
/// nothing
}

//add to fd_set
void Select::Add(int aFD)
{
   FD_SET((uint4) aFD, & itsFD_SET);   //cast for win32
   itsFDList.push_back(aFD);           //not sorted !

//update maximum
   if (aFD > itsMaxFD) itsMaxFD = aFD;
}


//add to fd_set
void Select::Remove(int aFD)
{
   FD_CLR((uint4) aFD, & itsFD_SET);   //cast for win32
   itsFDList.remove(aFD);

//update maximum
   if (aFD == itsMaxFD) 
   { 
    //find second highest FD
    itsMaxFD = -1; 
    cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
    if (*iteratorList > itsMaxFD) itsMaxFD = *iteratorList;
   } //for
  }//if
}


int Select::Can_Read(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, FDList_t & theFDList) const
{
   fd_set tmpFD_SET = itsFD_SET;                  //FIXME: check structure copy

   timeval tmpTimeout;
   tmpTimeout.tv_sec = aSecondsTimeout;
   tmpTimeout.tv_usec = aMicrosecondsTimeout;

   int result_ready = select( itsMaxFD + 1, &tmpFD_SET, 0, 0, & tmpTimeout);

   if (result_ready < 0)
   {
      WARNLOG() << "Can_Read: read select failed with error "<<errno << ":"<<strerror(errno)<<endl;
      return result_ready;
   }

//create resulting FD List for caller
   theFDList.clear();
   cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
      if ( FD_ISSET(*iteratorList, & tmpFD_SET)) theFDList.push_back(*iteratorList);
   }                                              //for

   return result_ready;

}

//NOTE: uses a blocking select call without timeout
int Select::Can_Read(FDList_t & theFDList) const
{
   fd_set tmpFD_SET = itsFD_SET;                  //FIXME: check structure copy

   int result_ready = select( itsMaxFD + 1, &tmpFD_SET, 0, 0, 0);

   if (result_ready < 0)
   {
      WARNLOG() << "Can_Read(): read select failed with error "<<errno << ":"<<strerror(errno)<<endl;
      return result_ready;
   }

//create resulting FD List for caller
   theFDList.clear();
   cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
      if ( FD_ISSET(*iteratorList, & tmpFD_SET)) theFDList.push_back(*iteratorList);
   }                                              //for

   return result_ready;

}

int Select::Can_Write(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, FDList_t & theFDList) const
{
   fd_set tmpFD_SET = itsFD_SET;                  //FIXME: check structure copy

   timeval tmpTimeout;
   tmpTimeout.tv_sec = aSecondsTimeout;
   tmpTimeout.tv_usec = aMicrosecondsTimeout;

   int result_ready = select( itsMaxFD + 1, 0, & tmpFD_SET, 0, & tmpTimeout);

   if (result_ready < 0)
   {
      WARNLOG() << "Can_Write: write select failed with error "<<errno << ":"<<strerror(errno)<<endl;
      return result_ready;
   }

//create resulting FD List for caller
   theFDList.clear();
   cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
      if ( FD_ISSET(*iteratorList, & tmpFD_SET)) theFDList.push_back(*iteratorList);
   }                                              //for

   return result_ready;

}


int Select::Can_Write(FDList_t & theFDList) const
{
   fd_set tmpFD_SET = itsFD_SET;                  //FIXME: check structure copy

   int result_ready = select( itsMaxFD + 1, 0, & tmpFD_SET, 0, 0);

   if (result_ready < 0)
   {
      WARNLOG() << "Can_Write: write select failed with error "<<errno << ":"<<strerror(errno)<<endl;
      return result_ready;
   }

//create resulting FD List for caller
   theFDList.clear();
   cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
      if ( FD_ISSET(*iteratorList, & tmpFD_SET)) theFDList.push_back(*iteratorList);
   }                                              //for

   return result_ready;

}



//adds its own handles to the provided list
void Select::GetEventHandles(FDList_t & theFDList) const
{
   //NOTE: do not clear the list, just add
   cFDListIterator_t iteratorList;

   for(iteratorList = itsFDList.begin(); iteratorList != itsFDList.end(); ++iteratorList)
   {
    theFDList.push_back(*iteratorList);
   }                                              //for

 return;  

}

//------------------------------ Logging ------------------------------
void Select::Log( ostream & aStreamRef ) const
{
   Common::LogFormat tmpLogFormat( 10 );
   Log( aStreamRef, tmpLogFormat );
}


void Select::Log( ostream & aStreamRef, Common::LogFormat & aLogFormat ) const
{
   aLogFormat . LogBeginStruct( aStreamRef, "IO_Select" );
   aLogFormat . LogElement( aStreamRef, "MaxFD" );
   aLogFormat . LogDecValue( aStreamRef, itsMaxFD );

   aLogFormat . LogElement( aStreamRef, "FDList" );
   aLogFormat . LogBeginStruct( aStreamRef, "FDList_t" );
   {
      cFDListIterator_t iterator;
      for(iterator = itsFDList.begin(); iterator != itsFDList.end(); ++iterator)
      {
         aLogFormat . LogElement(aStreamRef, "FD");
         aLogFormat . LogDecValue( aStreamRef, *iterator );
      }                                           //for
   }                                              //if
   aLogFormat . LogEndStruct( aStreamRef );
   aLogFormat . LogEndStruct( aStreamRef );
}


//End of File
