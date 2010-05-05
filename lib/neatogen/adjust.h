/* $Id: adjust.h,v 1.10 2008/05/28 17:44:56 erg Exp $ $Revision: 1.10 $ */
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



#ifndef ADJUST_H
#define ADJUST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <geom.h>

#define DFLT_MARGIN     4   /* 4 points */

typedef enum {
    AM_NONE, AM_VOR,
    AM_SCALE, AM_NSCALE, AM_SCALEXY, AM_PUSH, AM_PUSHPULL,
    AM_ORTHO, AM_ORTHO_YX, AM_ORTHOXY, AM_ORTHOYX,
    AM_PORTHO, AM_PORTHO_YX, AM_PORTHOXY, AM_PORTHOYX, AM_COMPRESS,
    AM_VPSC, AM_IPSEP, AM_FDP
} adjust_mode;

typedef struct {
    adjust_mode mode;
    char *attrib;
    char *print;
} adjust_data;

typedef struct {
    float x, y;
    boolean doAdd;  /* if true, x and y are in points */
} expand_t;

    extern expand_t sepFactor(graph_t * G);
    extern expand_t esepFactor(graph_t * G);
    extern int adjustNodes(graph_t * G);
    extern void normalize(graph_t * g);
    extern int removeOverlap(graph_t * G);
    extern int removeOverlapAs(graph_t*, char*);
    extern int cAdjust(graph_t *, int);
    extern int scAdjust(graph_t *, int);
    extern adjust_data *graphAdjustMode(graph_t *G);

#ifdef __cplusplus
}
#endif
#endif
