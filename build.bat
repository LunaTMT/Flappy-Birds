@echo off
cls

echo Compiling C++ code...

:: Create 'bin' directory if it doesn't exist
if not exist bin m
:: Compile C++ code
g++ -g src\*.cpp src\entities\*.cpp src\utilities\*.cpp src\globals\*.cpp -Iinclude -Iinclude\entities -Iinclude\utilities -Iinclude\globals -o bin\main -lsfml-graphics -lsfml-window -lsfml-system

if %errorlevel% neq 0 (
    echo Compilation failed.
) else (
    echo Compilation successful.
    bin\main
)
