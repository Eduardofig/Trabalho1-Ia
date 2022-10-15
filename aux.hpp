#pragma once

#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

namespace aux
{
    double dist(const int from, const int to, const std::vector<std::pair<int, int>> &vertices);
    void print_path(const std::vector<int> &path);
}
