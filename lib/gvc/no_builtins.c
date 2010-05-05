/* $Id: no_builtins.c,v 1.5 2007/06/08 22:09:14 erg Exp $ $Revision: 1.5 $ */
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gvcext.h"

#if defined(GVDLL) && !defined(ENABLE_LTDL)
lt_symlist_t lt_preloaded_symbols[] = { { 0, 0 } };
#else
const lt_symlist_t lt_preloaded_symbols[] = { { 0, 0 } };
#endif
