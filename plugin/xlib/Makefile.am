# $Id: Makefile.am,v 1.12 2008/05/21 20:37:40 ellson Exp $ $Revision: 1.12 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/graph \
	-I$(top_srcdir)/lib/cdt \
	$(PANGOCAIRO_CFLAGS)

if WITH_PANGOCAIRO
if WITH_X
noinst_LTLIBRARIES = libgvplugin_xlib_C.la
if WITH_WIN32
lib_LTLIBRARIES = libgvplugin_xlib.la
else
pkglib_LTLIBRARIES = libgvplugin_xlib.la
endif
endif
endif

libgvplugin_xlib_C_la_SOURCES = \
	gvplugin_xlib.c \
	gvdevice_xlib.c

libgvplugin_xlib_la_LDFLAGS = -version-info @GVPLUGIN_VERSION_INFO@
libgvplugin_xlib_la_SOURCES = $(libgvplugin_xlib_C_la_SOURCES)
libgvplugin_xlib_la_LIBADD = @PANGOCAIRO_LIBS@ @X_LIBS@ -lX11 @SOCKET_LIBS@ @MATH_LIBS@

if WITH_WIN32
libgvplugin_xlib_la_LDFLAGS += -no-undefined
endif

if WITH_DARWIN9
libgvplugin_xlib_la_LDFLAGS += -Wl,-exported_symbol,_gvplugin_xlib_LTX_library
endif
