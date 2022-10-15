#include "search.hpp"
#include "dfs.hpp"
#include "aux.hpp"
#include <iostream>

int main()
{
    knn_graph graph(20, 1);
    aux::print_graph(graph);
    aux::run_experiment(graph, 1, 17);
}
