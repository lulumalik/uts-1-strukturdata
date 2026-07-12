#include "../include/array.h"
#include <iostream>

ArrayPasien::ArrayPasien() : jumlah(0) {}

bool ArrayPasien::tambah(const Pasien& p) {
    if (jumlah >= MAX_PASIEN) return false;
    data[jumlah++] = p;
    return true;
}

bool ArrayPasien::cari(const std::string& noRM, Pasien& hasil) const {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) {
            hasil = data[i];
            return true;
        }
    }
    return false;
}

bool ArrayPasien::update(const std::string& noRM, const Pasien& pBaru) {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) {
            data[i] = pBaru;
            return true;
        }
    }
    return false;
}

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

void ArrayPasien::tampilkan() const {
    if (jumlah == 0) {
        std::cout << "  [Array kosong]\n";
        return;
    }
    for (int i = 0; i < jumlah; i++) {
        std::cout << "  [" << i << "] " << data[i].noRM << " - "
                  << data[i].nama << " (" << data[i].umur << " thn) - "
                  << data[i].poli << " - " << data[i].status << "\n";
    }
}

int ArrayPasien::getJumlah() const {
    return jumlah;
}

bool ArrayPasien::duplikat(const std::string& noRM) const {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].noRM == noRM) return true;
    }
    return false;
}

Pasien ArrayPasien::getAt(int indeks) const {
    return data[indeks];
}

void ArrayPasien::setAt(int indeks, const Pasien& p) {
    if (indeks >= 0 && indeks < jumlah)
        data[indeks] = p;
}

void ArrayPasien::tukar(int i, int j) {
    if (i < 0 || j < 0 || i >= jumlah || j >= jumlah) return;
    Pasien temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}
