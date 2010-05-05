/* $Id: gvplugin_devil.c,v 1.2 2007/08/29 19:39:49 ellson Exp $ $Revision: 1.2 $ */
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

extern gvplugin_installed_t gvdevice_devil_types;

static gvplugin_api_t apis[] = {
    {API_device, &gvdevice_devil_types},
    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_devil_LTX_library = { "devil", apis };
