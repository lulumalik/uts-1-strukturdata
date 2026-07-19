#include "../include/graph.h"
#include <iostream>
#include <queue>

using namespace std;

// Constructor
Graph::Graph() {
    // Tidak ada inisialisasi khusus
}

// Menambahkan hubungan antar poli (edge)
void Graph::tambahEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);   // Graph tidak berarah
}

// Menampilkan graph
void Graph::tampilGraph() {
    cout << "\n===== HUBUNGAN ANTAR POLI =====\n";

    const string namaPoli[MAX] = {
        "Poli Umum",
        "Poli Gigi",
        "Poli Anak",
        "Poli Penyakit Dalam"
    };

    for (int i = 0; i < 4; i++) {
        cout << namaPoli[i] << " -> ";

        for (int j : adj[i]) {
            cout << namaPoli[j] << " ";
        }

        cout << endl;
    }
}

// Breadth First Search
void Graph::BFS(int start) {

    bool visited[MAX] = {false};
    queue<int> q;

    const string namaPoli[MAX] = {
        "Poli Umum",
        "Poli Gigi",
        "Poli Anak",
        "Poli Penyakit Dalam"
    };

    visited[start] = true;
    q.push(start);

    cout << "\n===== BFS =====\n";

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << namaPoli[node] << endl;

        for (int next : adj[node]) {

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }

        }

    }

}

// Fungsi bantu DFS
void Graph::DFSUtil(int node, bool visited[]) {

    const string namaPoli[MAX] = {
        "Poli Umum",
        "Poli Gigi",
        "Poli Anak",
        "Poli Penyakit Dalam"
    };

    visited[node] = true;

    cout << namaPoli[node] << endl;

    for (int next : adj[node]) {

        if (!visited[next]) {
            DFSUtil(next, visited);
        }

    }

}

// Depth First Search
void Graph::DFS(int start) {

    bool visited[MAX] = {false};

    cout << "\n===== DFS =====\n";

    DFSUtil(start, visited);

}