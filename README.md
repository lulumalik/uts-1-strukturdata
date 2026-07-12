# Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health

Project C++ untuk UTS Mata Kuliah **Struktur Data dan Algoritma**.

Studi kasus: simulasi sistem klinik dengan kapasitas maksimal 150 pasien per bulan, tanpa database eksternal.

## Anggota Kelompok

- LULU MAULANA MALIK (250401010517)
- A. M. NABIL AIENDRA DZIKRA (250401010507)
- MUHAMMAD FARIS (250401010509)

## Cara Build & Jalankan

### Windows (build.bat)

```bat
build.bat
bin\e-health-klinik.exe
```

### Manual (g++)

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o bin/e-health-klinik.exe
bin/e-health-klinik.exe
```

## Fitur Sistem

1. **Tambah Data Pasien** - validasi duplikasi & data kosong
2. **Cari Data Pasien** - sequential search pada linked list
3. **Update Data Pasien**
4. **Hapus Data Pasien** - manipulasi pointer linked list
5. **Tampilkan Data** - linked list & array
6. **Kelola Antrian** - enqueue/dequeue (queue)
7. **Riwayat Medis** - push/pop (stack)
8. **Struktur Poli Klinik** - tree (Umum, Gigi, Anak, Penyakit Dalam)
9. **Statistik Pasien**
10. **Graph Rujukan Poli** - BFS & DFS untuk jaringan rujukan
11. **Sorting Data Pasien** - Bubble, Selection, Insertion Sort
12. **Searching & Big O** - Linear vs Binary Search + analisis kompleksitas

## Struktur Data & Algoritma

| Modul | Konsep | Manfaat E-Health |
|-------|--------|------------------|
| Array + Linked List | Penyimpanan pasien | CRUD rekam medis |
| Queue | FIFO | Antrian pelayanan |
| Stack | LIFO | Riwayat pemeriksaan |
| Tree | Hierarki | Validasi poli klinik |
| Graph | Vertex + Edge | Jalur rujukan antar unit |
| BFS / DFS | Traversal graph | Rujukan terpendek / cek jalur |
| Sorting | O(n²) | Daftar pasien terurut |
| Searching | O(n) vs O(log n) | Cari No RM lebih efisien |
