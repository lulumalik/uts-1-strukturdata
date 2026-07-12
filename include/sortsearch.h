#ifndef SORTSEARCH_H
#define SORTSEARCH_H

#include "array.h"
#include <string>

// Kriteria pengurutan data pasien
enum KriteriaSort {
    BY_NORM = 1,
    BY_NAMA = 2,
    BY_UMUR = 3
};

// Sorting: mengurutkan data pasien pada Array (in-place)
void bubbleSort(ArrayPasien& arr, KriteriaSort kriteria);
void selectionSort(ArrayPasien& arr, KriteriaSort kriteria);
void insertionSort(ArrayPasien& arr, KriteriaSort kriteria);

// Searching: linear O(n) vs binary O(log n)
bool linearSearch(const ArrayPasien& arr, const std::string& noRM,
                  Pasien& hasil, int& perbandingan);
bool binarySearch(const ArrayPasien& arr, const std::string& noRM,
                  Pasien& hasil, int& perbandingan);

// Bandingkan kedua algoritma pencarian + tampilkan Big O
void bandingkanPencarian(const ArrayPasien& arr, const std::string& noRM);
void tampilkanAnalisisBigO();

#endif
