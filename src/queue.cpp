#include "../include/queue.h"
#include <iostream>

QueueAntrian::QueueAntrian() : front(0), rear(0) {}

bool QueueAntrian::enqueue(const Pasien& p) {
    if (penuh()) return false;
    data[rear++] = p;
    return true;
}

bool QueueAntrian::dequeue(Pasien& p) {
    if (kosong()) return false;

    p = data[front];

    for (int i = 0; i < rear - 1; i++) {
        data[i] = data[i + 1];
    }
    rear--;
    return true;
}

void QueueAntrian::tampilkan() const {
    if (kosong()) {
        std::cout << "  [Antrian kosong]\n";
        return;
    }
    for (int i = front; i < rear; i++) {
        std::cout << "  " << (i - front + 1) << ". " << data[i].noRM << " - "
                  << data[i].nama << " (" << data[i].poli << ")\n";
    }
}

bool QueueAntrian::kosong() const {
    return front == rear;
}

bool QueueAntrian::penuh() const {
    return rear >= MAX_PASIEN;
}

int QueueAntrian::ukuran() const {
    return rear - front;
}
