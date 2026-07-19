@echo off
echo ========================================
echo  Build: Sistem Klinik E-Health (C++)
echo ========================================

if not exist bin mkdir bin

echo [1/2] Compile SQLite...
gcc -c -O2 -Ithird_party/sqlite third_party/sqlite/sqlite3.c -o bin/sqlite3.o
if %ERRORLEVEL% NEQ 0 (
    echo [GAGAL] Compile SQLite gagal.
    exit /b 1
)

echo [2/2] Compile program...
g++ -std=c++17 -Wall -Wextra -Iinclude -Ithird_party/sqlite ^
    src/main.cpp ^
    src/array.cpp ^
    src/linkedlist.cpp ^
    src/queue.cpp ^
    src/stack.cpp ^
    src/tree.cpp ^
    src/graph.cpp ^
    src/database.cpp ^
    src/sortsearch.cpp ^
    bin/sqlite3.o ^
    -o bin/e-health-klinik.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo [SUKSES] Build berhasil!
    echo Jalankan: bin\e-health-klinik.exe
) else (
    echo.
    echo [GAGAL] Build error. Periksa kembali kode C++ kamu.
)
