#pragma once

#include "knn_graph.hpp"
#include "search.hpp"
#include "aux.hpp"
#include <cmath>
#include <queue>

std::pair<std::vector<int>, double> search::bfs(knn_graph &graph, int st, int target);
