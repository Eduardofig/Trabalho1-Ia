#pragma once

#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include "search.hpp"

namespace aux
{
    double dist(const int from, const int to, const std::vector<std::pair<int, int>> &vertices);
    void print_path(const std::vector<int> &path);
    void run_experiment(knn_graph &g, int st, int target);
}
