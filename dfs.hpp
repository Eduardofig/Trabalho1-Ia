#pragma once

#include "search.hpp"
#include "aux.hpp"

std::pair<std::vector<double>, double> dfs(knn_graph &graph, int st, int target);
