/* $Id: gvplugin_gtk.c,v 1.2 2006/06/28 02:49:58 ellson Exp $ $Revision: 1.2 $ */
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

#include "gvplugin.h"

extern gvplugin_installed_t gvdevice_types_gtk;

static gvplugin_api_t apis[] = {
    {API_device, &gvdevice_types_gtk},
    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_gtk_LTX_library = { "gtk", apis };
