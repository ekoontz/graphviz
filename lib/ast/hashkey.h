/* $Id: hashkey.h,v 1.1.1.1 2004/12/23 04:04:21 ellson Exp $ $Revision: 1.1.1.1 $ */
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

/*
 * Glenn Fowler
 * AT&T Research
 *
 * 1-6 char lower-case keyword -> long hash
 * digit args passed as HASHKEYN('2')
 */

#ifndef _HASHKEY_H
#define _HASHKEY_H

#define HASHKEYMAX			6
#define HASHKEYBIT			5
#define HASHKEYOFF			('a'-1)
#define HASHKEYPART(h,c)		(((h)<<HASHKEYBIT)+HASHKEY1(c))

#define HASHKEYN(n)			((n)-'0'+'z'+1)

#define HASHKEY1(c1)			((c1)-HASHKEYOFF)
#define HASHKEY2(c1,c2)			HASHKEYPART(HASHKEY1(c1),c2)
#define HASHKEY3(c1,c2,c3)		HASHKEYPART(HASHKEY2(c1,c2),c3)
#define HASHKEY4(c1,c2,c3,c4)		HASHKEYPART(HASHKEY3(c1,c2,c3),c4)
#define HASHKEY5(c1,c2,c3,c4,c5)	HASHKEYPART(HASHKEY4(c1,c2,c3,c4),c5)
#define HASHKEY6(c1,c2,c3,c4,c5,c6)	HASHKEYPART(HASHKEY5(c1,c2,c3,c4,c5),c6)

#define HASHNKEY1(n,c1)			HASHKEY2((n)+HASHKEYOFF,c1)
#define HASHNKEY2(n,c2,c1)		HASHKEY3((n)+HASHKEYOFF,c2,c1)
#define HASHNKEY3(n,c3,c2,c1)		HASHKEY4((n)+HASHKEYOFF,c3,c2,c1)
#define HASHNKEY4(n,c4,c3,c2,c1)	HASHKEY5((n)+'a',c4,c3,c2,c1)
#define HASHNKEY5(n,c5,c4,c3,c2,c1)	HASHKEY6((n)+'a',c5,c4,c3,c2,c1)

#if _BLD_ast && defined(__EXPORT__)
#define extern		__EXPORT__
#endif

    extern long strkey(const char *);

#undef	extern

#endif

#ifdef __cplusplus
}
#endif
