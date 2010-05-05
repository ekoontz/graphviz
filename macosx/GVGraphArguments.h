/* $Id: GVGraphArguments.h,v 1.1 2008/02/11 12:34:07 glenlow Exp $ $Revision: 1.1 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2008 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#import <Foundation/Foundation.h>

@class GVGraph;

@interface GVGraphArguments : NSMutableDictionary {
	GVGraph *_graph;
	NSMutableDictionary *_arguments;
}

- (id)initWithGraph:(GVGraph *)graph;

/* dictionary primitive methods */
- (NSUInteger)count;
- (NSEnumerator *)keyEnumerator;
- (id)objectForKey:(id)aKey;

/* mutable dictionary primitive methods */
- (void)setObject:(id)anObject forKey:(id)aKey;
- (void)removeObjectForKey:(id)aKey;

- (void)dealloc;

@end
