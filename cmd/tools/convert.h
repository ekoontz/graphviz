/* $Id: convert.h,v 1.2 2008/01/09 20:50:35 erg Exp $ $Revision: 1.2 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CONVERT_H
#define CONVERT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef USE_CGRAPH
#include <cgraph.h>
#include <cghdr.h>
#else
#include <agraph.h>
#endif
#include <stdio.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <string.h>

    extern void dot_to_gxl(Agraph_t *, FILE *);
#ifdef HAVE_LIBEXPAT
    extern Agraph_t *gxl_to_dot(FILE *);
#endif

#endif

#ifdef __cplusplus
}
#endif
