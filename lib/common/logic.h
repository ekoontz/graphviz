/* $Id: logic.h,v 1.5 2006/01/28 00:20:45 ellson Exp $ $Revision: 1.5 $ */
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

#ifndef GV_LOGIC_H
#define GV_LOGIC_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined HAVE_STDBOOL_H && ! defined __cplusplus
#include <stdbool.h>
#endif

#define NOT(v) (!(v))

/* HAVE_BOOL only tested the CC compiler, we know C++ must define bool */
#if ! defined HAVE_BOOL && ! defined __cplusplus
typedef unsigned char bool;
#define false 0
#define true NOT(false)
#endif

#ifndef FALSE
#define	FALSE false
#endif
#ifndef TRUE
#define TRUE true
#endif

#ifndef NOTUSED
#define NOTUSED(var) (void) var
#endif

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef NIL
#define NIL(type) ((type)0)
#endif

#ifdef __cplusplus
}
#endif

#endif

