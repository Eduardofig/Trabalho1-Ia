#pragma once

#include "knn_graph.hpp"

namespace search
{
    std::pair<std::vector<double>, double> dijkstra(knn_graph &g, int st, int target);
    std::pair<std::vector<double>, double> best_first(knn_graph &g, int st, int target);
    std::pair<std::vector<double>, double> a_algorithim(knn_graph &g, int st);
    std::pair<std::vector<double>, double> astar(knn_graph &g, int st, int target);
    std::pair<std::vector<double>, double> dfs(knn_graph &g, int st, int target);
}
