/* $Id: GVWindowController.h,v 1.6 2008/05/27 15:23:46 glenlow Exp $ $Revision: 1.6 $ */
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
#import <AppKit/AppKit.h>
#import <Quartz/Quartz.h>

@interface GVWindowController : NSWindowController <NSUserInterfaceValidations>
{
	IBOutlet PDFView *documentView;
}

- (id)init;
- (void)setDocument: (NSDocument *)document;
- (void)awakeFromNib;

- (void)graphDocumentDidChange:(NSNotification*)notification;
- (NSRect)windowWillUseStandardFrame:(NSWindow *)window defaultFrame:(NSRect)defaultFrame;

- (IBAction)actualSizeView:(id)sender;
- (IBAction)zoomInView:(id)sender;
- (IBAction)zoomOutView:(id)sender;
- (IBAction)zoomToFitView:(id)sender;

- (IBAction)printGraphDocument:(id)sender;

- (BOOL)validateUserInterfaceItem:(id <NSValidatedUserInterfaceItem>)anItem;

- (void)dealloc;
@end
