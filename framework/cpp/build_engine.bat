@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /std:c++17 /EHsc /O2 /Fe:graphite_engine.exe graphite_engine.cpp

