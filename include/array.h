#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

// Array: penyimpanan data pasien dengan akses O(1)
class ArrayPasien {
private:
    Pasien data[MAX_PASIEN];
    int jumlah;

public:
    // Constructor
    ArrayPasien();

    // ==========================
    // CRUD Data Pasien
    // ==========================

    // Menambahkan data pasien
    bool tambah(const Pasien& p);

    // Mencari data pasien berdasarkan No. RM
    bool cari(const std::string& noRM, Pasien& hasil) const;

    // Mengupdate data pasien
    bool update(const std::string& noRM, const Pasien& pBaru);

    // Menghapus data pasien
    bool hapus(const std::string& noRM);

    // Menampilkan seluruh data pasien
    void tampilkan() const;

    // Mendapatkan jumlah pasien
    int getJumlah() const;

    // Mengecek apakah No. RM sudah ada
    bool duplikat(const std::string& noRM) const;

    // ==========================
    // SORTING (Bubble Sort)
    // ==========================

    // Mengurutkan berdasarkan Nama
    void bubbleSortNama();

    // Mengurutkan berdasarkan Nomor Rekam Medis
    void bubbleSortNoRM();
};

#endif