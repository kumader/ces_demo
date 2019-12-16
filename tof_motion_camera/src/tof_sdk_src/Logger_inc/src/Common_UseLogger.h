///////////////////////////////////////////////////////////////////////////
//     PROJECT: Cpp -- UseLogger
//   COPYRIGHT: R. Hranitzky
//    $RCSfile$
//   $Revision: 2964 $
//      AUTHOR: R. Hranitzky
//    LANGUAGE: C++
// DESCRIPTION: The definitions for class UseLogger
//              used /usr/local/bin/CppClassCoder.pl to create this file
//              created Sat Jul 24 07:42:06 2004
//              automatically generated code
///////////////////////////////////////////////////////////////////////////

#ifndef _Common_UseLogger_
#define _Common_UseLogger_

#ifdef USE_IDENT
#ident "$Header$"
#endif

//------------------------------ Includes ------------------------------
#include "General.h"
#include <iostream>
#include <string>
#include "Common_Logger.h"

//------------------------------ Declarations --------------------------
namespace Common { class LogFormat; }

/// The namespace Common
namespace Common
{

#define DEBUGLOG() \
if (GetLogLevel() < Common::UseLogger::S_DEBUG) ; \
else Common::Logger().debug(*this)

#define INFOLOG() \
if (GetLogLevel() < Common::UseLogger::S_INFO) ; \
else Common::Logger().info(*this)


#define WARNLOG() \
if (GetLogLevel() < Common::UseLogger::S_ERROR) ; \
else Common::Logger().warn(*this)

#define ERRORLOG() \
if (GetLogLevel() < Common::UseLogger::S_ERROR) ; \
else Common::Logger().error(*this)

#define TRACELOG() \
Common::Logger().trace(*this)

#define LOGLOG() \
Common::Logger().log(*this)

#define RAWLOG() \
Common::Logger().raw( )

#define LOG_ASSERT(a,b) \
if (a) ; \
else { Common::Logger().error(*this) << b << std::endl; }


//------------------------------ Exported Class Definitions ------------

/// The definition of class UseLogger
   class UseLogger
   {
      public:

         enum LogLevel_e
         {
            S_NO_LOGGING = 0
            , S_ERROR = 1
            , S_WARN = 2
            , S_INFO = 3
            , S_DEBUG = 4
         };

// Use Default Copy Constructor
// Use Default Assignment Operator

/// Constructor
         UseLogger( );

/// Special Constructor
         UseLogger (const uint4 & aCycle, const LogLevel_e & aLogLevel, const std::string & aName);

/// Destructor
         ~UseLogger( );     //NOTE: not virtual, so don't use polymorphism to access derived classes

/// Write human readable representation of content
         void Log( std::ostream & aStreamRef ) const;

/// Write human readable representation with indentation
         void Log( std::ostream & aStreamRef, Common::LogFormat & aLogFormat ) const;

/// Provide a function to convert enum LogLevel_e to string
         static std::string ConvertToString( LogLevel_e aLogLevel );

/// Provide a function to convert a string to the enum LogLevel_e
         static bool ConvertFromString( LogLevel_e & theResult, const std::string & aString);

//  Arithmetic operators
/// Equal operator
         bool operator == (const UseLogger & aRef) const;

/// Less operator
         bool operator < (const UseLogger & aRef) const;

///@name Set and Get functions for all members
//@{
// The member Cycle
///  The Get function for member Cycle
         uint4   GetCycle( ) const;
///  The Set function for member Cycle
         void    SetCycle( uint4 aValue );
//----------------------------------------------------
// The member LogLevel
///  The Get function for member LogLevel
         LogLevel_e   GetLogLevel( ) const;
///  The Set function for member LogLevel
         void    SetLogLevel( LogLevel_e aValue );
//----------------------------------------------------
// The member Name
///  The Get function for member Name
	 std::string   GetName( ) const;
///  The Set function for member Name
         void    SetName( std::string aValue );
//----------------------------------------------------
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


// All the Elements

         uint4 itsCycle;
         LogLevel_e itsLogLevel;
	 std::string itsName;

   };                                             // End of class UseLogger

//------------------------------ Inline Functions ----------------------
   inline bool UseLogger::operator == (const UseLogger & aRef) const
   {
      if ( itsCycle != aRef.itsCycle ) return false;
      if ( itsLogLevel != aRef.itsLogLevel ) return false;
      if ( itsName != aRef.itsName ) return false;

      return true;
   }

   inline bool UseLogger::operator < (const UseLogger & aRef) const
   {
      if ( itsCycle >= aRef.itsCycle ) return false;
      if ( itsLogLevel >= aRef.itsLogLevel ) return false;
      if ( itsName >= aRef.itsName ) return false;

      return true;                                //min 1 attribute in class
   }

   inline std::ostream & operator << ( std::ostream & aStreamRef, const UseLogger & aRef )
   {
      aRef . Log( aStreamRef );
      return aStreamRef;
   }

   inline uint4 UseLogger::GetCycle( ) const
   {
      return itsCycle;
   }

   inline void UseLogger::SetCycle( uint4 aValue )
   {
      itsCycle = aValue;
   }
   inline UseLogger::LogLevel_e UseLogger::GetLogLevel( ) const
   {
      return itsLogLevel;
   }

   inline void UseLogger::SetLogLevel( LogLevel_e aValue )
   {
      itsLogLevel = aValue;
   }
   inline std::string UseLogger::GetName( ) const
   {
      return itsName;
   }

   inline void UseLogger::SetName( std::string aValue )
   {
      itsName = aValue;
   }

};                                                // End of namespace Common
#endif
