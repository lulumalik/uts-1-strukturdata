# TODO List — Pembagian Tugas (3 Orang)

**Project:** Sistem Klinik E-Health (Struktur Data & Algoritma)  
**Anggota:**
1. LULU MAULANA MALIK (250401010517)
2. A. M. NABIL AIENDRA DZIKRA (250401010507)
3. MUHAMMAD FARIS (250401010509)

**Cara pakai:** centang `[x]` jika selesai. Update status di grup sebelum presentasi/submit.

---

## Status Cepat

| Area | Status |
|------|--------|
| Kode inti (Array, LL, Queue, Stack, Tree) | ✅ Selesai |
| Graph + BFS + DFS | ✅ Selesai |
| Sorting + Searching + Big O | ✅ Selesai |
| Dokumentasi bab 1–7 + lampiran menu | ✅ Ada (perlu dicek ulang) |
| Testing / screenshot / demo | ❌ Belum |
| Bab implementasi, pengujian, kesimpulan, pustaka | ❌ Belum |
| Presentasi (PPT/slide) | ❌ Belum |
| Commit & push perubahan terbaru | ❌ Belum |

---

## Orang 1 — LULU (Kode + Modul Graph)

**Fokus:** pastikan modul Graph/BFS/DFS jalan & siap demo.

### Belum / perlu dikerjakan
- [ ] **Uji manual Menu 11 (Graph)**
  - [ ] Tampilkan jaringan rujukan
  - [ ] BFS dari `Umum`
  - [ ] DFS dari `Anak`
  - [ ] Jalur terpendek `Umum` → `Apotek`
  - [ ] Cek jalur `Gigi` → `Lab` (harusnya ada lewat Umum/dll)
  - [ ] Uji input poli salah → muncul error
- [ ] **Screenshot hasil Graph** (simpan di folder `docs/screenshots/` atau Word laporan)
- [ ] **Tulis di dokumentasi:** bagian *Implementasi Graph, BFS, DFS* (cara kerja singkat + contoh output)
- [ ] **Tulis flow sistem** untuk Menu 11 (mirip flow antrian yang sudah ada)
- [ ] **Siapkan skrip demo Graph** (urutan klik menu saat presentasi)
- [ ] **Review komentar kode** di `graph.h` / `graph.cpp` (jelas untuk dosen)

### Sudah (referensi)
- `include/graph.h`, `src/graph.cpp`
- Menu 11 di `main.cpp`
- Penjelasan Graph di `DOKUMENTASI.md` (landasan teori)

---

## Orang 2 — NABIL (Kode + Sorting / Searching / Big O)

**Fokus:** pastikan sorting & searching + analisis Big O siap demo.

### Belum / perlu dikerjakan
- [ ] **Uji manual Menu 12 & 13**
  - [ ] Tambah minimal 5 pasien beda No RM / nama / umur
  - [ ] Bubble Sort by Nama
  - [ ] Selection Sort by Umur
  - [ ] Insertion Sort by No RM
  - [ ] Bandingkan Linear vs Binary **sebelum** sort (tunjukkan binary bisa gagal)
  - [ ] Sort No RM lalu Binary Search (Menu 13 opsi 3)
  - [ ] Tampilkan Analisis Big O Sistem
- [ ] **Screenshot** hasil sorting & perbandingan jumlah perbandingan Linear vs Binary
- [ ] **Tulis di dokumentasi:**
  - [ ] Bagian *Implementasi Sorting*
  - [ ] Bagian *Implementasi Searching & Big O* (tabel O(n) vs O(log n))
  - [ ] Flow Menu 12 & 13
- [ ] **Siapkan skrip demo Sorting/Searching** untuk presentasi
- [ ] **Review komentar kode** di `sortsearch.h` / `sortsearch.cpp` + aksesor di `array.h`

### Sudah (referensi)
- `include/sortsearch.h`, `src/sortsearch.cpp`
- Aksesor `getAt` / `setAt` / `tukar` di Array
- Menu 12 & 13 di `main.cpp`

---

## Orang 3 — FARIS (Dokumentasi Laporan + Presentasi + Integrasi)

**Fokus:** laporan lengkap, presentasi, dan kelengkapan submit.

### Belum / perlu dikerjakan
- [ ] **Lengkapi `DOKUMENTASI.md` / laporan Word**
  - [ ] Bab **Implementasi Sistem** (struktur file, cara build, cuplikan kode penting)
  - [ ] Bab **Pengujian** (tabel test case + hasil expected/actual)
  - [ ] Bab **Kesimpulan**
  - [ ] Bab **Saran**
  - [ ] **Daftar Pustaka**
- [ ] **Kumpulkan screenshot** dari Orang 1 & 2 → rapikan di laporan
- [ ] **Update Kata Pengantar / Pendahuluan** jika nama dosen / kampus / tanggal perlu diisi
- [ ] **Buat PPT presentasi** (10–15 slide)
  - [ ] Latar belakang & studi kasus
  - [ ] Struktur data yang dipakai (6 struktur)
  - [ ] Alur sistem singkat
  - [ ] Demo Graph BFS/DFS
  - [ ] Demo Sorting + Big O Searching
  - [ ] Kesimpulan & pembagian kerja
- [ ] **README final check** (cara build Windows + Mac)
- [ ] **Git commit + push** semua file baru (minta konfirmasi dulu jika perlu)
  - File belum ter-commit: `graph.*`, `sortsearch.*`, `DOKUMENTASI.md`, perubahan `main.cpp`, `array.*`, build scripts

### Opsional (jika ada waktu)
- [ ] Video demo singkat (1–3 menit)
- [ ] Cover laporan / halaman pengesahan sesuai format kampus

---

## Tugas Bersama (ketiganya)

| No | Tugas | Deadline usulan |
|----|--------|-----------------|
| 1 | Build & jalankan program di laptop masing-masing | ASAP |
| 2 | Rehearsal presentasi 1x bersama | H-1 submit |
| 3 | Cek format laporan sesuai template dosen | H-1 submit |
| 4 | Pastikan tidak ada crash di semua menu 0–13 | H-1 submit |

---

## Checklist Test Case (bagi siapa saja yang uji)

| ID | Skenario | Expected | PIC |
|----|----------|----------|-----|
| T01 | Tambah pasien valid | Sukses, masuk LL + Array | Siapa saja |
| T02 | Tambah No RM duplikat | Error duplikasi | Siapa saja |
| T03 | Tambah poli salah | Error poli | Siapa saja |
| T04 | Enqueue → Dequeue | Status Selesai + masuk Stack | Siapa saja |
| T05 | BFS Umum | Urutan level-by-level | Lulu |
| T06 | Jalur terpendek Umum→Apotek | Ada jalur, langkah ≥ 1 | Lulu |
| T07 | Bubble Sort by Nama | Array terurut A–Z | Nabil |
| T08 | Binary Search tanpa sort | Bisa gagal / beda hasil | Nabil |
| T09 | Binary Search setelah sort No RM | Ketemu, banding lebih sedikit | Nabil |
| T10 | Menu invalid | Error menu tidak valid | Faris (laporan) |

---

## Ringkasan Pembagian

```
LULU   → Graph / BFS / DFS + uji + dokumentasi modul itu + demo
NABIL  → Sorting / Searching / Big O + uji + dokumentasi modul itu + demo
FARIS  → Laporan lengkap (implementasi/uji/kesimpulan/pustaka) + PPT + commit/submit
```

Kalau ada yang selesai lebih cepat, bantu yang lain (terutama screenshot & rehearsal).
