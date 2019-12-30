cd opencv411\build\install\x64\mingw\bin
set My_PATH=%CD%
echo %PATH%
setx PATH_TEMP "%PATH%;%CD%" 
::reg add "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v "Path" /t REG_EXPAND_SZ /d "%PATH%" /f

pause