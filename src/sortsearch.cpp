#include "../include/sortsearch.h"
#include <iostream>

static int bandingkan(const Pasien& a, const Pasien& b, KriteriaSort kriteria) {
    switch (kriteria) {
        case BY_NORM:
            if (a.noRM < b.noRM) return -1;
            if (a.noRM > b.noRM) return 1;
            return 0;
        case BY_NAMA:
            if (a.nama < b.nama) return -1;
            if (a.nama > b.nama) return 1;
            return 0;
        case BY_UMUR:
            if (a.umur < b.umur) return -1;
            if (a.umur > b.umur) return 1;
            return 0;
    }
    return 0;
}

static const char* namaKriteria(KriteriaSort kriteria) {
    switch (kriteria) {
        case BY_NORM: return "No RM";
        case BY_NAMA: return "Nama";
        case BY_UMUR: return "Umur";
    }
    return "-";
}

void bubbleSort(ArrayPasien& arr, KriteriaSort kriteria) {
    int n = arr.getJumlah();
    if (n <= 1) {
        std::cout << "[INFO] Data kurang dari 2, tidak perlu diurutkan.\n";
        return;
    }

    int tukarCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bandingkan(arr.getAt(j), arr.getAt(j + 1), kriteria) > 0) {
                arr.tukar(j, j + 1);
                tukarCount++;
            }
        }
    }

    std::cout << "[SUKSES] Bubble Sort selesai (kriteria: " << namaKriteria(kriteria) << ").\n";
    std::cout << "  Jumlah tukar : " << tukarCount << "\n";
    std::cout << "  Big O        : O(n^2) waktu, O(1) ruang\n";
}

void selectionSort(ArrayPasien& arr, KriteriaSort kriteria) {
    int n = arr.getJumlah();
    if (n <= 1) {
        std::cout << "[INFO] Data kurang dari 2, tidak perlu diurutkan.\n";
        return;
    }

    int tukarCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (bandingkan(arr.getAt(j), arr.getAt(minIdx), kriteria) < 0)
                minIdx = j;
        }
        if (minIdx != i) {
            arr.tukar(i, minIdx);
            tukarCount++;
        }
    }

    std::cout << "[SUKSES] Selection Sort selesai (kriteria: " << namaKriteria(kriteria) << ").\n";
    std::cout << "  Jumlah tukar : " << tukarCount << "\n";
    std::cout << "  Big O        : O(n^2) waktu, O(1) ruang\n";
}

void insertionSort(ArrayPasien& arr, KriteriaSort kriteria) {
    int n = arr.getJumlah();
    if (n <= 1) {
        std::cout << "[INFO] Data kurang dari 2, tidak perlu diurutkan.\n";
        return;
    }

    int geserCount = 0;
    for (int i = 1; i < n; i++) {
        Pasien kunci = arr.getAt(i);
        int j = i - 1;
        while (j >= 0 && bandingkan(arr.getAt(j), kunci, kriteria) > 0) {
            arr.setAt(j + 1, arr.getAt(j));
            j--;
            geserCount++;
        }
        arr.setAt(j + 1, kunci);
    }

    std::cout << "[SUKSES] Insertion Sort selesai (kriteria: " << namaKriteria(kriteria) << ").\n";
    std::cout << "  Jumlah geser : " << geserCount << "\n";
    std::cout << "  Big O        : O(n^2) waktu (terbaik O(n) jika hampir terurut), O(1) ruang\n";
}

bool linearSearch(const ArrayPasien& arr, const std::string& noRM,
                  Pasien& hasil, int& perbandingan) {
    perbandingan = 0;
    int n = arr.getJumlah();
    for (int i = 0; i < n; i++) {
        perbandingan++;
        if (arr.getAt(i).noRM == noRM) {
            hasil = arr.getAt(i);
            return true;
        }
    }
    return false;
}

