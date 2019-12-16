///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 1895 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The definitions for class Select
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sun Dec  2 13:25:18 2007
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _IO_Select_
#define _IO_Select_

#ifdef USE_IDENT
#ident "$Header: $"
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include "Common_UseLogger.h"
#include <list>

#ifdef _TARGET_ARCH_W32_
//ROH: try without #define _WIN32_WINNT _WIN32_WINNT_WIN8 // Windows 8.0
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#else
#include <sys/select.h>
#endif

//------------------------------ Declarations --------------------------

/// The namespace IO
namespace IO
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class Select
   class Select : public Common::UseLogger
   {
      public:

         typedef std::list< int >                   FDList_t;
         typedef FDList_t::const_iterator          cFDListIterator_t;
         typedef FDList_t::iterator                 FDListIterator_t;

//   Use Default Copy Constructor
//   Use Default Assignment Operator

/// Default Constructor (USE ONLY FOR TESTING)
         Select( );

         Select(  const std::string & aName
            , const Common::UseLogger::LogLevel_e & aLogLevel
            );

         Select(  const std::string & aName
            , const Common::UseLogger::LogLevel_e & aLogLevel
	    , const FDList_t & anFDList
            );

/// Destructor
         virtual ~Select( );    //support inheritance and polymorphism

/// Write human readable representation of content
         void Log( std::ostream & aStreamRef ) const;

/// Write human readable representation with indentation
         void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

//  Arithmetic operators
/// Equal operator
         bool operator == (const Select & aRef) const;

/// Less operator
         bool operator < (const Select & aRef) const;

///@name Set and Get functions for all members
//@{
//----------------------------------------------------
// The member MaxFD
///  The Get function for member MaxFD
         int   GetMaxFD( ) const;
///  The Set function for member MaxFD
         void    SetMaxFD( int aValue );
//----------------------------------------------------
///  The Add function for FDs
         void    Add( int aFD );
///  The Remove function for FDs
         void    Remove( int aFD );
///  The Can_Read function with timeout and list of descriptors
         int Can_Read(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, FDList_t & theFDList) const;
///  The Can_Read function without timeout (blocking)
         int Can_Read(FDList_t & theFDList) const;
///  The Can_Write function
         int Can_Write(const uint4 & aSecondsTimeout, const uint4 & aMicrosecondsTimeout, FDList_t & theFDList) const;
///  The Can_Write function
         int Can_Write(FDList_t & theFDList) const;
///  The GetEventHandles function
         void GetEventHandles(FDList_t & theFDList) const;

//@}

      private:

//   All the Elements

         fd_set    itsFD_SET;                     //os
         int itsMaxFD;                            //internal administration
         FDList_t  itsFDList;                     //internal administration

   };                                             // End of class Select

//------------------------------ Inline Functions ----------------------
   inline bool Select::operator == (const Select & aRef) const
   {
      if ( itsMaxFD != aRef.itsMaxFD ) return false;

      return true;
   }

   inline bool Select::operator < (const Select & aRef) const
   {
      if ( itsMaxFD >= aRef.itsMaxFD ) return false;

      return true;                                //min 1 attribute in class
   }

   inline std::ostream & operator << ( std::ostream & aStreamRef, const Select & aRef )
   {
      aRef . Log( aStreamRef );
      return aStreamRef;
   }

   inline int Select::GetMaxFD( ) const
   {
      return itsMaxFD;
   }

   inline void Select::SetMaxFD( int aValue )
   {
      itsMaxFD = aValue;
   }

};                                                // End of namespace IO
#endif
