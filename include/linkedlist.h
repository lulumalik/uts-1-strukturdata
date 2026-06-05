#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "types.h"

// Linked List: penyimpanan data pasien dinamis
struct Node {
    Pasien data;
    Node* next;
};

class LinkedListPasien {
private:
    Node* head;

public:
    LinkedListPasien();
    // fungsi untuk menghapus data pasien
    ~LinkedListPasien();

    void tambah(const Pasien& p);
    // fungsi untuk mencari data pasien
    Node* cari(const std::string& noRM) const;
    bool update(const std::string& noRM, const Pasien& pBaru);
    // fungsi untuk menghapus data pasien
    bool hapus(const std::string& noRM);
    void tampilkan() const;
    // fungsi untuk menghitung jumlah data pasien
    int hitung() const;
    // fungsi untuk memeriksa duplikasi data pasien
    bool duplikat(const std::string& noRM) const;
};

#endif
