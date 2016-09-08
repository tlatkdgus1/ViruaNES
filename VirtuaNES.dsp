# Microsoft Developer Studio Project File - Name="VirtuaNES" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=VirtuaNES - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "VirtuaNES.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "VirtuaNES.mak" CFG="VirtuaNES - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "VirtuaNES - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "VirtuaNES - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE "VirtuaNES - Win32 Profile" ("Win32 (x86) Application" 用)
!MESSAGE "VirtuaNES - Win32 Release_Debugout" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /map /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "VirtuaNES___Win32_Profile"
# PROP BASE Intermediate_Dir "VirtuaNES___Win32_Profile"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "Profile"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /Z7 /O2 /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /profile /map:"VirtuaNES.map" /debug /machine:I386

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "VirtuaNES___Win32_Release_Debugout"
# PROP BASE Intermediate_Dir "VirtuaNES___Win32_Release_Debugout"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "Release_Debugout"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_DEBUGOUT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "NES" /I "NES\Mapper" /I "NES\ApuEx" /I "NES\PadEx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_DEBUGOUT" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib comctl32.lib imm32.lib dinput.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /debug

!ENDIF 

# Begin Target

# Name "VirtuaNES - Win32 Release"
# Name "VirtuaNES - Win32 Debug"
# Name "VirtuaNES - Win32 Profile"
# Name "VirtuaNES - Win32 Release_Debugout"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AboutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\App.cpp
# End Source File
# Begin Source File

SOURCE=.\CheatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Com.cpp
# End Source File
# Begin Source File

SOURCE=.\Config.cpp
# End Source File
# Begin Source File

SOURCE=.\ControllerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Crclib.cpp
# End Source File
# Begin Source File

SOURCE=.\DebugOut.cpp
# End Source File
# Begin Source File

SOURCE=.\DirectDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\DirectInput.cpp
# End Source File
# Begin Source File

SOURCE=.\DirectSound.cpp
# End Source File
# Begin Source File

SOURCE=.\EmulatorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmuThread.cpp
# End Source File
# Begin Source File

SOURCE=.\FolderDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GraphicsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LanguageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LauncherDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\MMTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\MovieDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MovieInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NetPlay.cpp
# End Source File
# Begin Source File

SOURCE=.\NetPlayDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Pathlib.cpp
# End Source File
# Begin Source File

SOURCE=.\Plugin.cpp
# End Source File
# Begin Source File

SOURCE=.\Recent.cpp
# End Source File
# Begin Source File

SOURCE=.\Registry.cpp
# End Source File
# Begin Source File

SOURCE=.\RomInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ShortcutDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SoundDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\VirtuaNES.rc
# End Source File
# Begin Source File

SOURCE=.\WaveRec.cpp
# End Source File
# Begin Source File

SOURCE=.\WinMain.cpp
# End Source File
# Begin Source File

SOURCE=.\Wnd.cpp
# End Source File
# Begin Source File

SOURCE=.\WndHook.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AboutDlg.h
# End Source File
# Begin Source File

SOURCE=.\App.h
# End Source File
# Begin Source File

SOURCE=.\CheatDlg.h
# End Source File
# Begin Source File

SOURCE=.\Com.h
# End Source File
# Begin Source File

SOURCE=.\Config.h
# End Source File
# Begin Source File

SOURCE=.\ControllerDlg.h
# End Source File
# Begin Source File

SOURCE=.\Crclib.h
# End Source File
# Begin Source File

SOURCE=.\DebugOut.h
# End Source File
# Begin Source File

SOURCE=.\DirectDraw.h
# End Source File
# Begin Source File

SOURCE=.\DirectInput.h
# End Source File
# Begin Source File

SOURCE=.\DirectSound.h
# End Source File
# Begin Source File

SOURCE=.\EmulatorDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmuThread.h
# End Source File
# Begin Source File

SOURCE=.\FolderDlg.h
# End Source File
# Begin Source File

SOURCE=.\GraphicsDlg.h
# End Source File
# Begin Source File

SOURCE=.\LanguageDlg.h
# End Source File
# Begin Source File

SOURCE=.\LauncherDlg.h
# End Source File
# Begin Source File

SOURCE=.\lzAscii.h
# End Source File
# Begin Source File

SOURCE=.\lzSight.h
# End Source File
# Begin Source File

SOURCE=.\lzTVlayer.h
# End Source File
# Begin Source File

SOURCE=.\Macro.h
# End Source File
# Begin Source File

SOURCE=.\MainFrame.h
# End Source File
# Begin Source File

SOURCE=.\MMTimer.h
# End Source File
# Begin Source File

SOURCE=.\MovieDlg.h
# End Source File
# Begin Source File

