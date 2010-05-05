# $Id: Makefile.am,v 1.2 2006/04/07 18:50:38 ellson Exp $ $Revision: 1.2 $
## Process this file with automake to produce Makefile.in

EXAMPLES = boxes.dat dpd.dat funny.dat maze.dat nested.dat northo.dat \
	obs.dat other.dat paths.dat rotor.dat u.dat unknown.dat

pathplanexampledir = $(datadir)/@PACKAGE@/demo/pathplan_data

if WITH_TCL
pathplanexample_DATA = $(EXAMPLES)
endif

EXTRA_DIST = $(EXAMPLES)
