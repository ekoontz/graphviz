/* $Id: gvplugin_core.c,v 1.16 2008/04/25 20:06:20 ellson Exp $ $Revision: 1.16 $ */
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

extern gvplugin_installed_t gvdevice_dot_types;
extern gvplugin_installed_t gvdevice_fig_types;
extern gvplugin_installed_t gvdevice_map_types;
extern gvplugin_installed_t gvdevice_ps_types;
extern gvplugin_installed_t gvdevice_svg_types;
extern gvplugin_installed_t gvdevice_tk_types;
extern gvplugin_installed_t gvdevice_vml_types;

extern gvplugin_installed_t gvrender_dot_types;
extern gvplugin_installed_t gvrender_fig_types;
extern gvplugin_installed_t gvrender_map_types;
extern gvplugin_installed_t gvrender_ps_types;
extern gvplugin_installed_t gvrender_svg_types;
extern gvplugin_installed_t gvrender_tk_types;
extern gvplugin_installed_t gvrender_vml_types;

extern gvplugin_installed_t gvloadimage_core_types;

static gvplugin_api_t apis[] = {
    {API_device, &gvdevice_dot_types},
    {API_device, &gvdevice_fig_types},
    {API_device, &gvdevice_map_types},
    {API_device, &gvdevice_ps_types},
    {API_device, &gvdevice_svg_types},
    {API_device, &gvdevice_tk_types},
    {API_device, &gvdevice_vml_types},

    {API_render, &gvrender_dot_types},
    {API_render, &gvrender_fig_types},
    {API_render, &gvrender_map_types},
    {API_render, &gvrender_ps_types},
    {API_render, &gvrender_svg_types},
    {API_render, &gvrender_tk_types},
    {API_render, &gvrender_vml_types},

    {API_loadimage, &gvloadimage_core_types},

    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_core_LTX_library = { "core", apis };
