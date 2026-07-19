# Ringkasan Hasil Uji

Sumber log lengkap: `docs/hasil-uji.txt` (dijalankan otomatis terhadap `bin/e-health-klinik.exe`).

## Data sampel
5 pasien: RM005 Citra, RM001 Andi, RM003 Budi, RM002 Eka, RM004 Dina.

## Sorting
| Algoritma | Kriteria | Status |
|-----------|----------|--------|
| Bubble Sort | Nama | Lulus — Andi…Eka |
| Selection Sort | Umur | Lulus — 19…40 |
| Insertion Sort | No RM | Lulus — RM001…RM005 |

## Searching (cari RM003 setelah sort No RM)
| Metode | Perbandingan | Status |
|--------|--------------|--------|
| Linear Search | 3 | Ketemu |
| Binary Search | 1 | Ketemu |

## Graph
| Uji | Hasil | Status |
|-----|-------|--------|
| BFS dari Umum | Umum→Gigi→Anak→Penyakit Dalam→Lab→Apotek | Lulus |
| Jalur terpendek Umum→Apotek | 1 langkah | Lulus |
| DFS Gigi→Lab | Ada jalur | Lulus |

## Statistik akhir
- Linked List: 5 · Array: 5 · Vertex graph: 6 · Kapasitas: 150
