#!/bin/bash
echo "========================================"
echo " Build: Sistem Klinik E-Health (C++)"
echo "========================================"

mkdir -p bin

g++ -std=c++17 -Wall -Wextra -Iinclude \
    src/main.cpp \
    src/array.cpp \
    src/linkedlist.cpp \
    src/queue.cpp \
    src/stack.cpp \
    src/tree.cpp \
    -o bin/e-health-klinik

if [ $? -eq 0 ]; then
    echo ""
    echo "[SUKSES] Build berhasil!"
    echo "Jalankan dengan perintah: ./bin/e-health-klinik"
else
    echo ""
    echo "[GAGAL] Build error. Periksa kembali kode C++ kamu."
fi
