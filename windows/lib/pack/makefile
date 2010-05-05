:PACKAGE: graphviz

.SOURCE.h : ../cdt ../graph ../common ../pathplan ../gvc

pack $(LIBVERSION) :LIBRARY: pack.3 pack.c ccomps.c \
    -lcommon

$(INCLUDEDIR) :INSTALLDIR: pack.h

:: pack.pdf
