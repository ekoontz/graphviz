# $Id: Makefile.am,v 1.7 2007/03/12 22:48:19 erg Exp $ $Revision: 1.7 $
## Process this file with automake to produce Makefile.in

man = dotty.1
pdf = dotty.pdf

leftydir = $(pkgdatadir)/lefty
pdfdir = $(pkgdatadir)/doc/pdf

man_MANS = $(man)
pdf_DATA = $(pdf)
if WITH_WIN32
bin_PROGRAMS = dotty
else
bin_SCRIPTS = dotty
endif
lefty_DATA = dotty.lefty dotty_draw.lefty dotty_edit.lefty \
        dotty_layout.lefty dotty_ui.lefty

if WITH_WIN32
dotty_SOURCES = mswin32/dotty.c
dotty_LDADD = -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32
else
dotty: $(top_srcdir)/cmd/dotty/dotty.sh
	cp $(top_srcdir)/cmd/dotty/dotty.sh dotty
	chmod +x dotty
endif

.1.pdf:
	-groff -Tps -man $< | ps2pdf - - >$@

EXTRA_DIST = $(lefty_DATA) $(man) $(pdf) \
	dotty.bsh dotty.ksh dotty.sh \
	Makefile.old notes mswin32

DISTCLEANFILES = $(pdf) dotty
