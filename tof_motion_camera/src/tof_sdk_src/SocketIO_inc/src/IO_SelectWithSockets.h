///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The definitions for class SelectWithSockets
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 13:25:18 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _IO_SelectWithSockets_
#define _IO_SelectWithSockets_

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include "Common_UseLogger.h"
#include "IO_Socket.h"
#include "IO_Select.h"
#include <list>
#include <map>

//------------------------------ Declarations --------------------------

/// The namespace IO
namespace IO
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class SelectWithSockets
   class SelectWithSockets : public Select
   {
      public:

        //SocketList
         typedef std::list< IO::Socket >                         SocketList_t;
         typedef SocketList_t::const_iterator                   cSocketListIterator_t;
         typedef SocketList_t::iterator                          SocketListIterator_t;


        //Socket Map: int is the file descriptor
         typedef std::map< int, IO::Socket >                     SocketMap_t;
         typedef SocketMap_t::const_iterator                    cSocketMapIterator_t;
         typedef SocketMap_t::iterator                           SocketMapIterator_t;


//   Use Default Copy Constructor
//   Use Default Assignment Operator

/// Default Constructor (USE ONLY FOR TESTING)
         SelectWithSockets( );

         SelectWithSockets(  const std::string & aName
            , const Common::UseLogger::LogLevel_e & aLogLevel
            );

/// Destructor
         ~SelectWithSockets( );

/// Write human readable representation of content
         void Log( std::ostream & aStreamRef ) const;

/// Write human readable representation with indentation
         void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

//  Arithmetic operators
/// Equal operator
         bool operator == (const SelectWithSockets & aRef) const;

/// Less operator
         bool operator < (const SelectWithSockets & aRef) const;

///@name Set and Get functions for all members
//@{
///  The Add function for IO::Sockets
         void    Add( const IO::Socket & aSocket );
///  The Remove function for IO::Sockets
         void    Remove( const IO::Socket & aSocket );

///  The Can_Read function with timeout and list of sockets 
         int Can_Read(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, SocketList_t & theSocketList) const;

///  The Can_Read function without timeouts, with list of sockets 
         int Can_Read(SocketList_t & theSocketList) const;

///  The Can_Write function with timeout and list of sockets 
         int Can_Write(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, SocketList_t & theSocketList) const ;

///  The Can_Write function without timeout and list of sockets 
         int Can_Write(SocketList_t & theSocketList) const ;

///  The Find  function without timeout and list of sockets 
         bool Find(int aFD, IO::Socket & aSocketRef) const ;

//@}

      private:


//   All the Elements
         SocketMap_t itsSocketMap;                //internal administration
   };                                             // End of class SelectWithSockets

//------------------------------ Inline Functions ----------------------
   inline bool SelectWithSockets::operator == (const SelectWithSockets & aRef) const
   {
      return Select::operator == (aRef);
   }

   inline bool SelectWithSockets::operator < (const SelectWithSockets & aRef) const
   {
      return Select::operator < (aRef); 
   }

   inline std::ostream & operator << ( std::ostream & aStreamRef, const SelectWithSockets & aRef )
   {
      aRef . Log( aStreamRef );
      return aStreamRef;
   }

inline bool SelectWithSockets::Find(int aFD, IO::Socket & aSocketRef) const
{
  cSocketMapIterator_t iteratorMap = itsSocketMap.find(aFD);
  if ( iteratorMap == itsSocketMap.end() ) return false;
  aSocketRef = iteratorMap->second;
  return true;
}


};                                                // End of namespace IO
#endif
