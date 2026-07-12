#include <iostream>
#include <limits>
#include "../include/types.h"
#include "../include/array.h"
#include "../include/linkedlist.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/tree.h"
#include "../include/graph.h"
#include "../include/sortsearch.h"

using namespace std;

// Objek global struktur data
ArrayPasien arrayPasien;
LinkedListPasien linkedList;
QueueAntrian antrian;
StackRiwayat riwayat;
TreePoli treePoli;
GraphRujukan graphRujukan;

void bersihkanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void tampilkanMenu() {
    cout << "\n========================================\n";
    cout << "  SISTEM MANAJEMEN ANTRIAN & REKAM MEDIS\n";
    cout << "         KLINIK E-HEALTH (C++)\n";
    cout << "========================================\n";
    cout << "  1. Tambah Data Pasien\n";
    cout << "  2. Cari Data Pasien\n";
    cout << "  3. Update Data Pasien\n";
    cout << "  4. Hapus Data Pasien\n";
    cout << "  5. Tampilkan Semua Pasien (Linked List)\n";
    cout << "  6. Tampilkan Data Pasien (Array)\n";
    cout << "  7. Kelola Antrian Pasien (Queue)\n";
    cout << "  8. Riwayat Medis (Stack)\n";
    cout << "  9. Struktur Poli Klinik (Tree)\n";
    cout << " 10. Statistik Pasien\n";
    cout << " 11. Graph Rujukan Poli (BFS/DFS)\n";
    cout << " 12. Sorting Data Pasien\n";
    cout << " 13. Searching & Analisis Big O\n";
    cout << "  0. Keluar\n";
    cout << "========================================\n";
    cout << "Pilih menu: ";
}

Pasien inputPasien(bool includeStatus = true) {
    Pasien p;
    cout << "No Rekam Medis : ";
    getline(cin, p.noRM);
    cout << "Nama Pasien    : ";
    getline(cin, p.nama);
    cout << "Umur           : ";
    cin >> p.umur;
    bersihkanBuffer();
    cout << "Poli Tujuan    : ";
    getline(cin, p.poli);

    if (includeStatus) {
        cout << "Status         : ";
        getline(cin, p.status);
    } else {
        p.status = "Menunggu";
    }

    return p;
}

void tambahPasien() {
    cout << "\n--- TAMBAH DATA PASIEN ---\n";
    Pasien p = inputPasien();

    if (p.noRM.empty() || p.nama.empty() || p.poli.empty()) {
        cout << "[ERROR] Data tidak boleh kosong!\n";
        return;
    }

    if (linkedList.duplikat(p.noRM) || arrayPasien.duplikat(p.noRM)) {
        cout << "[ERROR] Duplikasi data! No RM '" << p.noRM << "' sudah terdaftar.\n";
        return;
    }

    if (!treePoli.cariPoli(p.poli)) {
        cout << "[ERROR] Poli '" << p.poli << "' tidak ditemukan.\n";
        cout << "Poli tersedia: Umum, Gigi, Anak, Penyakit Dalam\n";
        return;
    }

    linkedList.tambah(p);
    if (!arrayPasien.tambah(p)) {
        cout << "[ERROR] Array penuh! Kapasitas maksimal " << MAX_PASIEN << " pasien.\n";
        linkedList.hapus(p.noRM);
        return;
    }

    cout << "[SUKSES] Pasien '" << p.nama << "' berhasil ditambahkan.\n";
}

void cariPasien() {
    cout << "\n--- CARI DATA PASIEN ---\n";
    string noRM;
    cout << "Masukkan No RM: ";
    getline(cin, noRM);

    if (noRM.empty()) {
        cout << "[ERROR] No RM tidak boleh kosong!\n";
        return;
    }

    Node* node = linkedList.cari(noRM);
    if (node == nullptr) {
        cout << "[ERROR] Data pasien dengan No RM '" << noRM << "' tidak ditemukan.\n";
        return;
    }

    Pasien& p = node->data;
    cout << "\nData ditemukan:\n";
    cout << "  No RM  : " << p.noRM << "\n";
    cout << "  Nama   : " << p.nama << "\n";
    cout << "  Umur   : " << p.umur << " tahun\n";
    cout << "  Poli   : " << p.poli << "\n";
    cout << "  Status : " << p.status << "\n";
}

void updatePasien() {
    cout << "\n--- UPDATE DATA PASIEN ---\n";
    string noRM;
    cout << "Masukkan No RM yang akan diupdate: ";
    getline(cin, noRM);

    if (linkedList.cari(noRM) == nullptr) {
        cout << "[ERROR] Data pasien tidak ditemukan.\n";
        return;
    }

    cout << "Masukkan data baru:\n";
    Pasien pBaru = inputPasien();
    pBaru.noRM = noRM;

    linkedList.update(noRM, pBaru);
    arrayPasien.update(noRM, pBaru);
    cout << "[SUKSES] Data pasien berhasil diupdate.\n";
}

