/* $Id: gcommon.c,v 1.2 2005/04/08 20:45:34 erg Exp $ $Revision: 1.2 $ */
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

/* Lefteris Koutsofios - AT&T Labs Research */

#include "common.h"
#include "g.h"
#include "gcommon.h"
#include "mem.h"

int Gxfd;
Widget Groot;
Display *Gdisplay;
int Gpopdownflag;
int Gscreenn;
int Gdepth;

int Ginitgraphics (void) {
    return 0;
}

int Gtermgraphics (void) {
    return 0;
}

int Gsync (void) {
    return 0;
}

int Gresetbstate (int wi) {
    return 0;
}

int Gprocessevents (int waitflag, int mode) {
    return 0;
}
