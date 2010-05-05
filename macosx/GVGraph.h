/* $Id: GVGraph.h,v 1.3 2008/05/26 06:09:46 glenlow Exp $ $Revision: 1.3 $ */
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

#include "gvc.h"

@class GVGraphArguments;
@class GVGraphDefaultAttributes;

@interface GVGraph : NSObject
{
	graph_t *_graph;
	BOOL _freeLastLayout;
	
	GVGraphArguments *_arguments;
	GVGraphDefaultAttributes *_graphAttributes;
	GVGraphDefaultAttributes *_defaultNodeAttributes;
	GVGraphDefaultAttributes *_defaultEdgeAttributes;
}

@property(readonly) graph_t *graph;
@property(readonly) GVGraphArguments *arguments;
@property(readonly) GVGraphDefaultAttributes *graphAttributes;
@property(readonly) GVGraphDefaultAttributes *defaultNodeAttributes;
@property(readonly) GVGraphDefaultAttributes *defaultEdgeAttributes;

+ (void)initialize;
+ (NSEnumerator *)devices;

- (id)initWithURL:(NSURL *)URL error:(NSError **)outError;

- (NSData *)renderWithFormat:(NSString *)format;
- (void)renderWithFormat:(NSString*)format toURL:(NSURL *)URL;
- (void)noteChanged:(BOOL)relayout;

- (BOOL)writeToURL:(NSURL *)URL error:(NSError **)outError;

- (void)dealloc;

@end
