/* $Id: txtview.h,v 1.2 2005/04/08 20:45:34 erg Exp $ $Revision: 1.2 $ */
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

/* Lefteris Koutsofios - AT&T Labs Research */

#ifndef _TXTVIEW_H
#define _TXTVIEW_H
void TXTinit (Grect_t);
void TXTterm (void);
int TXTmode (int argc, lvar_t *argv);
int TXTask (int argc, lvar_t *argv);
void TXTprocess (int, char *);
void TXTupdate (void);
void TXTtoggle (int, void *);
#endif /* _TXTVIEW_H */

#ifdef __cplusplus
}
#endif
