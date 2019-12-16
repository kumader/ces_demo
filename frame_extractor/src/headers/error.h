/**
 *
 * Global Error Definitions.
 * @see @ref page_error_codes
 *
 * @file
 * Copyright &copy; Audi Electronics Venture GmbH. All rights reserved
 *
 * $Author: FOX0IY4 $
 * $Date: 2013-11-22 15:06:18 +0100 (Fr, 22 Nov 2013) $
 * $Revision: 306 $
 *
 * @remarks
 *
 */
#ifndef _ERROR_BASE_HEADER_
#define _ERROR_BASE_HEADER_

#ifndef A_UTILS_ERRORS_H

/// Facility code zero
#define FAC_CODE_NULL                   0

/**
 * For general error handling functionality see @ref page_error_codes.
 */
#define _FACILITY_MASK_                0x3FFC0000L
/**
 * For general error handling functionality see @ref page_error_codes.
 */
#define _ERROR_CODE_MASK_              0x0003FFFFL
/**
 * For general error handling functionality see @ref page_error_codes.
 */
#define _MAKE_ERROR(s)                 ( - ( ( s ) ) )

/// Check if result is OK.
#define IS_OK(s)                       ( ( s ) >= 0L )

/// Check if result is failed.
#define IS_FAILED(s)                   ( ( s ) < 0L )

/// Extract the error code from a given tResult value.
#define ERROR_CODE(s)                  ( ( - ( s ) ) & _ERROR_CODE_MASK_ )

/// Return status ERR_NOERROR from the current function. This requires the calling function's
/// return type to be tResult.
#define RETURN_NOERROR                 return ERR_NOERROR

/// Return from the current function using a specific error code. This requires the calling function's
/// return type to be tResult.
#if (__UCOM_ASSERT_WHEN_LOGGING_ERRORS == 1)
#define RETURN_ERROR(code)             assert(IS_OK(code)); return (code)
#else
#define RETURN_ERROR(code)             return (code)
#endif

/// Return from current function is expression is failed. This requires the calling function's
/// return type to be tResult.
#define RETURN_IF_FAILED(s)            { tResult __result = (s); if (IS_FAILED(__result)) { RETURN_ERROR(__result); } }

/// Return from current function is pointer is NULL. The error code that is returned is ERR_POINTER. 
/// This requires the calling function's return type to be tResult.
#define RETURN_IF_POINTER_NULL(_ptr)    if ( (tVoid*) ( _ptr ) == NULL ) { RETURN_ERROR(ERR_POINTER); }

/// This macro asserts if a pointer is NULL.
/// This assertion is only present in Debug builds and it does nothing on Release builds.
#ifdef _DEBUG
#define ASSERT_IF_POINTER_NULL(_ptr)    A_UTILS_ASSERT((tVoid*) ( _ptr ) != NULL);
#else
#define ASSERT_IF_POINTER_NULL(_ptr)
#endif

/// Return status ERR_FAILED from the current function. This requires the calling function's
/// return type to be tResult.
//#define RETURN_FAILED                  RETURN_ERROR(ERR_FAILED)

/// Return status ERR_UNEXPECTED from the current function. This requires the calling function's
/// return type to be tResult.
//#define RETURN_UNEXPECTED              RETURN_ERROR(ERR_UNEXPECTED)

/**
 *  Error constants
 */
