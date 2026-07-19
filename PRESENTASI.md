# Outline Presentasi (12 Slide)

**Judul:** Sistem Manajemen Antrian & Rekam Medis Pasien Berbasis E-Health  
**Mata Kuliah:** Struktur Data dan Algoritma  
**Anggota:** Lulu · Nabil · Faris  

Salin ke PowerPoint/Canva. Satu slide = satu poin besar.

---

## Slide 1 — Judul
- Nama project
- Nama kelompok + NIM
- Mata kuliah / kampus

## Slide 2 — Latar Belakang
- Kebutuhan e-health: data pasien, antrian, riwayat, rujukan
- Solusi: aplikasi CLI C++ tanpa database eksternal

## Slide 3 — Rumusan & Tujuan
- Kelola pasien + antrian + riwayat
- Terapkan Array, LL, Queue, Stack, Tree, Graph
- BFS/DFS, Sorting, Searching + Big O

## Slide 4 — Struktur Data yang Dipakai
| Struktur | Fungsi |
|----------|--------|
| Array + Linked List | Data pasien |
| Queue | Antrian (FIFO) |
| Stack | Riwayat (LIFO) |
| Tree | Hierarki poli |
| Graph | Jaringan rujukan |

## Slide 5 — Alur Sistem Singkat
Tambah pasien → validasi tree → simpan LL+Array → antrian Queue → selesai → Stack  
Rujukan: Graph BFS/DFS · Laporan: Sort + Search

## Slide 6 — Demo Graph (Lulu)
- Vertex: Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek
- BFS: jalur terpendek
- DFS: cek ada jalur
- Screenshot / live demo Menu 11

## Slide 7 — Demo Sorting (Nabil)
- Bubble / Selection / Insertion
- Kriteria: No RM, Nama, Umur
- Manfaat: daftar pasien terurut untuk petugas

## Slide 8 — Searching & Big O (Nabil)
- Linear O(n) vs Binary O(log n)
- Syarat binary: data terurut No RM
- Contoh: RM003 → bandingkan jumlah perbandingan

## Slide 9 — Error Handling
- Data kosong, duplikasi No RM, poli invalid
- Array penuh → rollback Linked List
- Antrian/stack kosong/penuh

## Slide 10 — Hasil Pengujian
- 5 pasien sampel lulus
- Sort nama/umur/No RM lulus
- BFS Umum→Apotek = 1 langkah
- DFS Gigi→Lab = ada jalur

## Slide 11 — Kesimpulan & Saran
- Konsep SDA berhasil diterapkan ke studi kasus e-health
- Saran: persistensi data, GUI, algoritma sort lebih cepat

## Slide 12 — Pembagian Kerja & QnA
| Anggota | Kontribusi |
|---------|------------|
| Lulu | Graph, BFS, DFS |
| Nabil | Sorting, Searching, Big O |
| Faris | Laporan, presentasi, integrasi |

**Terima kasih — siap pertanyaan**

---

## Tips presentasi
- Maksimal 1 diagram per slide
- Live demo pakai `DEMO.md`
- Cadangan: buka `docs/hasil-uji.txt` jika demo gagal
