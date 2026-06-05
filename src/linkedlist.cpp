#include "../include/linkedlist.h"
#include <iostream>

LinkedListPasien::LinkedListPasien() : head(nullptr) {}

LinkedListPasien::~LinkedListPasien() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedListPasien::tambah(const Pasien& p) {
    Node* baru = new Node;
    baru->data = p;
    baru->next = head;
    head = baru;
}

Node* LinkedListPasien::cari(const std::string& noRM) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.noRM == noRM)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

bool LinkedListPasien::update(const std::string& noRM, const Pasien& pBaru) {
    Node* node = cari(noRM);
    if (node == nullptr) return false;
    node->data = pBaru;
    return true;
}

bool LinkedListPasien::hapus(const std::string& noRM) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data.noRM != noRM) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return false;

    if (prev == nullptr)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    return true;
}

void LinkedListPasien::tampilkan() const {
    if (head == nullptr) {
        std::cout << "  [Linked List kosong]\n";
        return;
    }
    Node* temp = head;
    int no = 1;
    while (temp != nullptr) {
        std::cout << "  " << no++ << ". " << temp->data.noRM << " - "
                  << temp->data.nama << " (" << temp->data.umur << " thn) - "
                  << temp->data.poli << " - " << temp->data.status << "\n";
        temp = temp->next;
    }
}

int LinkedListPasien::hitung() const {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool LinkedListPasien::duplikat(const std::string& noRM) const {
    return cari(noRM) != nullptr;
}
