#include "search.hpp"
#include "dfs.hpp"
#include "aux.hpp"
#include <iostream>

int main()
{
    knn_graph graph(30, 2);
    aux::print_graph(graph);
    aux::run_experiment(graph, 1, 30);

    auto [dfs_avg_time, dfs_avg_dist] = aux::get_avg_time_dist(graph, 20, search::dfs);

    std::cout << "\nDfs:\n";
    std::cout << "Average time : " << dfs_avg_time << " microseconds " << '\n';
    std::cout << "Average distance walked: " << dfs_avg_dist << '\n';

}
