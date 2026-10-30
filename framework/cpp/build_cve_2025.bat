@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /LD /O2 /Fe:graphite_cve_2025.dll graphite_cve_2025.c

