#ifndef STACK_H
#define STACK_H

#include "types.h"

// Stack (LIFO): riwayat pemeriksaan medis pasien
class StackRiwayat {
private:
    Pasien data[MAX_PASIEN];
    int top;

public:
    StackRiwayat();

    // fungsi untuk menambahkan data pasien ke riwayat
    bool push(const Pasien& p);
    // fungsi untuk menghapus data pasien dari riwayat
    bool pop(Pasien& p);
    // fungsi untuk menampilkan data pasien di riwayat
    void tampilkan() const;
    // fungsi untuk memeriksa apakah riwayat kosong
    bool kosong() const;
    // fungsi untuk memeriksa apakah riwayat penuh
    bool penuh() const;
    // fungsi untuk mendapatkan ukuran riwayat
    int ukuran() const;
};

#endif
