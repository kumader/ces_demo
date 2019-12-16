/***********************************************************************
 *
 *     PROJECT: cpp
 *   COPYRIGHT: Robert Hranitzky 
 *    $RCSfile$
 *   $Revision: 4070 $
 *      AUTHOR: Robert Hranitzky 
 *    LANGUAGE: C++
 * DESCRIPTION: all general definitions  
 *
 ************************************************************************/

#ifndef _GENERAL_H_
#define _GENERAL_H_

#ifdef USE_IDENT
/*
 * ident adds a version string to object file 
 * 
 */
# ident "$Id:"
#endif

/*----------------------------- Constants ------------------------------*/

/*
 * Limits for the standardized integral types.
 */

#define SINT1_MAX 127
#define SINT1_MIN (-SINT1_MAX - 1)

#define SINT2_MAX 32767
#define SINT2_MIN (-SINT2_MAX - 1)

#define SINT4_MAX 2147483647L
#define SINT4_MIN (-SINT4_MAX - 1)


#define UINT1_MIN 0U
#define UINT1_MAX 255U

#define UINT2_MIN 0U
#define UINT2_MAX 65535U

#define UINT4_MIN 0U
#define UINT4_MAX 4294967295U 


/*------------------------ Macros and Definitions ----------------------*/

/*------------------------------ Types ---------------------------------*/

#endif /* ! _GENERAL_H_ */

/* architecture dependent definitions */
#ifdef _TARGET_ARCH_X86_HOSTSIM_
# include "General_x86-hostsim.h"
#else
#ifdef _TARGET_ARCH_BLACKFIN_
# include "General_blackfin.h"
#else
#ifdef _TARGET_ARCH_ZORAN_
# include "General_zoran.h"
#else
#ifdef _TARGET_ARCH_W32_
# include "General_w32.h"
#else
#ifdef _TARGET_ARCH_ARMHF_
# include "General_armhf.h"
#else
#error "Please define a target architecture (_TARGET_ARCH_???????_)!"
#endif  /* _TARGET_ARCH_ARMHF_ */
#endif  /* _TARGET_ARCH_W32_ */
#endif  /* _TARGET_ARCH_ZORAN_ */
#endif  /* _TARGET_ARCH_BLACKFIN_ */
#endif  /* _TARGET_ARCH_X86_HOSTSIM_ */

/* End of file */