bool binarySearch(const ArrayPasien& arr, const std::string& noRM,
                  Pasien& hasil, int& perbandingan) {
    perbandingan = 0;
    int kiri = 0;
    int kanan = arr.getJumlah() - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        perbandingan++;
        const std::string& kunci = arr.getAt(tengah).noRM;

        if (kunci == noRM) {
            hasil = arr.getAt(tengah);
            return true;
        }
        if (kunci < noRM)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return false;
}

void bandingkanPencarian(const ArrayPasien& arr, const std::string& noRM) {
    if (arr.getJumlah() == 0) {
        std::cout << "[ERROR] Array pasien kosong.\n";
        return;
    }

    Pasien hasilLinear, hasilBinary;
    int bandingLinear = 0, bandingBinary = 0;

    bool ketemuLinear = linearSearch(arr, noRM, hasilLinear, bandingLinear);
    bool ketemuBinary = binarySearch(arr, noRM, hasilBinary, bandingBinary);

    std::cout << "\n--- PERBANDINGAN SEARCHING (Big O) ---\n";
    std::cout << "  Target No RM : " << noRM << "\n";
    std::cout << "  Jumlah data  : " << arr.getJumlah() << "\n\n";

    std::cout << "  Linear Search:\n";
    std::cout << "    Hasil        : " << (ketemuLinear ? "Ditemukan" : "Tidak ditemukan") << "\n";
    std::cout << "    Perbandingan : " << bandingLinear << "\n";
    std::cout << "    Big O        : O(n)\n\n";

    std::cout << "  Binary Search:\n";
    std::cout << "    Hasil        : " << (ketemuBinary ? "Ditemukan" : "Tidak ditemukan") << "\n";
    std::cout << "    Perbandingan : " << bandingBinary << "\n";
    std::cout << "    Big O        : O(log n)\n";
    std::cout << "    Catatan      : Array harus sudah diurutkan berdasarkan No RM.\n";

    if (ketemuLinear && !ketemuBinary) {
        std::cout << "\n  [INFO] Binary Search gagal menemukan data.\n";
        std::cout << "         Pastikan data sudah di-sort berdasarkan No RM terlebih dahulu.\n";
    }

    if (ketemuLinear) {
        std::cout << "\n  Data pasien:\n";
        std::cout << "    No RM  : " << hasilLinear.noRM << "\n";
        std::cout << "    Nama   : " << hasilLinear.nama << "\n";
        std::cout << "    Umur   : " << hasilLinear.umur << " tahun\n";
        std::cout << "    Poli   : " << hasilLinear.poli << "\n";
        std::cout << "    Status : " << hasilLinear.status << "\n";
    }
}

void tampilkanAnalisisBigO() {
    std::cout << "\n========================================\n";
    std::cout << "  ANALISIS BIG O — KLINIK E-HEALTH\n";
    std::cout << "========================================\n";
    std::cout << "\nStruktur Data:\n";
    std::cout << "  Array akses indeks     : O(1)\n";
    std::cout << "  Array/LL sequential    : O(n)\n";
    std::cout << "  Queue enqueue/dequeue  : O(1) / O(n)*\n";
    std::cout << "  Stack push/pop         : O(1)\n";
    std::cout << "  Tree cari poli         : O(n)\n";
    std::cout << "  Graph BFS / DFS        : O(V + E)\n";
    std::cout << "  *dequeue menggeser elemen (implementasi array)\n";

    std::cout << "\nSorting:\n";
    std::cout << "  Bubble Sort            : O(n^2)\n";
    std::cout << "  Selection Sort         : O(n^2)\n";
    std::cout << "  Insertion Sort         : O(n^2) worst, O(n) best\n";

    std::cout << "\nSearching:\n";
    std::cout << "  Linear Search          : O(n)\n";
    std::cout << "  Binary Search          : O(log n) — butuh data terurut\n";

    std::cout << "\nManfaat bagi pengguna e-health:\n";
    std::cout << "  - Sorting memudahkan petugas melihat daftar pasien teratur\n";
    std::cout << "  - Binary Search mempercepat pencarian No RM pada data besar\n";
    std::cout << "  - BFS memberi jalur rujukan terpendek antar poli\n";
    std::cout << "========================================\n";
}
