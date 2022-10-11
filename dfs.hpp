#pragma once

#include "search.hpp"

std::pair<std::vector<double>, double> dfs(knn_graph &g, int st, int target);