void hapusPasien() {
    cout << "\n--- HAPUS DATA PASIEN ---\n";
    string noRM;
    cout << "Masukkan No RM yang akan dihapus: ";
    getline(cin, noRM);

    bool hapusLL = linkedList.hapus(noRM);
    bool hapusArr = arrayPasien.hapus(noRM);

    if (!hapusLL && !hapusArr) {
        cout << "[ERROR] Data pasien tidak ditemukan.\n";
        return;
    }

    cout << "[SUKSES] Data pasien berhasil dihapus.\n";
}

void kelolaAntrian() {
    int sub;
    cout << "\n--- KELOLA ANTRIAN PASIEN (QUEUE/FIFO) ---\n";
    cout << "  1. Tambah ke Antrian (Enqueue)\n";
    cout << "  2. Layani Pasien (Dequeue)\n";
    cout << "  3. Tampilkan Antrian\n";
    cout << "Pilih: ";
    cin >> sub;
    bersihkanBuffer();

    if (sub == 1) {
        string noRM;
        cout << "Masukkan No RM pasien: ";
        getline(cin, noRM);

        Node* node = linkedList.cari(noRM);
        if (node == nullptr) {
            cout << "[ERROR] Pasien tidak ditemukan.\n";
            return;
        }

        if (!antrian.enqueue(node->data)) {
            cout << "[ERROR] Antrian penuh!\n";
            return;
        }

        node->data.status = "Menunggu";
        cout << "[SUKSES] Pasien '" << node->data.nama << "' masuk antrian.\n";

    } else if (sub == 2) {
        Pasien dilayani;
        if (!antrian.dequeue(dilayani)) {
            cout << "[ERROR] Antrian kosong! Tidak ada pasien yang dilayani.\n";
            return;
        }

        dilayani.status = "Selesai";
        riwayat.push(dilayani);

        Node* node = linkedList.cari(dilayani.noRM);
        if (node != nullptr) node->data.status = "Selesai";
        arrayPasien.update(dilayani.noRM, dilayani);

        cout << "[SUKSES] Pasien '" << dilayani.nama << "' telah dilayani.\n";
        cout << "         Riwayat medis telah dicatat ke Stack.\n";

    } else if (sub == 3) {
        cout << "\nAntrian saat ini (" << antrian.ukuran() << " pasien):\n";
        antrian.tampilkan();
    } else {
        cout << "[ERROR] Pilihan tidak valid.\n";
    }
}

void riwayatMedis() {
    int sub;
    cout << "\n--- RIWAYAT MEDIS (STACK/LIFO) ---\n";
    cout << "  1. Tampilkan Riwayat\n";
    cout << "  2. Ambil Riwayat Terbaru (Pop)\n";
    cout << "Pilih: ";
    cin >> sub;
    bersihkanBuffer();

    if (sub == 1) {
        cout << "\nRiwayat pemeriksaan (" << riwayat.ukuran() << " data):\n";
        riwayat.tampilkan();
    } else if (sub == 2) {
        Pasien p;
        if (!riwayat.pop(p)) {
            cout << "[ERROR] Stack kosong! Tidak ada riwayat.\n";
            return;
        }
        cout << "[INFO] Riwayat terbaru diambil: " << p.nama
             << " (" << p.poli << ")\n";
    } else {
        cout << "[ERROR] Pilihan tidak valid.\n";
    }
}

void statistikPasien() {
    cout << "\n--- STATISTIK PASIEN ---\n";
    cout << "  Total pasien (Linked List) : " << linkedList.hitung() << "\n";
    cout << "  Total pasien (Array)       : " << arrayPasien.getJumlah() << "\n";
    cout << "  Pasien dalam antrian       : " << antrian.ukuran() << "\n";
    cout << "  Riwayat pemeriksaan        : " << riwayat.ukuran() << "\n";
    cout << "  Vertex graph rujukan       : " << graphRujukan.getJumlahVertex() << "\n";
    cout << "  Kapasitas maksimal/bulan   : " << MAX_PASIEN << "\n";
}

void kelolaGraphRujukan() {
    int sub;
    cout << "\n--- GRAPH RUJUKAN POLI (BFS / DFS) ---\n";
    cout << "  1. Tampilkan Jaringan Rujukan\n";
    cout << "  2. Telusuri BFS (Breadth First Search)\n";
    cout << "  3. Telusuri DFS (Depth First Search)\n";
    cout << "  4. Cari Jalur Rujukan Terpendek (BFS)\n";
    cout << "  5. Cek Ada Jalur Rujukan (DFS)\n";
    cout << "Pilih: ";
    cin >> sub;
    bersihkanBuffer();

    if (sub == 1) {
        graphRujukan.tampilkan();
    } else if (sub == 2) {
        string mulai;
        cout << "Poli awal (contoh: Umum): ";
        getline(cin, mulai);
        graphRujukan.bfs(mulai);
    } else if (sub == 3) {
        string mulai;
        cout << "Poli awal (contoh: Umum): ";
        getline(cin, mulai);
        graphRujukan.dfs(mulai);
    } else if (sub == 4) {
        string asal, tujuan;
        cout << "Poli asal   : ";
        getline(cin, asal);
        cout << "Poli tujuan : ";
        getline(cin, tujuan);
        graphRujukan.jalurTerpendek(asal, tujuan);
    } else if (sub == 5) {
        string asal, tujuan;
        cout << "Poli asal   : ";
        getline(cin, asal);
        cout << "Poli tujuan : ";
        getline(cin, tujuan);
        if (graphRujukan.adaJalur(asal, tujuan)) {
            cout << "[SUKSES] Ada jalur rujukan dari '" << asal
                 << "' ke '" << tujuan << "' (DFS).\n";
            cout << "  Kompleksitas DFS: O(V + E)\n";
        } else {
            cout << "[INFO] Tidak ada jalur rujukan dari '" << asal
                 << "' ke '" << tujuan << "'.\n";
        }
    } else {
        cout << "[ERROR] Pilihan tidak valid.\n";
    }
}

