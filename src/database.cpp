#include "../include/database.h"
#include "sqlite3.h"
#include <iostream>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif

using namespace std;

static sqlite3* db = nullptr;

static bool pastikanFolderData() {
#ifdef _WIN32
    _mkdir("data");
#else
    mkdir("data", 0755);
#endif
    return true;
}

bool Database::buka(const char* path) {
    pastikanFolderData();

    if (sqlite3_open(path, &db) != SQLITE_OK) {
        cerr << "[DB ERROR] Gagal buka database: " << sqlite3_errmsg(db) << "\n";
        db = nullptr;
        return false;
    }

    const char* sql =
        "CREATE TABLE IF NOT EXISTS pasien ("
        "  no_rm  TEXT PRIMARY KEY,"
        "  nama   TEXT NOT NULL,"
        "  umur   INTEGER NOT NULL,"
        "  poli   TEXT NOT NULL,"
        "  status TEXT NOT NULL"
        ");";

    char* err = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &err) != SQLITE_OK) {
        cerr << "[DB ERROR] Gagal buat tabel: " << err << "\n";
        sqlite3_free(err);
        return false;
    }

    return true;
}

void Database::tutup() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::simpan(const Pasien& p) {
    if (db == nullptr) return false;

    const char* sql =
        "INSERT INTO pasien (no_rm, nama, umur, poli, status) "
        "VALUES (?, ?, ?, ?, ?);";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, p.noRM.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, p.nama.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, p.umur);
    sqlite3_bind_text(stmt, 4, p.poli.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, p.status.c_str(), -1, SQLITE_TRANSIENT);

    bool ok = (sqlite3_step(stmt) == SQLITE_DONE);
    if (!ok) cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
    sqlite3_finalize(stmt);
    return ok;
}

bool Database::update(const Pasien& p) {
    if (db == nullptr) return false;

    const char* sql =
        "UPDATE pasien SET nama = ?, umur = ?, poli = ?, status = ? "
        "WHERE no_rm = ?;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, p.nama.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, p.umur);
    sqlite3_bind_text(stmt, 3, p.poli.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, p.status.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, p.noRM.c_str(), -1, SQLITE_TRANSIENT);

    bool ok = (sqlite3_step(stmt) == SQLITE_DONE);
    if (!ok) cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
    sqlite3_finalize(stmt);
    return ok;
}

bool Database::hapus(const std::string& noRM) {
    if (db == nullptr) return false;

    const char* sql = "DELETE FROM pasien WHERE no_rm = ?;";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    sqlite3_bind_text(stmt, 1, noRM.c_str(), -1, SQLITE_TRANSIENT);
    bool ok = (sqlite3_step(stmt) == SQLITE_DONE);
    if (!ok) cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
    sqlite3_finalize(stmt);
    return ok;
}

bool Database::muatSemua(std::vector<Pasien>& hasil) {
    hasil.clear();
    if (db == nullptr) return false;

    const char* sql =
        "SELECT no_rm, nama, umur, poli, status FROM pasien ORDER BY rowid;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "[DB ERROR] " << sqlite3_errmsg(db) << "\n";
        return false;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Pasien p;
        p.noRM = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        p.nama = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        p.umur = sqlite3_column_int(stmt, 2);
        p.poli = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        p.status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        hasil.push_back(p);
    }

    sqlite3_finalize(stmt);
    return true;
}
