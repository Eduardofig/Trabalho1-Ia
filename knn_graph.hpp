#pragma once

#include <utility>
#include <vector>

class knn_graph
{
    public:
        std::vector<std::pair<int, int>> vertices;
        std::vector<std::vector<std::pair<int, double>>> edges;

        void gen_vertices(int n);
        void gen_edges(int k);

        knn_graph(int n, int k);
};
