/* $Id: gvplugin_ming.c,v 1.2 2007/08/29 19:44:01 ellson Exp $ $Revision: 1.2 $ */
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

extern gvplugin_installed_t gvrender_ming_types;
extern gvplugin_installed_t gvdevice_ming_types;

static gvplugin_api_t apis[] = {
    {API_device, &gvdevice_ming_types},
    {API_render, &gvrender_ming_types},
    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_ming_LTX_library = { "ming", apis };
