/* $Id: macros.h,v 1.16 2006/12/07 22:49:35 erg Exp $ $Revision: 1.16 $ */
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

#ifndef GV_MACROS_H
#define GV_MACROS_H

#ifndef NOTUSED
#define NOTUSED(var) (void) var
#endif

#define isPinned(n)     (ND_pinned(n) == P_PIN)
#define hasPos(n)       (ND_pinned(n) > 0)
#define isFixed(n)      (ND_pinned(n) > P_SET)

#define SET_CLUST_NODE(n) (ND_clustnode(n) = TRUE)
#define IS_CLUST_NODE(n)  (ND_clustnode(n))
#define HAS_CLUST_EDGE(g) (GD_flags(g) & 1)
#define SET_CLUST_EDGE(g) (GD_flags(g) |= 1)
#define EDGE_TYPE(g) (GD_flags(g) & (7 << 1))

#define SET_RANKDIR(g,rd) ((g)->u.rankdir = (rd))

#ifndef streq
#define streq(a,b)		(*(a)==*(b)&&!strcmp(a,b))
#endif

#define XPAD(d) ((d).x += 4*GAP)
#define YPAD(d) ((d).y += 2*GAP)
#define PAD(d)  {XPAD(d); YPAD(d);}

#define OTHERDIR(dir) ((dir == CCW) ? CW : CCW)

#define NEXTSIDE(side, dir) ((dir == CCW) ? \
		((side & 0x8) ? BOTTOM : (side << 1)) : \
		((side & 0x1) ? LEFT : (side >> 1)))

#endif
