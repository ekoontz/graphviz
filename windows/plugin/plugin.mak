# Microsoft Developer Studio Generated NMAKE File, Based on plugin.dsp
!IF "$(CFG)" == ""
CFG=plugin - Win32 Debug
!MESSAGE No configuration specified. Defaulting to plugin - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "plugin - Win32 Release" && "$(CFG)" != "plugin - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "plugin.mak" CFG="plugin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "plugin - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "plugin - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "plugin - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\plugin.lib"


CLEAN :
	-@erase "$(INTDIR)\gvdevice_gd.obj"
	-@erase "$(INTDIR)\gvlayout_dot_layout.obj"
	-@erase "$(INTDIR)\gvlayout_neato_layout.obj"
	-@erase "$(INTDIR)\gvloadimage_core.obj"
	-@erase "$(INTDIR)\gvloadimage_gd.obj"
	-@erase "$(INTDIR)\gvloadimage_pango.obj"
	-@erase "$(INTDIR)\gvplugin_core.obj"
	-@erase "$(INTDIR)\gvplugin_dot_layout.obj"
	-@erase "$(INTDIR)\gvplugin_gd.obj"
	-@erase "$(INTDIR)\gvplugin_neato_layout.obj"
	-@erase "$(INTDIR)\gvplugin_pango.obj"
	-@erase "$(INTDIR)\gvrender_core.obj"
	-@erase "$(INTDIR)\gvrender_core_dot.obj"
	-@erase "$(INTDIR)\gvrender_core_fig.obj"
	-@erase "$(INTDIR)\gvrender_core_map.obj"
	-@erase "$(INTDIR)\gvrender_core_ps.obj"
	-@erase "$(INTDIR)\gvrender_core_svg.obj"
	-@erase "$(INTDIR)\gvrender_core_vml.obj"
	-@erase "$(INTDIR)\gvrender_gd.obj"
	-@erase "$(INTDIR)\gvrender_gd_vrml.obj"
	-@erase "$(INTDIR)\gvrender_pango.obj"
	-@erase "$(INTDIR)\gvtextlayout_gd.obj"
	-@erase "$(INTDIR)\gvtextlayout_pango.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\plugin.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "." /I ".." /I "..\lib\gvc" /I "..\lib\common" /I "..\lib\cdt" /I "..\lib\graph" /I "..\lib\pathplan" /I "..\third-party\include" /I "..\lib\gd" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /Fp"$(INTDIR)\plugin.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\plugin.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\plugin.lib" 
LIB32_OBJS= \
	"$(INTDIR)\gvlayout_dot_layout.obj" \
	"$(INTDIR)\gvlayout_neato_layout.obj" \
	"$(INTDIR)\gvloadimage_core.obj" \
	"$(INTDIR)\gvloadimage_gd.obj" \
	"$(INTDIR)\gvloadimage_pango.obj" \
	"$(INTDIR)\gvplugin_core.obj" \
	"$(INTDIR)\gvplugin_dot_layout.obj" \
	"$(INTDIR)\gvplugin_gd.obj" \
	"$(INTDIR)\gvplugin_neato_layout.obj" \
	"$(INTDIR)\gvplugin_pango.obj" \
	"$(INTDIR)\gvrender_core.obj" \
	"$(INTDIR)\gvrender_core_dot.obj" \
	"$(INTDIR)\gvrender_core_fig.obj" \
	"$(INTDIR)\gvrender_core_map.obj" \
	"$(INTDIR)\gvrender_core_ps.obj" \
	"$(INTDIR)\gvrender_core_svg.obj" \
	"$(INTDIR)\gvrender_core_vml.obj" \
	"$(INTDIR)\gvrender_gd.obj" \
	"$(INTDIR)\gvrender_gd_vrml.obj" \
	"$(INTDIR)\gvrender_pango.obj" \
	"$(INTDIR)\gvtextlayout_gd.obj" \
	"$(INTDIR)\gvtextlayout_pango.obj" \
	"$(INTDIR)\gvdevice_gd.obj"

"$(OUTDIR)\plugin.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\plugin.lib"
   copy .\Release\plugin.lib ..\lib\lib\Release
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ELSEIF  "$(CFG)" == "plugin - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\plugin.lib"


