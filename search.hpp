#pragma once

#include "knn_graph.hpp"

namespace search
{
    std::pair<std::vector<int>, double> dijkstra(knn_graph &g, int st, int target);
    std::pair<std::vector<int>, double> best_first(knn_graph &g, int st, int target);
    std::pair<std::vector<int>, double> a_algorithim(knn_graph &g, int st);
    std::pair<std::vector<int>, double> astar(knn_graph &g, int st, int target);
    std::pair<std::vector<int>, double> dfs(knn_graph &g, int st, int target);
}
