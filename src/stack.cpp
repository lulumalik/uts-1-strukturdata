#include "../include/stack.h"
#include <iostream>

StackRiwayat::StackRiwayat() : top(-1) {}

bool StackRiwayat::push(const Pasien& p) {
    if (penuh()) return false;
    data[++top] = p;
    return true;
}

bool StackRiwayat::pop(Pasien& p) {
    if (kosong()) return false;
    p = data[top--];
    return true;
}

void StackRiwayat::tampilkan() const {
    if (kosong()) {
        std::cout << "  [Riwayat kosong]\n";
        return;
    }
    for (int i = top; i >= 0; i--) {
        std::cout << "  " << (top - i + 1) << ". " << data[i].noRM << " - "
                  << data[i].nama << " (" << data[i].poli << ") - "
                  << data[i].status << "\n";
    }
}

bool StackRiwayat::kosong() const {
    return top < 0;
}

bool StackRiwayat::penuh() const {
    return top >= MAX_PASIEN - 1;
}

int StackRiwayat::ukuran() const {
    return top + 1;
}
