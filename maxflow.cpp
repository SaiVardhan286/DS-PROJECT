#include "maxflow.h"
#include <queue>
#include <algorithm>

int bfs(Graph& g, int s, int t, std::vector<int>& parent) {
    int n = g.getAdj().size();
    std::fill(parent.begin(), parent.end(), -1);
    std::queue<std::pair<int, int>> q;
    q.push({s, 1e9});
    parent[s] = -2;

    while (!q.empty()) {
        auto [cur, flow] = q.front();
        q.pop();

        for (auto& e : g.getAdj()[cur]) {
            if (parent[e.to] == -1 && e.capacity > 0) {
                parent[e.to] = cur;
                int new_flow = std::min(flow, e.capacity);
                if (e.to == t)
                    return new_flow;
                q.push({e.to, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(Graph& g, int s, int t) {
    int flow = 0;
    std::vector<int> parent(g.getAdj().size());

    int new_flow;
    while ((new_flow = bfs(g, s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            for (auto& e : g.getAdj()[prev]) {
                if (e.to == cur && e.capacity >= new_flow) {
                    e.capacity -= new_flow;
                    g.getAdj()[cur][e.rev].capacity += new_flow;
                    break;
                }
            }
            cur = prev;
        }
    }
    return flow;
}
