# Microsoft Developer Studio Generated NMAKE File, Based on vpsc.dsp
!IF "$(CFG)" == ""
CFG=vpsc - Win32 Debug
!MESSAGE No configuration specified. Defaulting to vpsc - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "vpsc - Win32 Release" && "$(CFG)" != "vpsc - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "vpsc.mak" CFG="vpsc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "vpsc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "vpsc - Win32 Debug" (based on "Win32 (x86) Static Library")
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

!IF  "$(CFG)" == "vpsc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\vpsc.lib"


CLEAN :
	-@erase "$(INTDIR)\block.obj"
	-@erase "$(INTDIR)\blocks.obj"
	-@erase "$(INTDIR)\constraint.obj"
	-@erase "$(INTDIR)\csolve_VPSC.obj"
	-@erase "$(INTDIR)\generate-constraints.obj"
	-@erase "$(INTDIR)\PairingHeap.obj"
	-@erase "$(INTDIR)\remove_rectangle_overlap.obj"
	-@erase "$(INTDIR)\solve_VPSC.obj"
	-@erase "$(INTDIR)\variable.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\vpsc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Fp"$(INTDIR)\vpsc.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vpsc.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\vpsc.lib" 
LIB32_OBJS= \
	"$(INTDIR)\block.obj" \
	"$(INTDIR)\blocks.obj" \
	"$(INTDIR)\constraint.obj" \
	"$(INTDIR)\csolve_VPSC.obj" \
	"$(INTDIR)\generate-constraints.obj" \
	"$(INTDIR)\remove_rectangle_overlap.obj" \
	"$(INTDIR)\solve_VPSC.obj" \
	"$(INTDIR)\variable.obj" \
	"$(INTDIR)\PairingHeap.obj"

"$(OUTDIR)\vpsc.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\vpsc.lib"
   copy .\Release\vpsc.lib ..\lib\Release
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ELSEIF  "$(CFG)" == "vpsc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\vpsc.lib"


CLEAN :
	-@erase "$(INTDIR)\block.obj"
	-@erase "$(INTDIR)\blocks.obj"
	-@erase "$(INTDIR)\constraint.obj"
	-@erase "$(INTDIR)\csolve_VPSC.obj"
	-@erase "$(INTDIR)\generate-constraints.obj"
	-@erase "$(INTDIR)\PairingHeap.obj"
	-@erase "$(INTDIR)\remove_rectangle_overlap.obj"
	-@erase "$(INTDIR)\solve_VPSC.obj"
	-@erase "$(INTDIR)\variable.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\vpsc.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Fp"$(INTDIR)\vpsc.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ  /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\vpsc.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\vpsc.lib" 
LIB32_OBJS= \
	"$(INTDIR)\block.obj" \
	"$(INTDIR)\blocks.obj" \
	"$(INTDIR)\constraint.obj" \
	"$(INTDIR)\csolve_VPSC.obj" \
	"$(INTDIR)\generate-constraints.obj" \
	"$(INTDIR)\remove_rectangle_overlap.obj" \
	"$(INTDIR)\solve_VPSC.obj" \
	"$(INTDIR)\variable.obj" \
	"$(INTDIR)\PairingHeap.obj"

"$(OUTDIR)\vpsc.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

SOURCE="$(InputPath)"
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\vpsc.lib"
   copy .\Debug\vpsc.lib ..\lib\Debug
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
!IF EXISTS("vpsc.dep")
!INCLUDE "vpsc.dep"
!ELSE 
!MESSAGE Warning: cannot find "vpsc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "vpsc - Win32 Release" || "$(CFG)" == "vpsc - Win32 Debug"
SOURCE=.\block.cpp

"$(INTDIR)\block.obj" : $(SOURCE) "$(INTDIR)" ".\pairingheap\PairingHeap.cpp"


SOURCE=.\blocks.cpp

"$(INTDIR)\blocks.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\constraint.cpp

"$(INTDIR)\constraint.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\csolve_VPSC.cpp

"$(INTDIR)\csolve_VPSC.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=".\generate-constraints.cpp"

"$(INTDIR)\generate-constraints.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pairingheap\PairingHeap.cpp

"$(INTDIR)\PairingHeap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\remove_rectangle_overlap.cpp

"$(INTDIR)\remove_rectangle_overlap.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\solve_VPSC.cpp

"$(INTDIR)\solve_VPSC.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\variable.cpp

"$(INTDIR)\variable.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

