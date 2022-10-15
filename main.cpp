#include "search.hpp"
#include "dfs.hpp"
#include "aux.hpp"
#include <iostream>

int main()
{
    knn_graph g;
    g.gen_vertices(10);
    g.gen_edges(5);

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }
    std::cout << "\nGraph:\n";
    g.print_graph();

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
    g.print_edges();

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nDfs:\n";
    const auto &[dfs_path, dfs_walked] = search::dfs(g, 0, 5);
    aux::print_path(dfs_path);
    std::cout << "Walked: " << dfs_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nDijkstra:\n";
    const auto &[dijk_path, dijk_walked] = search::dijkstra(g, 0, 5);
    aux::print_path(dijk_path);
    std::cout << "Walked: " << dijk_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nBest First:\n";
    const auto &[best_first_path, best_first_walked] = search::best_first(g, 0, 5);
    aux::print_path(best_first_path);
    std::cout << "Walked: " << best_first_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nA*:\n";
    const auto &[astar_path, astar_walked] = search::astar(g, 0, 5);
    aux::print_path(astar_path);
    std::cout << "Walked: " << astar_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }
}
