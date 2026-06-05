#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

// Queue (FIFO): antrian pasien di klinik
class QueueAntrian {
private:
    Pasien data[MAX_PASIEN];
    int front;
    int rear;

public:
    QueueAntrian();

    // fungsi untuk menambahkan data pasien ke antrian
    bool enqueue(const Pasien& p);
    // fungsi untuk menghapus data pasien dari antrian
    bool dequeue(Pasien& p);
    // fungsi untuk menampilkan data pasien di antrian
    void tampilkan() const;
    // fungsi untuk memeriksa apakah antrian kosong
    bool kosong() const;
    // fungsi untuk memeriksa apakah antrian penuh
    bool penuh() const;
    // fungsi untuk mendapatkan ukuran antrian
    int ukuran() const;
};

#endif
