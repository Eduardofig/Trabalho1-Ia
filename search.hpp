#pragma once

#include "knn_graph.hpp"

namespace search
{
    std::pair<std::vector<int>, double> dijkstra(knn_graph &graph, int st, int target);
    std::pair<std::vector<int>, double> best_first(knn_graph &graph, int st, int target);
    std::pair<std::vector<int>, double> a_algorithm(knn_graph &graph, int st, int target);
    std::pair<std::vector<int>, double> astar(knn_graph &graph, int st, int target);
    std::pair<std::vector<int>, double> dfs(knn_graph &graph, int st, int target);
    std::pair<std::vector<int>, double> bfs(knn_graph &graph, int st, int target);
}
