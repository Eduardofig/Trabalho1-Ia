#pragma once

#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <set>
#include <chrono>
#include "search.hpp"

namespace aux
{
    double dist(const int from, const int to, const std::vector<std::pair<int, int>> &vertices);
    void print_path(const std::vector<int> &path);
    void run_experiment(knn_graph &graph, int st, int target);
    void print_graph(knn_graph &graph);
    double get_path_distance(knn_graph &graph, const std::vector<int> &path);
    std::pair<double, double> get_avg_time_dist(knn_graph &graph, int num_experiments,
            std::pair<std::vector<int>, double> (*search_function)(knn_graph&, int, int));
}
