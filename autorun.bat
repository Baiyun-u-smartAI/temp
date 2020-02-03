@ECHO OFF
REM 第一行的作用是取消显示输出
REM 检查权限，不输出结果，也不输出错误
NET SESSION 1>NUL 2>NUL
REM 如果没有权限，跳至提升权限段
IF %ERRORLEVEL% NEQ 0 GOTO ELEVATE
REM 跳至实际需要执行的批处理段
GOTO ADMINTASKS

REM 提升权限段
:ELEVATE
REM 记录当前路径
CD /d %~dp0
REM 使用 javascript 用管理员权限重新执行该批处理文件
MSHTA "javascript: var shell = new ActiveXObject('shell.application'); shell.ShellExecute('%~nx0', '', '', 'runas', 1);close();"
REM 退出
EXIT

REM 实际需要执行的批处理段
:ADMINTASKS
REM 在下面加入需要管理员权限的定制内容
REM 获取分区根目录
SET DISKROOT=%~dp0
SET DISKROOT=%DISKROOT:~0,3%


REM 添加系统环境变量 新键NEW_PATH1 键值%~dp0%FOLDERNAME%
REM SET FOLDERNAME=test
REM CD %~dp0%FOLDERNAME%/..
REM SETX /M NEW_PATH1 %~dp0%FOLDERNAME%


REM SET FOLDERNAME=erw
REM RD /S /Q %~dp0%FOLDERNAME%
:OPENCV_INSTALL
REM SET OPENCV_FOLDER=opencv*
FOR /f "delims=" %%a IN ('DIR /s /b /AD opencv4*') DO SET "OPENCV_FOLDER=%%a"
ECHO %OPENCV_FOLDER%
IF EXIST "%OPENCV_FOLDER%\build\bin\libopencv_core*.dll" (
  ECHO OpenCV目录已经找到，路径：
  ECHO %OPENCV_FOLDER%\build\install
  SETX /M OPENCV4_PATH "%OPENCV_FOLDER%\build"
REM ECHO %OPENCV_FOLDER%\build\bin;%PATH%
REM 设置PATH环境变量
) ELSE ECHO OpenCV安装失败，未找到OpenCV目录

 
:GCC_INSTALL
SET GCC_FOLDER=mingw64
ECHO %~dp0%GCC_FOLDER%\bin\g++.exe
IF EXIST "%~dp0%GCC_FOLDER%\bin\g++.exe" (
  ECHO C++目录已经找到，路径：
  SET GCC_PATH=%~dp0%GCC_FOLDER%\bin
REM 设置PATH环境变量
) ELSE ECHO MingW64 C++安装失败，未找到MingW64 C++目录

PAUSE

