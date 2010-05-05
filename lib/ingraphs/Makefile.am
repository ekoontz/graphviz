# $Id: Makefile.am,v 1.5 2006/05/26 14:49:10 ellson Exp $ $Revision: 1.5 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
        -I$(top_srcdir) \
        -I$(top_srcdir)/lib/graph \
	-I$(top_srcdir)/lib/cdt 

noinst_HEADERS = ingraphs.h 
noinst_LTLIBRARIES = libingraphs_C.la

libingraphs_C_la_SOURCES = ingraphs.c

EXTRA_DIST = Makefile.old
