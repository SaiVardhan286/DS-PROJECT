#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge {
    int to;
    int capacity;
    int rev; // index of reverse edge
};

class Graph {
public:
    Graph(int n);
    void addEdge(int u, int v, int capacity);
    std::vector<std::vector<Edge>>& getAdj();

private:
    int n;
    std::vector<std::vector<Edge>> adj;
};

#endif // GRAPH_H
