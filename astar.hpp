#pragma once

#include <cmath>
#include <queue>
#include "knn_graph.hpp"
#include "search.hpp"

std::pair<std::vector<double>, double> search::astar(knn_graph &g, int st, int target);
