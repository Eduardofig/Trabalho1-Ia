#pragma once

#include <cmath>
#include <queue>
#include "knn_graph.hpp"
#include "search.hpp"

std::pair<std::vector<int>, double> search::a_algorithm(knn_graph &graph, int st, int target);
