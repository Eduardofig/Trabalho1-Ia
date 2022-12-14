#include <iostream>
#include <cstdlib>
#include <set>
#include <math.h>

#include "knn_graph.hpp"
#include "aux.hpp"

void knn_graph::gen_vertices(int n)
{
    this->vertices.clear();
    std::set<std::pair<int, int>> used;

    int m = 0;
    while(this->vertices.size() < n) {
        std::pair<int, int> pos = std::make_pair(std::rand() % n, std::rand() % n);

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

    int n = this->vertices.size();
    this->edges.resize(n);

    for(int from = 0; from < n; ++from) {
        this->edges[from].clear();

        // Each node has k bidirectional edges
        while(this->edges[from].size() < k) {
            int to = std::rand() % n;

            if(from != to) {
                const double weight = aux::dist(from, to, this->vertices);

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

knn_graph::knn_graph()
{

}

void knn_graph::print_graph()
{
    int n = this->vertices.size();
    for(int i = 0; i < n; ++i) {
        auto &[x, y] = this->vertices[i];
        std::cout << "Node: " << i + 1 << ", Point: (x: " << x << "," << " y: " << y << ")" << '\n';
    }
}

void knn_graph::print_edges()
{
    int n = this->vertices.size();
    std::cout << "Edges: \n";
    for(int from = 0; from < n; ++from) {
        for(auto &[to, weight]: this->edges[from]) {
            std::cout << (from + 1) << "----->" << (to + 1) << " weight: " << weight << '\n';
        }
    }
}