CLEAN :
	-@erase "$(INTDIR)\gvdevice_gd.obj"
	-@erase "$(INTDIR)\gvlayout_dot_layout.obj"
	-@erase "$(INTDIR)\gvlayout_neato_layout.obj"
	-@erase "$(INTDIR)\gvloadimage_core.obj"
	-@erase "$(INTDIR)\gvloadimage_gd.obj"
	-@erase "$(INTDIR)\gvloadimage_pango.obj"
	-@erase "$(INTDIR)\gvplugin_core.obj"
	-@erase "$(INTDIR)\gvplugin_dot_layout.obj"
	-@erase "$(INTDIR)\gvplugin_gd.obj"
	-@erase "$(INTDIR)\gvplugin_neato_layout.obj"
	-@erase "$(INTDIR)\gvplugin_pango.obj"
	-@erase "$(INTDIR)\gvrender_core.obj"
	-@erase "$(INTDIR)\gvrender_core_dot.obj"
	-@erase "$(INTDIR)\gvrender_core_fig.obj"
	-@erase "$(INTDIR)\gvrender_core_map.obj"
	-@erase "$(INTDIR)\gvrender_core_ps.obj"
	-@erase "$(INTDIR)\gvrender_core_svg.obj"
	-@erase "$(INTDIR)\gvrender_core_vml.obj"
	-@erase "$(INTDIR)\gvrender_gd.obj"
	-@erase "$(INTDIR)\gvrender_gd_vrml.obj"
	-@erase "$(INTDIR)\gvrender_pango.obj"
	-@erase "$(INTDIR)\gvtextlayout_gd.obj"
	-@erase "$(INTDIR)\gvtextlayout_pango.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\plugin.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "..\lib\gvc" /I "..\lib\common" /I "..\lib\cdt" /I "..\lib\graph" /I "..\lib\pathplan" /I "..\third-party\include" /I "..\lib\gd" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /Fp"$(INTDIR)\plugin.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\plugin.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\plugin.lib" 
LIB32_OBJS= \
	"$(INTDIR)\gvlayout_dot_layout.obj" \
	"$(INTDIR)\gvlayout_neato_layout.obj" \
	"$(INTDIR)\gvloadimage_core.obj" \
	"$(INTDIR)\gvloadimage_gd.obj" \
	"$(INTDIR)\gvloadimage_pango.obj" \
	"$(INTDIR)\gvplugin_core.obj" \
	"$(INTDIR)\gvplugin_dot_layout.obj" \
	"$(INTDIR)\gvplugin_gd.obj" \
	"$(INTDIR)\gvplugin_neato_layout.obj" \
	"$(INTDIR)\gvplugin_pango.obj" \
	"$(INTDIR)\gvrender_core.obj" \
	"$(INTDIR)\gvrender_core_dot.obj" \
	"$(INTDIR)\gvrender_core_fig.obj" \
	"$(INTDIR)\gvrender_core_map.obj" \
	"$(INTDIR)\gvrender_core_ps.obj" \
	"$(INTDIR)\gvrender_core_svg.obj" \
	"$(INTDIR)\gvrender_core_vml.obj" \
	"$(INTDIR)\gvrender_gd.obj" \
	"$(INTDIR)\gvrender_gd_vrml.obj" \
	"$(INTDIR)\gvrender_pango.obj" \
	"$(INTDIR)\gvtextlayout_gd.obj" \
	"$(INTDIR)\gvtextlayout_pango.obj" \
	"$(INTDIR)\gvdevice_gd.obj"

"$(OUTDIR)\plugin.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\plugin.lib"
   copy .\Debug\plugin.lib ..\lib\lib\Debug
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("plugin.dep")
!INCLUDE "plugin.dep"
!ELSE 
!MESSAGE Warning: cannot find "plugin.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "plugin - Win32 Release" || "$(CFG)" == "plugin - Win32 Debug"
SOURCE=.\gd\gvdevice_gd.c

"$(INTDIR)\gvdevice_gd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\dot_layout\gvlayout_dot_layout.c

"$(INTDIR)\gvlayout_dot_layout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\neato_layout\gvlayout_neato_layout.c

"$(INTDIR)\gvlayout_neato_layout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvloadimage_core.c

"$(INTDIR)\gvloadimage_core.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\gd\gvloadimage_gd.c

"$(INTDIR)\gvloadimage_gd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\pango\gvloadimage_pango.c

"$(INTDIR)\gvloadimage_pango.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvplugin_core.c

"$(INTDIR)\gvplugin_core.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\dot_layout\gvplugin_dot_layout.c

"$(INTDIR)\gvplugin_dot_layout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\gd\gvplugin_gd.c

"$(INTDIR)\gvplugin_gd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\neato_layout\gvplugin_neato_layout.c

"$(INTDIR)\gvplugin_neato_layout.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\pango\gvplugin_pango.c

"$(INTDIR)\gvplugin_pango.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core.c

"$(INTDIR)\gvrender_core.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_dot.c

"$(INTDIR)\gvrender_core_dot.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_fig.c

"$(INTDIR)\gvrender_core_fig.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_map.c

"$(INTDIR)\gvrender_core_map.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_ps.c

"$(INTDIR)\gvrender_core_ps.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_svg.c

"$(INTDIR)\gvrender_core_svg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\core\gvrender_core_vml.c

"$(INTDIR)\gvrender_core_vml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\gd\gvrender_gd.c

"$(INTDIR)\gvrender_gd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\gd\gvrender_gd_vrml.c

"$(INTDIR)\gvrender_gd_vrml.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\pango\gvrender_pango.c

"$(INTDIR)\gvrender_pango.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\gd\gvtextlayout_gd.c

"$(INTDIR)\gvtextlayout_gd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\pango\gvtextlayout_pango.c

"$(INTDIR)\gvtextlayout_pango.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

