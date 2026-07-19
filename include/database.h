#ifndef DATABASE_H
#define DATABASE_H

#include "types.h"
#include <vector>

// Persistensi data pasien ke SQLite (file lokal data/klinik.db)
class Database {
public:
    static bool buka(const char* path = "data/klinik.db");
    static void tutup();
    static bool simpan(const Pasien& p);
    static bool update(const Pasien& p);
    static bool hapus(const std::string& noRM);
    static bool muatSemua(std::vector<Pasien>& hasil);
};

#endif
