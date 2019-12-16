/**
 * A_UTILS portable integer type definitions.
 * based on pstdint.h Copyright &copy; 2005-2007 Paul Hsieh
 */
#ifndef _A_UTILS_PORTABLE_TYPES_H_
#define _A_UTILS_PORTABLE_TYPES_H_

#include <stddef.h>
#include <limits.h>
#include <signal.h>

#ifndef SIZE_MAX
#   define SIZE_MAX (~(size_t)0)
#endif

/*
 *  Deduce the type assignments from limits.h under the assumption that
 *  integer sizes in bits are powers of 2, and follow the ANSI
 *  definitions.
 */

#ifndef UINT8_MAX
#   define UINT8_MAX 0xff
#endif
#ifndef tUInt8
# if (UCHAR_MAX == UINT8_MAX) || defined (S_SPLINT_S)
    typedef unsigned char tUInt8;
# else
#   error "Platform not supported"
# endif
#endif

#ifndef INT8_MAX
#   define INT8_MAX 0x7f
#endif
#ifndef INT8_MIN
#   define INT8_MIN A_UTILS_INT8_C(0x80)
#endif
#ifndef tInt8
# if (SCHAR_MAX == INT8_MAX) || defined (S_SPLINT_S)
    typedef signed char tInt8;
#   define A_UTILS_INT8_C(v) ((tInt8) v)
# else
#   error "Platform not supported"
# endif
#endif

#ifndef UINT16_MAX
#   define UINT16_MAX 0xffff
#endif
#ifndef tUInt16
#if (UINT_MAX == UINT16_MAX) || defined (S_SPLINT_S)
  typedef unsigned int tUInt16;
#elif (USHRT_MAX == UINT16_MAX)
  typedef unsigned short tUInt16;
#else
#error "Platform not supported"
#endif
#endif

#ifndef INT16_MAX
#   define INT16_MAX 0x7fff
#endif
#ifndef INT16_MIN
#   define INT16_MIN A_UTILS_INT16_C(0x8000)
#endif
#ifndef tInt16
#if (INT_MAX == INT16_MAX) || defined (S_SPLINT_S)
    typedef signed int tInt16;
#   define A_UTILS_INT16_C(v) ((tInt16) (v))
#elif (SHRT_MAX == INT16_MAX)
    typedef signed short tInt16;
#   define A_UTILS_INT16_C(v) ((tInt16) (v))
#else
#error "Platform not supported"
#endif
#endif

#ifndef UINT32_MAX
#   define UINT32_MAX (0xffffffffUL)
#endif
#ifndef tUInt32
#if (ULONG_MAX == UINT32_MAX) || defined (S_SPLINT_S)
    typedef unsigned long tUInt32;
#elif (UINT_MAX == UINT32_MAX)
    typedef unsigned int tUInt32;
#elif (USHRT_MAX == UINT32_MAX)
    typedef unsigned short tUInt32;
#else
#error "Platform not supported"
#endif
#endif

#ifndef INT32_MAX
#   define INT32_MAX (0x7fffffffL)
#endif
#ifndef INT32_MIN
#   define INT32_MIN A_UTILS_INT32_C(0x80000000)
#endif
#ifndef tInt32
#if (LONG_MAX == INT32_MAX) || defined (S_SPLINT_S)
    typedef signed long tInt32;
#   define A_UTILS_INT32_C(v) v ## L
#elif (INT_MAX == INT32_MAX)
    typedef signed int tInt32;
#   define A_UTILS_INT32_C(v) v
#elif (SHRT_MAX == INT32_MAX)
    typedef signed short tInt32;
#   define A_UTILS_INT32_C(v) ((short) (v))
#else
#error "Platform not supported"
#endif
#endif

/*
 *  The macro a_utils_stdint_int64_defined is temporarily used to record
 *  whether or not 64 integer support is available.  It must be
 *  defined for any 64 integer extensions for new platforms that are
 *  added.
 */

#if !defined (a_utils_stdint_int64_defined)
#if (defined(__STDC__) && defined(__STDC_VERSION__)) || defined (S_SPLINT_S)
# if (__STDC__ && __STDC_VERSION >= 199901L) || defined (S_SPLINT_S)
#   define a_utils_stdint_int64_defined
    typedef long long tInt64;
    typedef unsigned long long tUInt64;
#   define A_UTILS_UINT64_C(v) v ## ULL
#   define A_UTILS_INT64_C(v) v ## LL
# endif
#endif
#endif

#if !defined (a_utils_stdint_int64_defined)
# if defined(__GNUC__)
#   define a_utils_stdint_int64_defined
    __extension__ typedef long long tInt64;
    __extension__ typedef unsigned long long tUInt64;
#   define A_UTILS_UINT64_C(v) v ## ULL
#   define A_UTILS_INT64_C(v) v ## LL   
# elif defined(__MWERKS__) || defined (__SUNPRO_C) || defined (__SUNPRO_CC) || defined (_LONG_LONG) || defined (_CRAYC) || defined (S_SPLINT_S) || defined (A_UTILS_PLATFORM_WITH_STDINT_INT64)
#   define a_utils_stdint_int64_defined
    typedef long long tInt64;
    typedef unsigned long long tUInt64;
#   define A_UTILS_UINT64_C(v) v ## ULL
#   define A_UTILS_INT64_C(v) v ## LL
# elif (defined(__WATCOMC__) && defined(__WATCOM_INT64__)) || (defined(_MSC_VER) && _INTEGRAL_MAX_BITS >= 64) || (defined (__BORLANDC__) && __BORLANDC__ > 0x460) || defined (__alpha) || defined (__DECC)
#   define a_utils_stdint_int64_defined
    typedef __int64 tInt64;
    typedef unsigned __int64 tUInt64;
#   define A_UTILS_UINT64_C(v) v ## UI64
#   define A_UTILS_INT64_C(v) v ## I64
# endif
#endif

#ifndef a_utils_stdint_int64_defined
#   error "Platform not supported"
#endif

#if !defined (LONG_LONG_MAX) && defined (A_UTILS_INT64_C)
#   define LONG_LONG_MAX A_UTILS_INT64_C (9223372036854775807)
#endif
#ifndef ULONG_LONG_MAX
#   define ULONG_LONG_MAX A_UTILS_UINT64_C (18446744073709551615)
#endif

#if !defined (INT64_MAX) && defined (A_UTILS_INT64_C)
#   define INT64_MAX A_UTILS_INT64_C (9223372036854775807)
#endif
#if !defined (INT64_MIN) && defined (A_UTILS_INT64_C)
#   define INT64_MIN A_UTILS_INT64_C (-9223372036854775808)
#endif
#if !defined (UINT64_MAX) && defined (A_UTILS_INT64_C)
#   define UINT64_MAX A_UTILS_UINT64_C (18446744073709551615)
#endif

#endif
