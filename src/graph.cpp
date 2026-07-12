#include "../include/graph.h"
#include <iostream>
#include <queue>
#include <stack>

GraphRujukan::GraphRujukan() : jumlahVertex(0) {
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++)
            adj[i][j] = false;
    }
}

int GraphRujukan::indeksVertex(const std::string& nama) const {
    for (int i = 0; i < jumlahVertex; i++) {
        if (vertices[i] == nama || vertices[i].find(nama) != std::string::npos)
            return i;
    }
    return -1;
}

void GraphRujukan::inisialisasi() {
    // Vertex: unit layanan klinik e-health
    vertices[0] = "Umum";
    vertices[1] = "Gigi";
    vertices[2] = "Anak";
    vertices[3] = "Penyakit Dalam";
    vertices[4] = "Lab";
    vertices[5] = "Apotek";
    jumlahVertex = 6;

    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            adj[i][j] = false;

    // Edge: jalur rujukan antar unit (directed)
    // Umum dapat merujuk ke spesialis
    adj[0][1] = true; // Umum -> Gigi
    adj[0][2] = true; // Umum -> Anak
    adj[0][3] = true; // Umum -> Penyakit Dalam
    adj[0][4] = true; // Umum -> Lab
    adj[0][5] = true; // Umum -> Apotek

    // Spesialis dapat merujuk balik / lintas
    adj[1][0] = true; // Gigi -> Umum
    adj[1][5] = true; // Gigi -> Apotek

    adj[2][0] = true; // Anak -> Umum
    adj[2][3] = true; // Anak -> Penyakit Dalam
    adj[2][4] = true; // Anak -> Lab
    adj[2][5] = true; // Anak -> Apotek

    adj[3][0] = true; // Penyakit Dalam -> Umum
    adj[3][4] = true; // Penyakit Dalam -> Lab
    adj[3][5] = true; // Penyakit Dalam -> Apotek

    adj[4][0] = true; // Lab -> Umum
    adj[4][5] = true; // Lab -> Apotek
}

void GraphRujukan::tampilkan() const {
    std::cout << "\nJaringan Rujukan Poli (Graph):\n";
    std::cout << "  Vertex (" << jumlahVertex << "):\n";
    for (int i = 0; i < jumlahVertex; i++)
        std::cout << "    [" << i << "] " << vertices[i] << "\n";

    std::cout << "  Edge (arah rujukan):\n";
    bool adaEdge = false;
    for (int i = 0; i < jumlahVertex; i++) {
        for (int j = 0; j < jumlahVertex; j++) {
            if (adj[i][j]) {
                std::cout << "    " << vertices[i] << " -> " << vertices[j] << "\n";
                adaEdge = true;
            }
        }
    }
    if (!adaEdge)
        std::cout << "    [Tidak ada edge]\n";
}

void GraphRujukan::bfs(const std::string& mulai) const {
    int start = indeksVertex(mulai);
    if (start < 0) {
        std::cout << "[ERROR] Poli '" << mulai << "' tidak ditemukan di graph.\n";
        std::cout << "Vertex tersedia: Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek\n";
        return;
    }

    bool dikunjungi[MAX_VERTEX] = {false};
    std::queue<int> q;

    dikunjungi[start] = true;
    q.push(start);

    std::cout << "\nHasil BFS dari '" << vertices[start] << "' (Big O: O(V+E)):\n  ";
    bool pertama = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!pertama) std::cout << " -> ";
        std::cout << vertices[v];
        pertama = false;

        for (int i = 0; i < jumlahVertex; i++) {
            if (adj[v][i] && !dikunjungi[i]) {
                dikunjungi[i] = true;
                q.push(i);
            }
        }
    }
    std::cout << "\n";
}

void GraphRujukan::dfsRekursif(int v, bool dikunjungi[]) const {
    dikunjungi[v] = true;
    std::cout << vertices[v];

    bool pertama = true;
    for (int i = 0; i < jumlahVertex; i++) {
        if (adj[v][i] && !dikunjungi[i]) {
            if (pertama) {
                std::cout << " -> ";
                pertama = false;
            } else {
                std::cout << " -> ";
            }
            dfsRekursif(i, dikunjungi);
        }
    }
}

void GraphRujukan::dfs(const std::string& mulai) const {
    int start = indeksVertex(mulai);
    if (start < 0) {
        std::cout << "[ERROR] Poli '" << mulai << "' tidak ditemukan di graph.\n";
        std::cout << "Vertex tersedia: Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek\n";
        return;
    }

    bool dikunjungi[MAX_VERTEX] = {false};
    std::cout << "\nHasil DFS dari '" << vertices[start] << "' (Big O: O(V+E)):\n  ";
    dfsRekursif(start, dikunjungi);
    std::cout << "\n";
}

void GraphRujukan::jalurTerpendek(const std::string& asal, const std::string& tujuan) const {
    int start = indeksVertex(asal);
    int end = indeksVertex(tujuan);

    if (start < 0 || end < 0) {
        std::cout << "[ERROR] Nama poli tidak valid.\n";
        std::cout << "Vertex tersedia: Umum, Gigi, Anak, Penyakit Dalam, Lab, Apotek\n";
        return;
    }

    if (start == end) {
        std::cout << "[INFO] Asal dan tujuan sama: " << vertices[start] << "\n";
        return;
    }

    bool dikunjungi[MAX_VERTEX] = {false};
    int parent[MAX_VERTEX];
    for (int i = 0; i < MAX_VERTEX; i++)
        parent[i] = -1;

    std::queue<int> q;
    dikunjungi[start] = true;
    q.push(start);

    bool ketemu = false;
    while (!q.empty() && !ketemu) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < jumlahVertex; i++) {
            if (adj[v][i] && !dikunjungi[i]) {
                dikunjungi[i] = true;
                parent[i] = v;
                q.push(i);
                if (i == end) {
                    ketemu = true;
                    break;
                }
            }
        }
    }

    if (!ketemu) {
        std::cout << "[INFO] Tidak ada jalur rujukan dari '"
                  << vertices[start] << "' ke '" << vertices[end] << "'.\n";
        return;
    }

    // Rekonstruksi jalur dari parent
    int jalur[MAX_VERTEX];
    int panjang = 0;
    for (int v = end; v != -1; v = parent[v])
        jalur[panjang++] = v;

    std::cout << "\nJalur rujukan terpendek (BFS) dari '"
              << vertices[start] << "' ke '" << vertices[end] << "':\n  ";
    for (int i = panjang - 1; i >= 0; i--) {
        std::cout << vertices[jalur[i]];
        if (i > 0) std::cout << " -> ";
    }
    std::cout << "\n  Jumlah langkah rujukan: " << (panjang - 1) << "\n";
    std::cout << "  Kompleksitas BFS: O(V + E)\n";
}

bool GraphRujukan::adaJalur(const std::string& asal, const std::string& tujuan) const {
    int start = indeksVertex(asal);
    int end = indeksVertex(tujuan);

    if (start < 0 || end < 0) {
        std::cout << "[ERROR] Nama poli tidak valid.\n";
        return false;
    }
    if (start == end) return true;

    bool dikunjungi[MAX_VERTEX] = {false};
    std::stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (dikunjungi[v]) continue;
        dikunjungi[v] = true;

        if (v == end) return true;

        for (int i = jumlahVertex - 1; i >= 0; i--) {
            if (adj[v][i] && !dikunjungi[i])
                st.push(i);
        }
    }
    return false;
}

int GraphRujukan::getJumlahVertex() const {
    return jumlahVertex;
}
