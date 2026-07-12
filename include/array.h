#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

// Array: penyimpanan data pasien dengan akses O(1)
class ArrayPasien {
private:
    Pasien data[MAX_PASIEN];
    int jumlah;

public:
    ArrayPasien();
    // fungsi untuk menambahkan data pasien
    bool tambah(const Pasien& p);
    // fungsi untuk mencari data pasien
    bool cari(const std::string& noRM, Pasien& hasil) const;
    // fungsi untuk mengupdate data pasien
    bool update(const std::string& noRM, const Pasien& pBaru);
    bool hapus(const std::string& noRM);
    // fungsi untuk menampilkan data pasien
    void tampilkan() const;
    // fungsi untuk mendapatkan jumlah data pasien
    int getJumlah() const;
    bool duplikat(const std::string& noRM) const;

    // akses elemen untuk sorting & searching
    Pasien getAt(int indeks) const;
    void setAt(int indeks, const Pasien& p);
    void tukar(int i, int j);
};

#endif
