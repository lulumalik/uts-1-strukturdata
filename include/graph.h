#ifndef GRAPH_H
#define GRAPH_H

#include <string>

// Graph: jaringan rujukan antar poli klinik e-health
const int MAX_VERTEX = 10;

class GraphRujukan {
private:
    std::string vertices[MAX_VERTEX];
    bool adj[MAX_VERTEX][MAX_VERTEX];
    int jumlahVertex;

    int indeksVertex(const std::string& nama) const;
    void dfsRekursif(int v, bool dikunjungi[]) const;

public:
    GraphRujukan();

    // bangun graf rujukan poli default
    void inisialisasi();
    // tampilkan daftar vertex dan edge
    void tampilkan() const;
    // BFS: telusuri dari poli awal (level demi level)
    void bfs(const std::string& mulai) const;
    // DFS: telusuri dari poli awal (dalam dulu)
    void dfs(const std::string& mulai) const;
    // BFS: cari jalur rujukan terpendek antar dua poli
    void jalurTerpendek(const std::string& asal, const std::string& tujuan) const;
    // DFS: cek apakah ada jalur rujukan dari asal ke tujuan
    bool adaJalur(const std::string& asal, const std::string& tujuan) const;
    int getJumlahVertex() const;
};

#endif
