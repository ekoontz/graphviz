/* $Id: circpos.h,v 1.1.1.1 2004/12/23 04:04:29 ellson Exp $ $Revision: 1.1.1.1 $ */
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

#ifndef CIRCPOS_H
#define CIRCPOS_H

#include <render.h>
#include <circular.h>

    extern void circPos(Agraph_t * g, block_t * sn, circ_state *);

#endif

#ifdef __cplusplus
}
#endif
