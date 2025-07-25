@echo off
net session >nul 2>&1
if %errorlevel% neq 0 (
    powershell -Command "Start-Process '%~f0' -Verb runAs"
    exit /b
)

set CURRENT_PATH=%~dp0
set EXE_PATH=%CURRENT_PATH%intercept.exe
set SHORTCUT_NAME=InterceptKeyBlock
set STARTUP_PATH=%ProgramData%\Microsoft\Windows\Start Menu\Programs\Startup

powershell -command ^
"$s = (New-Object -ComObject WScript.Shell).CreateShortcut('%STARTUP_PATH%\%SHORTCUT_NAME%.lnk'); ^
 $s.TargetPath = '%EXE_PATH%'; ^
 $s.WorkingDirectory = '%CURRENT_PATH%'; ^
 $s.Save()"

echo Shortcut to Startup success.
pause