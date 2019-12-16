///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DumperUint2RegMap
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class DumperUint2RegMap 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Feb 24 15:41:58 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_DumperUint2RegMap_
#define _Common_DumperUint2RegMap_

#ifdef USE_IDENT
#ident "$Header: $" 
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>

#include <string>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Common
namespace Common
{

//------------------------------ Exported Class Definitions ------------

/// The definition of class DumperUint2RegMap
class DumperUint2RegMap
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        DumperUint2RegMap( );

   /// Special Constructor
        DumperUint2RegMap( const uint2 * aBufferPtr, const uint2 & aSize );

   /// Destructor
        ~DumperUint2RegMap( );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const DumperUint2RegMap & aRef) const;
   
   /// Less operator 
       bool operator < (const DumperUint2RegMap & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         const uint2 * itsBufferPtr;
         uint2 itsSize;


}; // End of class DumperUint2RegMap

//------------------------------ Inline Functions ----------------------
inline bool DumperUint2RegMap::operator == (const DumperUint2RegMap & aRef) const
{
   if ( ! (itsBufferPtr == aRef.itsBufferPtr) ) return false;
   if ( ! (itsSize == aRef.itsSize) ) return false;

   return true;
}

inline bool DumperUint2RegMap::operator < (const DumperUint2RegMap & aRef) const
{
   if ( ! (itsBufferPtr < aRef.itsBufferPtr) ) return false;
   if ( ! (itsSize < aRef.itsSize) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const DumperUint2RegMap & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}






}; // End of namespace Common

#endif

