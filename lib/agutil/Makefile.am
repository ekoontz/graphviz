# $Id: Makefile.am,v 1.3 2006/05/26 14:49:09 ellson Exp $ $Revision: 1.3 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
        -I$(top_srcdir) \
        -I$(top_srcdir)/lib/agraph \
        -I$(top_srcdir)/lib/cdt

noinst_HEADERS = agutil.h
noinst_LTLIBRARIES = libagutil_C.la

libagutil_C_la_SOURCES = dynattr.c nodeq.c agutil.h
