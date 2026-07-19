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

1. Tunjukkan menu utama (0–15).
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

## Bagian B — Graph BFS/DFS (Lulu) ±2 menit

1. **Menu 13** — tampilkan jaringan rujukan (vertex + edge).
2. **Menu 14** — BFS dari Poli Umum  
   Expected: Umum → Gigi → Anak → Penyakit Dalam (urutan level)
3. **Menu 15** — DFS dari Poli Umum  
   Expected: traversal mendalam antar poli

**Kalimat kunci:** *“BFS telusuri rujukan per level; DFS telusuri jalur mendalam. Kompleksitas O(V+E).”*

---

## Bagian C — Sorting & Searching / Big O (Nabil) ±3 menit

### Sorting — Menu 11

1. Pastikan sudah ada ≥3 pasien.
2. **Bubble Sort** by **Nama** (11 → 1 → 2) → tunjukkan urutan A–Z.
3. **Selection Sort** by **Umur** (11 → 2 → 3) → umur naik.
4. **Insertion Sort** by **No RM** (11 → 3 → 1) → RM001…RM00x.

**Kalimat kunci:** *“Sorting O(n²) membantu petugas membaca daftar pasien teratur.”*

### Searching — Menu 12

1. Pilih **1**, cari `RM003` → bandingkan jumlah perbandingan Linear Search dengan Binary Search.
2. Pilih **2** → tampilkan ringkasan Big O sistem.
3. (Opsional) Pilih **3** → sort No RM lalu search lagi.

**Kalimat kunci:** *“Linear Search O(n), Binary Search O(log n), tapi binary wajib data terurut No RM.”*

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
