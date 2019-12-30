set My_PATH=%PATH_TEMP%
echo My_PATH
setx PATH "%My_PATH%" /m
setx PATH_TEMP ""
pause