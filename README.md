# data_structures
Stack and queue implementations
The projects were compiled as static libraries. This batch file could be modified to change the relative paths for src and bin and be used

gcc -Wall -O -v -c ..\src\%1.c -o ..\bin\%1.o
ar rcs ..\bin\lib%1.a ..\bin\%1.o
gcc -Wall -O -v -static ..\src\%2.c -L..\bin -l%1 -o ..\bin\%2.exe
