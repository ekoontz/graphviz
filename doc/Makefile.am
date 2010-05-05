# $Id: Makefile.am,v 1.8 2008/02/11 18:29:13 ellson Exp $ $Revision: 1.8 $
## Process this file with automake to produce Makefile.in

# SUBDIRS = dot neato lefty dotty info
SUBDIRS = info

pdf = dotguide.pdf dottyguide.pdf leftyguide.pdf neatoguide.pdf
html = build.html FAQ.html index.html winbuild.html pspdf.png
txt = Dot.ref latex_suggestions.txt fontfaq.txt

pdfdir = $(pkgdatadir)/doc/pdf
htmldir = $(pkgdatadir)/doc/html
txtdir = $(pkgdatadir)/doc

pdf_DATA = $(pdf)
html_DATA = $(html)
txt_DATA = $(txt)

EXTRA_DIST = $(txt) $(pdf) $(html) schema/*.xml schema/*.xslt
