@ECHO OFF
REM ��һ�е�������ȡ����ʾ���
REM ���Ȩ�ޣ�����������Ҳ���������
NET SESSION 1>NUL 2>NUL
REM ���û��Ȩ�ޣ���������Ȩ�޶�
IF %ERRORLEVEL% NEQ 0 GOTO ELEVATE
REM ����ʵ����Ҫִ�е��������
GOTO ADMINTASKS

REM ����Ȩ�޶�
:ELEVATE
REM ��¼��ǰ·��
CD /d %~dp0
REM ʹ�� javascript �ù���ԱȨ������ִ�и��������ļ�
MSHTA "javascript: var shell = new ActiveXObject('shell.application'); shell.ShellExecute('%~nx0', '', '', 'runas', 1);close();"
REM �˳�
EXIT

REM ʵ����Ҫִ�е��������
:ADMINTASKS
REM �����������Ҫ����ԱȨ�޵Ķ�������
REM ��ȡ������Ŀ¼
SET DISKROOT=%~dp0
SET DISKROOT=%DISKROOT:~0,3%


REM ���ϵͳ�������� �¼�NEW_PATH1 ��ֵ%~dp0%FOLDERNAME%
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
  ECHO OpenCVĿ¼�Ѿ��ҵ���·����
  ECHO %OPENCV_FOLDER%\build\install
  SETX /M OPENCV4_PATH "%OPENCV_FOLDER%\build"
REM ECHO %OPENCV_FOLDER%\build\bin;%PATH%
REM ����PATH��������
) ELSE ECHO OpenCV��װʧ�ܣ�δ�ҵ�OpenCVĿ¼

 
:GCC_INSTALL
SET GCC_FOLDER=mingw64
ECHO %~dp0%GCC_FOLDER%\bin\g++.exe
IF EXIST "%~dp0%GCC_FOLDER%\bin\g++.exe" (
  ECHO C++Ŀ¼�Ѿ��ҵ���·����
  SET GCC_PATH=%~dp0%GCC_FOLDER%\bin
REM ����PATH��������
) ELSE ECHO MingW64 C++��װʧ�ܣ�δ�ҵ�MingW64 C++Ŀ¼

PAUSE

