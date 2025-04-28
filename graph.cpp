#include "graph.h"

Graph::Graph(int n) : n(n), adj(n) {}

void Graph::addEdge(int u, int v, int capacity) {
    adj[u].push_back({v, capacity, (int)adj[v].size()});
    adj[v].push_back({u, 0, (int)adj[u].size() - 1}); // reverse edge with 0 cap
}

std::vector<std::vector<Edge>>& Graph::getAdj() {
    return adj;
}
