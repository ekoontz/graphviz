/* $Id: GVAttributeSchema.h,v 1.1 2008/02/11 12:34:07 glenlow Exp $ $Revision: 1.1 $ */
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


@interface GVAttributeSchema : NSObject {
	NSXMLElement *_element;
}

@property(readonly) NSString *name;
@property(readonly) NSCell *cell;
@property(readonly) NSString *documentation;

+ (NSArray*)attributeSchemasWithComponent:(NSString *)component;
- (id)initWithXMLElement:(NSXMLElement *)element;

- (void)dealloc;
@end
