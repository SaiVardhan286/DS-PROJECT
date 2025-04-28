#include "graph.h"
#include "maxflow.h"
#include <vector>
#include <iostream>
#include <cmath>

void runAlgorithm1(Graph& g, int n) {
    std::cout << "\nRunning Algorithm-1 (Exact)...\n";

    double l = 0, r = 1.0 * n;
    double best_density = 0;
    std::vector<int> best_subgraph;

    for (int iter = 0; iter < 40; ++iter) {
        double mid = (l + r) / 2.0;
        int s = n;
        int t = n + 1;
        Graph flowG(n + 2);

        for (int u = 0; u < n; ++u) {
            flowG.addEdge(s, u, g.getAdj()[u].size());
            flowG.addEdge(u, t, (int)std::round(mid * 2));
        }

        for (int u = 0; u < n; ++u) {
            for (auto& e : g.getAdj()[u]) {
                if (u < e.to) {
                    flowG.addEdge(u, e.to, 1);
                    flowG.addEdge(e.to, u, 1);
                }
            }
        }

        int flow = edmondsKarp(flowG, s, t);

        std::vector<bool> visited(n+2, false);
        std::queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : flowG.getAdj()[v]) {
                if (e.capacity > 0 && !visited[e.to]) {
                    visited[e.to] = true;
                    q.push(e.to);
                }
            }
        }

        std::vector<int> subgraph;
        for (int u = 0; u < n; ++u) {
            if (visited[u])
                subgraph.push_back(u);
        }

        if (subgraph.size() > 0) {
            l = mid;
            best_density = mid;
            best_subgraph = subgraph;
        } else {
            r = mid;
        }
    }

    std::cout << "Best Density Found: " << best_density << std::endl;
    std::cout << "Subgraph Vertices: ";
    for (auto v : best_subgraph) std::cout << v << " ";
    std::cout << std::endl;
}
