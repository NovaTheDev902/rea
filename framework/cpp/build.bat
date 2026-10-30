@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /LD /O2 /Fe:graphite_core.dll graphite_core.c

