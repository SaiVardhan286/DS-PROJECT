#include "graph.h"
#include "maxflow.h"
#include <vector>
#include <iostream>
#include <algorithm>

void runAlgorithm4(Graph& g, int n) {
    std::cout << "\nRunning Algorithm-4 (CoreExact)...\n";

    // k-core pruning
    std::vector<int> degree(n);
    for (int u = 0; u < n; ++u) {
        degree[u] = g.getAdj()[u].size();
    }

    double l = 0, r = 1.0 * n;
    double best_density = 0;
    std::vector<int> best_subgraph;

    for (int iter = 0; iter < 40; ++iter) {
        double mid = (l + r) / 2.0;
        std::vector<bool> alive(n, true);
        bool changed = true;
        while (changed) {
            changed = false;
            for (int u = 0; u < n; ++u) {
                if (alive[u] && degree[u] < mid) {
                    alive[u] = false;
                    changed = true;
                    for (auto& e : g.getAdj()[u]) {
                        degree[e.to]--;
                    }
                }
            }
        }

        std::vector<int> subgraph;
        for (int u = 0; u < n; ++u) {
            if (alive[u])
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
