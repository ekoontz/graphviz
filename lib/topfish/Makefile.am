# $Id: Makefile.am,v 1.3 2008/04/29 21:59:17 erg Exp $ $Revision: 1.3 $
# ## Process this file with automake to produce Makefile.in
#
AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/lib/neatogen \
	-I$(top_srcdir)/lib/common

if WITH_SMYRNA
noinst_HEADERS = hierarchy.h
noinst_LTLIBRARIES = libtopfish_C.la
endif

libtopfish_C_la_SOURCES = hierarchy.c rescale_layout.c
