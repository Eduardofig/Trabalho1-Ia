#pragma once

#include "knn_graph.hpp"
#include "search.hpp"
#include <cmath>
#include <queue>

std::pair<std::vector<double>, double> search::dijkstra(knn_graph &g, int st, int target);
