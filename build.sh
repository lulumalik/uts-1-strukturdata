#!/bin/bash
echo "========================================"
echo " Build: Sistem Klinik E-Health (C++)"
echo "========================================"

mkdir -p bin

echo "[1/2] Compile SQLite..."
gcc -c -O2 -Ithird_party/sqlite third_party/sqlite/sqlite3.c -o bin/sqlite3.o
if [ $? -ne 0 ]; then
    echo "[GAGAL] Compile SQLite gagal."
    exit 1
fi

echo "[2/2] Compile program..."
g++ -std=c++17 -Wall -Wextra -Iinclude -Ithird_party/sqlite \
    src/main.cpp \
    src/array.cpp \
    src/linkedlist.cpp \
    src/queue.cpp \
    src/stack.cpp \
    src/tree.cpp \
    src/graph.cpp \
    src/database.cpp \
    src/sortsearch.cpp \
    bin/sqlite3.o \
    -o bin/e-health-klinik

if [ $? -eq 0 ]; then
    echo ""
    echo "[SUKSES] Build berhasil!"
    echo "Jalankan dengan perintah: ./bin/e-health-klinik"
else
    echo ""
    echo "[GAGAL] Build error. Periksa kembali kode C++ kamu."
fi
