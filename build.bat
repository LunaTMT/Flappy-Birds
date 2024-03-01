@echo off
cls

echo Compiling C++ code...

:: Create 'bin' directory if it doesn't exist
if not exist bin mkdir bin

:: Compile C++ code
g++ -g src\*.cpp src\entities\*.cpp -Iinclude -Iinclude\entities -o bin\main -lsfml-graphics -lsfml-window -lsfml-system

if %errorlevel% neq 0 (
    echo Compilation failed.
) else (
    echo Compilation successful.
    bin\main
)
