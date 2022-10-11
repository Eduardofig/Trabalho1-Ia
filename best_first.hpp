#pragma once

#include <cmath>
#include <queue>
#include "knn_graph.hpp"
#include "search.hpp"

std::pair<std::vector<int>, double> search::best_first(knn_graph &g, int st, int target);

