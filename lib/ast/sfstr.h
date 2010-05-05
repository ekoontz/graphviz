/* $Id: sfstr.h,v 1.1.1.1 2004/12/23 04:04:21 ellson Exp $ $Revision: 1.1.1.1 $ */
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
 * macro interface for sfio write strings
 *
 * NOTE: see <stak.h> for an alternative interface
 *	 read operations require sfseek()
 */

#ifndef _SFSTR_H
#define _SFSTR_H

#include <sfio.h>

#define sfstropen()	sfnew((Sfio_t*)0,(char*)0,-1,-1,SF_WRITE|SF_STRING)
#define sfstrnew(m)	sfnew((Sfio_t*)0,(char*)0,-1,-1,(m)|SF_STRING)
#define sfstrclose(f)	sfclose(f)

#define sfstrtell(f)	((f)->next - (f)->data)
#define sfstrrel(f,p)	((p) == (0) ? (char*)(f)->next : \
			 ((f)->next += (p), \
			  ((f)->next >= (f)->data && (f)->next  <= (f)->endb) ? \
				(char*)(f)->next : ((f)->next -= (p), (char*)0) ) )

#define sfstrset(f,p)	(((p) >= 0 && (p) <= (f)->size) ? \
				(char*)((f)->next = (f)->data+(p)) : (char*)0 )

#define sfstrbase(f)	((char*)(f)->data)
#define sfstrsize(f)	((f)->size)

#define sfstrrsrv(f,n)	(sfreserve(f,(long)(n),1)?(sfwrite(f,(char*)(f)->next,0),(char*)(f)->next):(char*)0)

#define sfstruse(f)	(sfputc(f,0), (char*)((f)->next = (f)->data) )

#if _BLD_ast && defined(__EXPORT__)
#define extern		__EXPORT__
#endif

    extern int sfstrtmp(Sfio_t *, int, void *, size_t);

#undef	extern

#endif

#ifdef __cplusplus
}
#endif
