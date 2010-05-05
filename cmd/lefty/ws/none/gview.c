/* $Id: gview.c,v 1.2 2005/04/08 20:45:34 erg Exp $ $Revision: 1.2 $ */
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

int GVcreatewidget (
    Gwidget_t *parent, Gwidget_t *widget, int attrn, Gwattr_t *attrp
) {
    return -1;
}

int GVsetwidgetattr (Gwidget_t *widget, int attrn, Gwattr_t *attrp) {
    return 0;
}

int GVgetwidgetattr (Gwidget_t *widget, int attrn, Gwattr_t *attrp) {
    return 0;
}

int GVdestroywidget (Gwidget_t *widget) {
    return 0;
}
