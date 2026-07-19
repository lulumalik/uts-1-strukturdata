# Skrip Demo Presentasi — Klinik E-Health

Gunakan urutan ini saat presentasi live (total ±8–10 menit).

---

## Persiapan (1 menit)

```bat
build.bat
bin\e-health-klinik.exe
```

Siapkan data contoh di catatan (copy-paste cepat).

---

## Bagian A — Fondasi (Faris / siapa saja) ±2 menit

1. Tunjukkan menu utama (0–13).
2. **Menu 1** — tambah 3 pasien cepat:

| No RM | Nama | Umur | Poli | Status |
|-------|------|------|------|--------|
| RM001 | Andi | 35 | Umum | Menunggu |
| RM003 | Budi | 28 | Anak | Menunggu |
| RM002 | Citra | 22 | Gigi | Menunggu |

3. **Menu 6** — tampilkan Array (urutan insert).
4. (Opsional) **Menu 7** enqueue RM001 → dequeue → **Menu 8** lihat riwayat Stack.

**Kalimat kunci:** *“Queue untuk antrian FIFO, Stack untuk riwayat LIFO.”*

---

## Bagian B — Graph BFS/DFS (Lulu) ±3 menit

**Menu 11**

1. Pilih **1** — tampilkan jaringan rujukan (vertex + edge).
2. Pilih **2** — BFS dari `Umum`  
   Expected: `Umum -> Gigi -> Anak -> Penyakit Dalam -> Lab -> Apotek`
3. Pilih **4** — jalur terpendek `Umum` → `Apotek`  
   Expected: 1 langkah (`Umum -> Apotek`)
4. Pilih **5** — cek jalur `Gigi` → `Lab`  
   Expected: ada jalur (DFS)

**Kalimat kunci:** *“BFS cari jalur rujukan terpendek; DFS cek apakah rujukan memungkinkan. Kompleksitas O(V+E).”*

---

## Bagian C — Sorting & Searching / Big O (Nabil) ±3 menit

### Sorting — Menu 12

1. Pastikan sudah ada ≥5 pasien (tambah lagi jika perlu: RM004, RM005).
2. **Bubble Sort** by **Nama** (12 → 1 → 2) → tunjukkan urutan A–Z.
3. **Selection Sort** by **Umur** (12 → 2 → 3) → umur naik.
4. **Insertion Sort** by **No RM** (12 → 3 → 1) → RM001…RM005.

**Kalimat kunci:** *“Sorting O(n²) membantu petugas membaca daftar pasien teratur.”*

### Searching — Menu 13

1. Pilih **1**, cari `RM003` → bandingkan jumlah perbandingan Linear vs Binary.
2. Pilih **2** → tampilkan ringkasan Big O sistem.
3. (Opsional) Pilih **3** → sort No RM lalu search lagi.

**Kalimat kunci:** *“Linear O(n), Binary O(log n) tapi wajib data terurut No RM.”*

---

## Penutup (30 detik)

- **Menu 10** statistik singkat.
- **Menu 0** keluar.
- Serahkan ke slide kesimpulan + pembagian kerja.

---

## Data lengkap 5 pasien (copy cepat)

```
RM005 / Citra Dewi / 22 / Gigi / Menunggu
RM001 / Andi Pratama / 35 / Umum / Menunggu
RM003 / Budi Santoso / 28 / Anak / Menunggu
RM002 / Eka Putri / 40 / Penyakit Dalam / Menunggu
RM004 / Dina Lestari / 19 / Umum / Menunggu
```

Bukti uji otomatis: `docs/hasil-uji.txt`
