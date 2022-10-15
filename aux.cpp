#include "aux.hpp"

double aux::dist(const int from, const int to, const std::vector<std::pair<int, int>> &vertices)
{
    const int x1 = vertices[from].first, y1 = vertices[from].second;
    const int x2 = vertices[to].first, y2 = vertices[to].second;

    const double delta_x = x2 - x1;
    const double delta_y = y2 - y1;

    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

void aux::print_path(const std::vector<int> &path)
{
    int n = path.size();
    std::cout << "Path: ";
    for(int i = 0; i < n; ++i) {
        std::cout << (path[i] + 1);
        if(i != n - 1) {
            std::cout << "->";
        }
    }
    std::cout << '\n';
}

void aux::run_experiment(knn_graph &graph, int st, int target)
{
    int n = graph.vertices.size();

    std::cout << "\n Running experiment starting from node " << st << " and ending at node " << target << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    --st;
    --target;

    if(target > n) {
        std::cerr << "Cannot react target from st\n";
    }

    std::cout << "\nDfs:\n";
    const auto &[dfs_path, dfs_walked] = search::dfs(graph, st, target);
    aux::print_path(dfs_path);
    std::cout << "Walked: " << dfs_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nDijkstra:\n";
    const auto &[dijk_path, dijk_walked] = search::dijkstra(graph, st, target);
    aux::print_path(dijk_path);
    std::cout << "Walked: " << dijk_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nBest First:\n";
    const auto &[best_first_path, best_first_walked] = search::best_first(graph, st, target);
    aux::print_path(best_first_path);
    std::cout << "Walked: " << best_first_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nA*:\n";
    const auto &[astar_path, astar_walked] = search::astar(graph, st, target);
    aux::print_path(astar_path);
    std::cout << "Walked: " << astar_walked << '\n';

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

}

void aux::print_graph(knn_graph &graph)
{
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
}
