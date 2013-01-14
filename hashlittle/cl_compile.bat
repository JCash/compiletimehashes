echo off
rem call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat"

c:\Python27_64\python.exe c:\dropzone\tools\timeit.py 1 cl /O1 /FA main.cpp

call main.exe

del main.obj

