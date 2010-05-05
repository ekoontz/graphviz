# Microsoft Developer Studio Project File - Name="plugin" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=plugin - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "plugin.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "plugin - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "." /I ".." /I "..\lib\gvc" /I "..\lib\common" /I "..\lib\cdt" /I "..\lib\graph" /I "..\lib\pathplan" /I "..\third-party\include" /I "..\lib\gd" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy .\Release\plugin.lib ..\lib\lib\Release
# End Special Build Tool

!ELSEIF  "$(CFG)" == "plugin - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "." /I ".." /I "..\lib\gvc" /I "..\lib\common" /I "..\lib\cdt" /I "..\lib\graph" /I "..\lib\pathplan" /I "..\third-party\include" /I "..\lib\gd" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy .\Debug\plugin.lib ..\lib\lib\Debug
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "plugin - Win32 Release"
# Name "plugin - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\gd\gvdevice_gd.c
# End Source File
# Begin Source File

SOURCE=.\dot_layout\gvlayout_dot_layout.c
# End Source File
# Begin Source File

SOURCE=.\neato_layout\gvlayout_neato_layout.c
# End Source File
# Begin Source File

SOURCE=.\core\gvloadimage_core.c
# End Source File
# Begin Source File

SOURCE=.\gd\gvloadimage_gd.c
# End Source File
# Begin Source File

SOURCE=.\pango\gvloadimage_pango.c
# End Source File
# Begin Source File

SOURCE=.\core\gvplugin_core.c
# End Source File
# Begin Source File

SOURCE=.\dot_layout\gvplugin_dot_layout.c
# End Source File
# Begin Source File

SOURCE=.\gd\gvplugin_gd.c
# End Source File
# Begin Source File

SOURCE=.\neato_layout\gvplugin_neato_layout.c
# End Source File
# Begin Source File

SOURCE=.\pango\gvplugin_pango.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_dot.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_fig.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_map.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_ps.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_svg.c
# End Source File
# Begin Source File

SOURCE=.\core\gvrender_core_vml.c
# End Source File
# Begin Source File

SOURCE=.\gd\gvrender_gd.c
# End Source File
# Begin Source File

SOURCE=.\gd\gvrender_gd_vrml.c
# End Source File
# Begin Source File

SOURCE=.\pango\gvrender_pango.c
# End Source File
# Begin Source File

SOURCE=.\gd\gvtextlayout_gd.c
# End Source File
# Begin Source File

SOURCE=.\pango\gvtextlayout_pango.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
