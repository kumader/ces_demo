///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- DumperUint1RegMap
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 4479 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++ 
// DESCRIPTION: The definitions for class DumperUint1RegMap 
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Feb 24 15:51:30 2018
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_DumperUint1RegMap_
#define _Common_DumperUint1RegMap_

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

/// The definition of class DumperUint1RegMap
class DumperUint1RegMap
{
public:

   //enums


   //   Use Default Copy Constructor
   //   Use Default Assignment Operator 

   /// Default Constructor
        DumperUint1RegMap( );

   /// Special Constructor
        DumperUint1RegMap( const uint1 * aBufferPtr, const uint2 & aSize );

   /// Destructor
        ~DumperUint1RegMap( );

   /// Write human readable representation of content
        void Log( std::ostream & aStreamRef ) const;
   
   /// Write human readable representation with indentation
        void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

   //  Arithmetic operators
   /// Equal operator 
       bool operator == (const DumperUint1RegMap & aRef) const;
   
   /// Less operator 
       bool operator < (const DumperUint1RegMap & aRef) const;

   ///@name Set, Get and other functions for all members 
   //@{
         //----------------------------------------------------
         //----------------------------------------------------

   //@}

private:
  

   //   All the Elements

         const uint1 * itsBufferPtr;
         uint2 itsSize;


}; // End of class DumperUint1RegMap

//------------------------------ Inline Functions ----------------------
inline bool DumperUint1RegMap::operator == (const DumperUint1RegMap & aRef) const
{
   if ( ! (itsBufferPtr == aRef.itsBufferPtr) ) return false;
   if ( ! (itsSize == aRef.itsSize) ) return false;

   return true;
}

inline bool DumperUint1RegMap::operator < (const DumperUint1RegMap & aRef) const
{
   if ( ! (itsBufferPtr < aRef.itsBufferPtr) ) return false;
   if ( ! (itsSize < aRef.itsSize) ) return false;

   return true; //min 1 attribute in class
}


inline std::ostream & operator << ( std::ostream & aStreamRef, const DumperUint1RegMap & aRef )
{
   aRef . Log( aStreamRef );
   return aStreamRef;
}






}; // End of namespace Common

#endif

