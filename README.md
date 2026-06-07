# 🏥 Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health

![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue?style=flat-square&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/License-Academic-orange?style=flat-square)

> Proyek UTS Mata Kuliah **Struktur Data dan Algoritma** — Simulasi sistem manajemen klinik berbasis C++ yang mengimplementasikan berbagai struktur data fundamental tanpa ketergantungan database eksternal.

---

## 📋 Deskripsi Proyek

Sistem ini mensimulasikan pengelolaan klinik secara digital dengan kapasitas **maksimal 150 pasien per bulan**. Seluruh data dikelola menggunakan struktur data yang diimplementasikan secara manual dalam C++, mencakup *linked list*, *queue*, *stack*, dan *tree* — tanpa menggunakan database eksternal seperti MySQL atau SQLite.

Tujuan utama proyek ini adalah mendemonstrasikan penerapan nyata struktur data dalam konteks sistem informasi kesehatan (*e-health*), sekaligus memenuhi capaian pembelajaran mata kuliah Struktur Data dan Algoritma.

---

## 👥 Anggota Kelompok

| No | Nama | NIM |
|----|------|-----|
| 1 | LULU MAULANA MALIK | 250401010517 |
| 2 | A. M. NABIL AIENDRA DZIKRA | 250401010507 |
| 3 | MUHAMMAD FARIS | 250401010509 |

---

## 🗂️ Struktur Direktori

```
uts-1-strukturdata/
├── bin/                    # Output executable
│   └── e-health-klinik.exe
├── include/                # Header files (.h)
│   ├── pasien.h
│   ├── antrian.h
│   ├── riwayat.h
│   └── poli.h
├── src/                    # Source files (.cpp)
│   ├── main.cpp
│   ├── pasien.cpp
│   ├── antrian.cpp
│   ├── riwayat.cpp
│   └── poli.cpp
├── build.bat               # Build script (Windows)
└── README.md
```

---

## ⚙️ Cara Build & Jalankan

### Prasyarat

- Compiler **g++** dengan dukungan standar **C++17**
- Sistem operasi Windows (atau Linux/macOS dengan penyesuaian path)
- Tidak diperlukan library eksternal

### Windows — Menggunakan `build.bat`

```bat
build.bat
bin\e-health-klinik.exe
```

### Manual — Menggunakan `g++` langsung

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o bin/e-health-klinik.exe
bin/e-health-klinik.exe
```

> **Keterangan flag:**
> - `-std=c++17` → menggunakan standar C++17
> - `-Wall -Wextra` → mengaktifkan semua peringatan kompiler
> - `-Iinclude` → menambahkan folder `include/` ke path pencarian header

---

## 🚀 Fitur Sistem

### 1. 👤 Manajemen Data Pasien
Pengelolaan data pasien menggunakan **Singly Linked List** sebagai struktur penyimpanan utama.

| Operasi | Keterangan |
|---------|-----------|
| **Tambah Pasien** | Menambahkan node baru ke linked list dengan validasi duplikasi ID dan kelengkapan data |
| **Cari Pasien** | *Sequential search* sepanjang linked list berdasarkan ID atau nama pasien |
| **Update Pasien** | Menelusuri linked list lalu memperbarui data pada node yang ditemukan |
| **Hapus Pasien** | Manipulasi pointer untuk melepas node dari linked list dan membebaskan memori |
| **Tampilkan Semua** | Traversal linked list dan array untuk menampilkan seluruh data terdaftar |

### 2. 🔢 Sistem Antrian (Queue)
Mengelola urutan pasien yang akan diperiksa menggunakan struktur data **Queue** (FIFO — *First In, First Out*).

- **Enqueue** → Pasien baru masuk ke belakang antrian
- **Dequeue** → Pasien dipanggil dari depan antrian untuk diperiksa
- Antrian terhubung dengan data pasien di linked list untuk konsistensi informasi

### 3. 📋 Riwayat Medis (Stack)
Pencatatan riwayat pemeriksaan menggunakan **Stack** (LIFO — *Last In, First Out*), sehingga riwayat terbaru selalu tampil di urutan pertama.

- **Push** → Menambahkan catatan pemeriksaan baru ke puncak stack
- **Pop** → Mengambil/menghapus catatan pemeriksaan terakhir
- **Peek** → Melihat riwayat terbaru tanpa menghapus data

### 4. 🏗️ Struktur Poli Klinik (Tree)
Representasi hierarki poli klinik menggunakan struktur **Tree**, memudahkan navigasi dan penugasan pasien ke poli yang sesuai.

```
           Klinik Utama
          /     |      \      \
       Umum   Gigi    Anak   Penyakit Dalam
```

### 5. 📊 Statistik Pasien
Menampilkan ringkasan data klinik, mencakup:
- Total pasien terdaftar bulan ini
- Jumlah pasien dalam antrian aktif
- Persentase kapasitas terpakai (dari maks. 150 pasien/bulan)
- Distribusi pasien per poli

---

## 🧠 Struktur Data yang Digunakan

| Struktur Data | Digunakan Untuk | Kompleksitas |
|---------------|-----------------|-------------|
| **Linked List** | Penyimpanan data pasien | Search: O(n), Insert/Delete: O(1) |
| **Queue** | Antrian pemeriksaan pasien | Enqueue/Dequeue: O(1) |
| **Stack** | Riwayat medis pasien | Push/Pop: O(1) |
| **Tree** | Hierarki poli klinik | Traversal: O(n) |
| **Array** | Tampilan & statistik data | Access: O(1) |

---

## 🖼️ Tampilan Program

Program berjalan di terminal/command prompt dengan tampilan menu berbasis teks:

```
╔══════════════════════════════════════════╗
║   SISTEM E-HEALTH MANAJEMEN KLINIK       ║
╠══════════════════════════════════════════╣
║  1. Tambah Data Pasien                   ║
║  2. Cari Data Pasien                     ║
║  3. Update Data Pasien                   ║
║  4. Hapus Data Pasien                    ║
║  5. Tampilkan Semua Pasien               ║
║  6. Kelola Antrian                       ║
║  7. Riwayat Medis                        ║
║  8. Struktur Poli Klinik                 ║
║  9. Statistik Pasien                     ║
║  0. Keluar                               ║
╚══════════════════════════════════════════╝
```

