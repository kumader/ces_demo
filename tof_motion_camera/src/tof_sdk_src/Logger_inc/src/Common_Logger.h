///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- CppClass
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 3850 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The definitions for class Logger
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Tue Jul 13 21:14:41 2004
//              automatically generated code
//              manually modified
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_Logger_
#define _Common_Logger_

#ifdef USE_IDENT
#ident "$Header$"
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include <sstream>
#include <string>

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Common
namespace Common
{

   class UseLogger;

//------------------------------ Exported Class Definitions ------------

/// The definition of class Logger
   class Logger
   {
      public:

//   Use Default Copy Constructor
//   Use Default Assignment Operator

/// Default Constructor
         Logger( );

/// Special Constructor
         Logger (const std::string & aName);

/// Destructor
         ~Logger( );

/// Write human readable representation of content
         void Log( std::ostream & aStreamRef ) const;

/// Write human readable representation with indentation
         void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

//  Arithmetic operators
/// Equal operator
         bool operator == (const Logger & aRef) const;

/// Less operator
         bool operator < (const Logger & aRef) const;

///@name Set and Get functions for all members
//@{
// The member Drop
///  The Get function for member Drop
         bool   GetDrop( ) const;
///  The Set function for member Drop
         void    SetDrop( bool aValue );
//----------------------------------------------------
// The member Name
///  The Get function for member Name
         std::string   GetName( ) const;
///  The Set function for member Name
         void    SetName( std::string aValue );
//----------------------------------------------------

//@}

///@name Special Functions
//@{
/// Get the timestamp
	 static std::string Timestamp( void );
/// Get the datestamp
	 static std::string Datestamp( void );
/// Get a date and a timestamp
	 static std::string DateTimestamp( void );

/// The debug function for logging
	 std::ostringstream & debug( const UseLogger & anObject );
/// The error function for logging
          std::ostringstream & error( const UseLogger & anObject );
/// The warn function for logging
	 std::ostringstream & warn( const UseLogger & anObject );
/// The info function for logging
	 std::ostringstream & info( const UseLogger & anObject );
/// The trace function for logging
	 std::ostringstream & trace( const UseLogger & anObject );
/// The log function for logging
	 std::ostringstream & log( const UseLogger & anObject );
/// The raw function for logging
	 std::ostringstream & raw( );

//@}

      private:

//Inhibit
/// Write content into buffer
         bool WriteToBuffer( uint1 * buffer
            , uint2 aBufferSize
            , uint2 & aByteOffset ) const;
/// Read content from buffer
         bool ReadFromBuffer( const uint1 * buffer
            , uint2 aBufferSize
            , uint2 & aByteOffset );


//   All the Elements

         static bool itsDrop;
         static std::string itsName;

         bool itsErrorFlag;                   //flag error logging for destructor
         std::ostringstream itsStreamBuffer;

   };                                             // End of class Logger

//------------------------------ Inline Functions ----------------------
   inline bool Logger::operator == (const Logger & aRef) const
   {
      if ( itsErrorFlag != aRef.itsErrorFlag ) return false;
      return true;
   }

   inline bool Logger::operator < (const Logger & aRef) const
   {
      if ( itsErrorFlag >= aRef.itsErrorFlag ) return false;
      return true;                                //min 1 attribute in class
   }

   inline std::ostream & operator << ( std::ostream & aStreamRef, const Logger & aRef )
   {
      aRef . Log( aStreamRef );
      return aStreamRef;
   }

   inline bool Logger::GetDrop( ) const
   {
      return itsDrop;
   }

   inline void Logger::SetDrop( bool aValue )
   {
      itsDrop = aValue;
   }

   inline std::string Logger::GetName( ) const
   {
      return itsName;
   }

   inline void Logger::SetName( std::string aValue )
   {
      itsName = aValue;
   }


};                                                // End of namespace Common
#endif
