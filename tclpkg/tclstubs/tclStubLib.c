/* $Id: tclStubLib.c,v 1.2 2005/02/24 00:57:34 ellson Exp $ $Revision: 1.2 $ */
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

/* this dummy file is here to fool libtool and automake */
#include "tcl.h"

/* need to reference an entry point to fool Sun's ld */
void tclstubs_dummy(void)
{
    Tcl_InitStubs(0, 0, 0);
}