enum
{
    ERR_NOERROR                    = 0L,                //!< 0 
    ERR_UNKNOWN                    = _MAKE_ERROR( 2 ),  //!< -2
    ERR_UNEXPECTED                 = _MAKE_ERROR( 3 ),  //!< -3
    ERR_POINTER                    = _MAKE_ERROR( 4 ),  //!< -4
    ERR_INVALID_ARG                = _MAKE_ERROR( 5 ),  //!< -5
    ERR_INVALID_FUNCTION           = _MAKE_ERROR( 6 ),  //!< -6
    ERR_INVALID_ADDRESS            = _MAKE_ERROR( 7 ),  //!< -7
    ERR_INVALID_HANDLE             = _MAKE_ERROR( 8 ),  //!< -8
    ERR_INVALID_FLAGS              = _MAKE_ERROR( 9 ),  //!< -9
    ERR_INVALID_INDEX              = _MAKE_ERROR( 10),  //!< -10
    ERR_INVALID_FILE               = _MAKE_ERROR( 11 ), //!< -11
    ERR_MEMORY                     = _MAKE_ERROR( 12 ), //!< -12
    ERR_TIMEOUT                    = _MAKE_ERROR( 13 ), //!< -13
    ERR_OUT_OF_SYNC                = _MAKE_ERROR( 14 ), //!< -14
    ERR_RESOURCE_IN_USE            = _MAKE_ERROR( 15 ), //!< -15
    ERR_NOT_IMPL                   = _MAKE_ERROR( 16 ), //!< -16
    ERR_NO_INTERFACE               = _MAKE_ERROR( 17 ), //!< -17
    ERR_NO_CLASS                   = _MAKE_ERROR( 18 ), //!< -18
    ERR_NOT_SUPPORTED              = _MAKE_ERROR( 19 ), //!< -19
    ERR_NOT_FOUND                  = _MAKE_ERROR( 20 ), //!< -20
    ERR_CANCELLED                  = _MAKE_ERROR( 21 ), //!< -21
    ERR_RETRY                      = _MAKE_ERROR( 22 ), //!< -22
    ERR_FILE_NOT_FOUND             = _MAKE_ERROR( 23 ), //!< -23
    ERR_PATH_NOT_FOUND             = _MAKE_ERROR( 24 ), //!< -24
    ERR_ACCESS_DENIED              = _MAKE_ERROR( 25 ), //!< -25
    ERR_NOT_READY                  = _MAKE_ERROR( 26 ), //!< -26
    ERR_OPEN_FAILED                = _MAKE_ERROR( 27 ), //!< -27
    ERR_IO_INCOMPLETE              = _MAKE_ERROR( 28 ), //!< -28
    ERR_IO_PENDING                 = _MAKE_ERROR( 29 ), //!< -29
    ERR_NOACCESS                   = _MAKE_ERROR( 30 ), //!< -30
    ERR_BAD_DEVICE                 = _MAKE_ERROR( 31 ), //!< -31
    ERR_DEVICE_IO                  = _MAKE_ERROR( 32 ), //!< -32
    ERR_DEVICE_NOT_READY           = _MAKE_ERROR( 33 ), //!< -33
    ERR_DEVICE_IN_USE              = _MAKE_ERROR( 34 ), //!< -34
    ERR_NOT_CONNECTED              = _MAKE_ERROR( 35 ), //!< -35
    ERR_UNKNOWN_FORMAT             = _MAKE_ERROR( 36 ), //!< -36
    ERR_NOT_INITIALISED            = _MAKE_ERROR( 37 ), //!< -37
    ERR_FAILED                     = _MAKE_ERROR( 38 ), //!< -38
    ERR_END_OF_FILE                = _MAKE_ERROR( 39 ), //!< -39
    ERR_INVALID_STATE              = _MAKE_ERROR( 40 ), //!< -40
    ERR_EXCEPTION_RAISED           = _MAKE_ERROR( 41 ), //!< -41
    ERR_INVALID_TYPE               = _MAKE_ERROR( 42 ), //!< -42
    ERR_EMPTY                      = _MAKE_ERROR( 43 ), //!< -43
    ERR_INVALID_VERSION            = _MAKE_ERROR( 44 ), //!< -44
    ERR_INVALID_LICENSE            = _MAKE_ERROR( 45 ), //!< -45
    ERR_SERVICE_NOT_FOUND          = _MAKE_ERROR( 46 ), //!< -46
    ERR_DAU                        = _MAKE_ERROR( 47 ), //!< -47
    ERR_IDLE_NOWAIT                = _MAKE_ERROR( 48 ), //!< -48
    ERR_OUT_OF_RANGE               = _MAKE_ERROR( 49 ), //!< -49
    ERR_KNOWN_PROBLEM              = _MAKE_ERROR( 50 )  //!< -50
};

/// fixed spelling error, but kept the old version for compatibility
#define ERR_RESSOURCE_IN_USE ERR_RESOURCE_IN_USE

#endif // A_UTILS_ERRORS_H

#endif // _ERROR_BASE_HEADER_
