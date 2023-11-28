@echo off

set MATLAB=D:\ProgrammiHD\Matlab 2023b


call  "\\MSI\D$\ProgrammiHD\Matlab 2023b\bin\win64\checkMATLABRootForDriveMap.exe" "\\MSI\D$\ProgrammiHD\Matlab 2023b"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

chcp 1252

if "%1"=="" ("D:\ProgrammiHD\Matlab 2023b\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f primitives_rtw.mk all) else ("D:\ProgrammiHD\Matlab 2023b\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f primitives_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1