KriteriaSort pilihKriteriaSort() {
    int k;
    cout << "Kriteria urut:\n";
    cout << "  1. No RM\n";
    cout << "  2. Nama\n";
    cout << "  3. Umur\n";
    cout << "Pilih: ";
    cin >> k;
    bersihkanBuffer();

    if (k == 2) return BY_NAMA;
    if (k == 3) return BY_UMUR;
    return BY_NORM;
}

void kelolaSorting() {
    int sub;
    cout << "\n--- SORTING DATA PASIEN ---\n";
    cout << "  1. Bubble Sort\n";
    cout << "  2. Selection Sort\n";
    cout << "  3. Insertion Sort\n";
    cout << "  4. Tampilkan Data Array\n";
    cout << "Pilih: ";
    cin >> sub;
    bersihkanBuffer();

    if (sub == 4) {
        cout << "\n--- DATA PASIEN (ARRAY) ---\n";
        arrayPasien.tampilkan();
        return;
    }

    if (sub < 1 || sub > 3) {
        cout << "[ERROR] Pilihan tidak valid.\n";
        return;
    }

    if (arrayPasien.getJumlah() == 0) {
        cout << "[ERROR] Belum ada data pasien untuk diurutkan.\n";
        return;
    }

    KriteriaSort kriteria = pilihKriteriaSort();

    if (sub == 1) bubbleSort(arrayPasien, kriteria);
    else if (sub == 2) selectionSort(arrayPasien, kriteria);
    else insertionSort(arrayPasien, kriteria);

    cout << "\nHasil setelah sorting:\n";
    arrayPasien.tampilkan();
}

void kelolaSearchingBigO() {
    int sub;
    cout << "\n--- SEARCHING & ANALISIS BIG O ---\n";
    cout << "  1. Bandingkan Linear vs Binary Search\n";
    cout << "  2. Tampilkan Analisis Big O Sistem\n";
    cout << "  3. Sort No RM dulu lalu Binary Search\n";
    cout << "Pilih: ";
    cin >> sub;
    bersihkanBuffer();

    if (sub == 1) {
        string noRM;
        cout << "Masukkan No RM yang dicari: ";
        getline(cin, noRM);
        if (noRM.empty()) {
            cout << "[ERROR] No RM tidak boleh kosong!\n";
            return;
        }
        bandingkanPencarian(arrayPasien, noRM);
    } else if (sub == 2) {
        tampilkanAnalisisBigO();
    } else if (sub == 3) {
        if (arrayPasien.getJumlah() == 0) {
            cout << "[ERROR] Belum ada data pasien.\n";
            return;
        }
        cout << "Mengurutkan array berdasarkan No RM (Bubble Sort)...\n";
        bubbleSort(arrayPasien, BY_NORM);

        string noRM;
        cout << "Masukkan No RM yang dicari: ";
        getline(cin, noRM);
        if (noRM.empty()) {
            cout << "[ERROR] No RM tidak boleh kosong!\n";
            return;
        }
        bandingkanPencarian(arrayPasien, noRM);
    } else {
        cout << "[ERROR] Pilihan tidak valid.\n";
    }
}

int main() {
    treePoli.inisialisasi();
    graphRujukan.inisialisasi();

    cout << "Selamat datang di Sistem Klinik E-Health\n";
    cout << "Struktur Poli Klinik:\n";
    treePoli.tampilkan();

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        bersihkanBuffer();

        switch (pilihan) {
            case 1:  tambahPasien(); break;
            case 2:  cariPasien(); break;
            case 3:  updatePasien(); break;
            case 4:  hapusPasien(); break;
            case 5:
                cout << "\n--- DATA PASIEN (LINKED LIST) ---\n";
                linkedList.tampilkan();
                break;
            case 6:
                cout << "\n--- DATA PASIEN (ARRAY) ---\n";
                arrayPasien.tampilkan();
                break;
            case 7:  kelolaAntrian(); break;
            case 8:  riwayatMedis(); break;
            case 9:
                cout << "\n--- STRUKTUR POLI KLINIK (TREE) ---\n";
                treePoli.tampilkan();
                break;
            case 10: statistikPasien(); break;
            case 11: kelolaGraphRujukan(); break;
            case 12: kelolaSorting(); break;
            case 13: kelolaSearchingBigO(); break;
            case 0:
                cout << "\nTerima kasih. Program selesai.\n";
                break;
            default:
                cout << "[ERROR] Menu tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
