#ifndef MAXFLOW_H
#define MAXFLOW_H

#include "graph.h"

int bfs(Graph& g, int s, int t, std::vector<int>& parent);
int edmondsKarp(Graph& g, int s, int t);

#endif // MAXFLOW_H
