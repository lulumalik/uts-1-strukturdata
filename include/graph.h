#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    static const int MAX = 10;
    std::vector<int> adj[MAX];

public:
    Graph();

    void tambahEdge(int u, int v);
    void tampilGraph();
    void BFS(int start);
    void DFS(int start);

private:
    void DFSUtil(int node, bool visited[]);
};

#endif