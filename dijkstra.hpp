#pragma once

#include "knn_graph.hpp"
#include "search.hpp"
#include "aux.hpp"
#include <cmath>
#include <queue>

std::pair<std::vector<int>, double> search::dijkstra(knn_graph &g, int st, int target);