SOURCE=.\MovieInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\NetPlay.h
# End Source File
# Begin Source File

SOURCE=.\NetPlayDlg.h
# End Source File
# Begin Source File

SOURCE=.\Pathlib.h
# End Source File
# Begin Source File

SOURCE=.\Plugin.h
# End Source File
# Begin Source File

SOURCE=.\Recent.h
# End Source File
# Begin Source File

SOURCE=.\Registry.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\RomInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\ShortcutDlg.h
# End Source File
# Begin Source File

SOURCE=.\SoundDlg.h
# End Source File
# Begin Source File

SOURCE=.\Typedef.h
# End Source File
# Begin Source File

SOURCE=.\VirtuaNESres.h
# End Source File
# Begin Source File

SOURCE=.\WaveRec.h
# End Source File
# Begin Source File

SOURCE=.\Wnd.h
# End Source File
# Begin Source File

SOURCE=.\WndHook.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CheatImageList.bmp
# End Source File
# Begin Source File

SOURCE=.\VirtuaNES.ico
# End Source File
# End Group
# Begin Group "NES"

# PROP Default_Filter ""
# Begin Group "Mapper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\NES\Mapper\Mapper.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper.h
# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper000.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper000.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper001.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper001.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper002.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper002.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper003.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper003.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper004.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper004.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper005.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper005.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper006.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper006.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper007.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper007.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper008.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper008.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper009.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper009.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper010.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper010.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper011.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper011.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper013.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper013.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper015.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper015.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper016.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper016.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper017.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper017.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper018.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper018.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper019.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper019.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper021.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper021.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper022.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper022.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper023.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper023.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper024.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper024.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper025.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper025.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper026.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper026.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper032.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper032.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper033.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper033.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper034.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper034.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper040.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper040.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper041.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper041.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper042.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper042.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper043.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper043.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper048.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper048.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper064.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper064.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper065.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper065.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper066.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper066.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper067.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper067.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper068.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper068.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper069.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper069.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper070.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper070.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper071.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper071.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper072.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper072.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper073.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper073.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper075.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper075.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper076.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper076.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper077.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper077.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper078.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper078.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper079.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper079.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper080.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper080.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper082.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper082.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper083.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper083.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper085.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper085.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper086.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper086.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper087.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper087.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper088.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper088.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper089.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper089.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper092.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper092.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper093.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper093.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper094.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper094.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper095.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper095.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper096.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper096.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper097.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper097.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper100.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper100.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper101.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper101.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper107.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper107.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper118.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper118.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper119.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper119.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper122.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper122.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper180.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper180.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper185.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper185.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper188.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper188.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper189.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\Mapper189.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\MapperFDS.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\MapperFDS.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\MapperNSF.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\Mapper\MapperNSF.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "ApuEx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\NES\ApuEX\2413tone.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_FDS.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_FDS.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_FME7.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_FME7.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_INTERFACE.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_INTERNAL.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_INTERNAL.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_MMC5.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_MMC5.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_N106.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_N106.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_VRC6.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_VRC6.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_VRC7.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\APU_VRC7.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\emu2413.c
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\emu2413.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\FDSplugin.h
# End Source File
# Begin Source File

SOURCE=.\NES\ApuEX\vrc7tone.h
# End Source File
# End Group
# Begin Group "PadEx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_CrazyClimber.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_CrazyClimber.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_HyperShot.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_HyperShot.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Keyboard.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Keyboard.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Paddle.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Paddle.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_SpaceShadowGun.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_SpaceShadowGun.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Toprider.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Toprider.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Zapper.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\PadEX\EXPAD_Zapper.h

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\NES\APU.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\APU.h
# End Source File
# Begin Source File

SOURCE=.\NES\Cheat.h
# End Source File
# Begin Source File

SOURCE=.\NES\Cpu.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\CPU.h
# End Source File
# Begin Source File

SOURCE=.\NES\MMU.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\MMU.h
# End Source File
# Begin Source File

SOURCE=.\NES\Nes.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\Nes.h
# End Source File
# Begin Source File

SOURCE=.\NES\PAD.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\PAD.h
# End Source File
# Begin Source File

SOURCE=.\NES\PPU.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\PPU.h
# End Source File
# Begin Source File

SOURCE=.\NES\ROM.cpp
# End Source File
# Begin Source File

SOURCE=.\NES\ROM.h
# End Source File
# Begin Source File

SOURCE=.\NES\ROM_Patch.cpp

!IF  "$(CFG)" == "VirtuaNES - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Profile"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "VirtuaNES - Win32 Release_Debugout"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\NES\State.h
# End Source File
# End Group
# End Target
# End Project
