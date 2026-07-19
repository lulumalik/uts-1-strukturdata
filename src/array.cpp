#include "../include/array.h"
#include <iostream>

ArrayPasien::ArrayPasien() : jumlah(0) {}

// =============================
// Tambah Data Pasien
// =============================
bool ArrayPasien::tambah(const Pasien& p) {
    if (jumlah >= MAX_PASIEN)
        return false;

    data[jumlah++] = p;
    return true;
}

// =============================
// Cari Data Pasien
// =============================
bool ArrayPasien::cari(const std::string& noRM, Pasien& hasil) const {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) {
            hasil = data[i];
            return true;
        }
    }
    return false;
}

// =============================
// Update Data Pasien
// =============================
bool ArrayPasien::update(const std::string& noRM, const Pasien& pBaru) {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) {
            data[i] = pBaru;
            return true;
        }
    }
    return false;
}

// =============================
// Hapus Data Pasien
// =============================
bool ArrayPasien::hapus(const std::string& noRM) {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) {

            for (int j = i; j < jumlah - 1; j++) {
                data[j] = data[j + 1];
            }

            jumlah--;
            return true;
        }
    }

    return false;
}

// =============================
// Tampilkan Data
// =============================
void ArrayPasien::tampilkan() const {

    if (jumlah == 0) {
        std::cout << "  [Array kosong]\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {

        std::cout
            << "  [" << i + 1 << "] "
            << data[i].noRM << " | "
            << data[i].nama << " | "
            << data[i].umur << " Tahun | "
            << data[i].poli << " | "
            << data[i].status << "\n";
    }
}

// =============================
// Jumlah Data
// =============================
int ArrayPasien::getJumlah() const {
    return jumlah;
}

// =============================
// Cek Duplikasi No RM
// =============================
bool ArrayPasien::duplikat(const std::string& noRM) const {

    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM)
            return true;
    }

    return false;
}

const Pasien& ArrayPasien::getAt(int index) const {
    return data[index];
}

Pasien& ArrayPasien::getAt(int index) {
    return data[index];
}

void ArrayPasien::setAt(int index, const Pasien& p) {
    if (index >= 0 && index < jumlah)
        data[index] = p;
}

void ArrayPasien::tukar(int i, int j) {
    if (i < 0 || j < 0 || i >= jumlah || j >= jumlah) return;
    Pasien temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

// =======================================================
// Bubble Sort Berdasarkan Nama
// =======================================================
void ArrayPasien::bubbleSortNama() {

    if (jumlah <= 1) {
        std::cout << "\nData belum cukup untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlah - 1; i++) {

        for (int j = 0; j < jumlah - i - 1; j++) {

            if (data[j].nama > data[j + 1].nama) {

                Pasien temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

            }

        }

    }

    std::cout << "\nData berhasil diurutkan berdasarkan Nama.\n";
}

// =======================================================
// Bubble Sort Berdasarkan Nomor Rekam Medis
// =======================================================
void ArrayPasien::bubbleSortNoRM() {

    if (jumlah <= 1) {
        std::cout << "\nData belum cukup untuk diurutkan.\n";
        return;
    }

    for (int i = 0; i < jumlah - 1; i++) {

        for (int j = 0; j < jumlah - i - 1; j++) {

            if (data[j].noRM > data[j + 1].noRM) {

                Pasien temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

            }

        }

    }

    std::cout << "\nData berhasil diurutkan berdasarkan Nomor Rekam Medis.\n";
}