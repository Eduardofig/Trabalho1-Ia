#include "search.hpp"
#include "dfs.hpp"
#include "aux.hpp"
#include <iostream>

int main()
{
    knn_graph graph;
    graph.gen_vertices(10);
    graph.gen_edges(5);

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }
    std::cout << "\nGraph:\n";
    graph.print_graph();

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
    graph.print_edges();

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    aux::run_experiment(graph, 0, 5);
}
