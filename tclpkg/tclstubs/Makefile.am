# $Id: Makefile.am,v 1.4 2006/05/26 14:49:11 ellson Exp $ $Revision: 1.4 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = @TCL_CFLAGS@ @TCL_INCLUDES@

LIBS = @TCL_STUB_LIB_SPEC@

if WITH_TCL
noinst_LTLIBRARIES = libtclstubs_C.la
endif
noinst_HEADERS = tclInt.h

# tclStubLib.c is a dummy file just to fool automake
libtclstubs_C_la_SOURCES = tclStubLib.c

EXTRA_DIST = Makefile.old
