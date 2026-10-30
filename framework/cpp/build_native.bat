@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /c /O2 /EHsc graphite_core.cpp
if errorlevel 1 exit /b 1
echo COMPILE_OK