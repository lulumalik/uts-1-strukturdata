@echo off
echo ========================================
echo  Build: Sistem Klinik E-Health (C++)
echo ========================================

if not exist bin mkdir bin

g++ -std=c++17 -Wall -Wextra -Iinclude ^
    src/main.cpp ^
    src/array.cpp ^
    src/linkedlist.cpp ^
    src/queue.cpp ^
    src/stack.cpp ^
    src/tree.cpp ^
    src/graph.cpp ^
    src/sortsearch.cpp ^
    -o bin/e-health-klinik.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo [SUKSES] Build berhasil!
    echo Jalankan: bin\e-health-klinik.exe
) else (
    echo.
    echo [GAGAL] Build error. Pastikan g++ sudah terinstall.
)

pause
