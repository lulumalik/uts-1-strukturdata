#ifndef TYPES_H
#define TYPES_H

#include <string>

// Kapasitas maksimal pasien per bulan (sesuai batasan makalah)
const int MAX_PASIEN = 150;

// Tipe data dan variabel: representasi data pasien dalam sistem klinik e-health
struct Pasien {
    std::string noRM;      // Nomor rekam medis (primary key, unik)
    std::string nama;
    int umur;
    std::string poli;      // Poli tujuan (Umum, Gigi, Anak, Penyakit Dalam)
    std::string status;    // Status pemeriksaan (Menunggu, Diperiksa, Selesai)
};

#endif
