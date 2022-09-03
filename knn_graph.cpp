#include <iostream>
#include <cstdlib>
#include <set>
#include <math.h>

#include "knn_graph.hpp"

void knn_graph::gen_vertices(int n)
{
    this->vertices.clear();
    std::set<std::pair<int, int>> used;

    int m = 0;
    while(this->vertices.size() < n) {
        std::pair<int, int> pos = {std::rand() % n, std::rand() % n};

        if(used.find(pos) == used.end()) {
            used.insert(pos);
            this->vertices.push_back(pos);
        }
    }
}

void knn_graph::gen_edges(int k)
{
    if(this->vertices.empty()) {
        std::cerr << "Can't generate edges for empty graph\n";
        return;
    }

    std::set<std::pair<int, int>> used;

    const auto &vref = this->vertices;
    const auto dist = [vref](const int from, const int to) {
        const int x1 = vref[from].first, y1 = vref[from].second;
        const int x2 = vref[to].first, y2 = vref[to].second;

        const double delta_x = x2 - x1;
        const double delta_y = y2 - y1;

        return sqrt(delta_x * delta_x + delta_y * delta_y);
    };

    int n = this->vertices.size();
    for(int from = 0; from < n; ++from) {
        this->edges[from].clear();
        while(this->edges[from].size() < k) {
            int to = std::rand() % n;

            if(used.find({from, to}) == used.end()) {
                used.insert({from, to});
                used.insert({to, from});

                const double weight = dist(from, to);

                this->edges[from].emplace_back(to, weight);
                this->edges[to].emplace_back(from, weight);
            }
        }
    }
}


knn_graph::knn_graph(int n, int k)
{
    this->gen_vertices(n);
    this->gen_edges(k);
}
