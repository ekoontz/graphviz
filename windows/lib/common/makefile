:PACKAGE: graphviz

.SOURCE.h :  ../cdt ../graph ../gvc ../pathplan ../fdpgen

common $(LIBVERSION) :LIBRARY: args.c arrows.c colxlate.c diagen.c emit.c \
	fontmetrics.c geom.c globals.c hpglgen.c htmllex.c htmlparse.c \
	htmltable.c input.c labels.c memory.c mifgen.c mpgen.c ns.c output.c \
	picgen.c pointset.c postproc.c psusershape.c routespl.c shapes.c \
	splines.c strcasecmp.c strncasecmp.c timing.c utils.c vtxgen.c \
	-lgvc -lgd -llibexpat -llibexpatw

htmlparse.h : .TERMINAL

$(INCLUDEDIR) :INSTALLDIR: types.h geom.h color.h usershape.h textpara.h

