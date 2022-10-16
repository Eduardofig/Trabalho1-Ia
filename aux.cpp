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

    if(dfs_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double dfs_dist = aux::get_path_distance(graph, dfs_path);
        aux::print_path(dfs_path);
        std::cout << "Distance: " << dfs_dist << '\n';
        std::cout << "Walked: " << dfs_walked << '\n';
    }

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nBfs:\n";
    const auto &[bfs_path, bfs_walked] = search::bfs(graph, st, target);

    if(bfs_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double bfs_dist = aux::get_path_distance(graph, bfs_path);
        aux::print_path(bfs_path);
        std::cout << "Distance: " << bfs_dist << '\n';
        std::cout << "Walked: " << bfs_walked << '\n';
    }

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nDijkstra:\n";
    const auto &[dijk_path, dijk_walked] = search::dijkstra(graph, st, target);

    if(dijk_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double dijk_dist = aux::get_path_distance(graph, dijk_path);
        aux::print_path(dijk_path);
        std::cout << "Distance: " << dijk_dist << '\n';
        std::cout << "Walked: " << dijk_walked << '\n';
    }

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nBest First:\n";
    const auto &[best_first_path, best_first_walked] = search::best_first(graph, st, target);

    if(best_first_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double best_first_dist = aux::get_path_distance(graph, best_first_path);
        aux::print_path(best_first_path);
        std::cout << "Distance: " << best_first_dist << '\n';
        std::cout << "Walked: " << best_first_walked << '\n';
    }

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nA:\n";
    const auto &[a_path, a_walked] = search::a_algorithm(graph, st, target);

    if(a_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double a_dist = aux::get_path_distance(graph, a_path);
        aux::print_path(a_path);
        std::cout << "Distance: " << a_dist << '\n';
        std::cout << "Walked: " << a_walked << '\n';
    }

    for(int i = 0; i < 100; ++i) {
        std::cout << '-';
    }

    std::cout << "\nA*:\n";
    const auto &[astar_path, astar_walked] = search::astar(graph, st, target);

    if(astar_path.front() == -1) {
        std::cout << " Node " << (target + 1) << " is not reachable from  Node " << (st + 1) << '\n';
    } else {
        const double astar_dist = aux::get_path_distance(graph, astar_path);
        aux::print_path(astar_path);
        std::cout << "Distance: " << astar_dist << '\n';
        std::cout << "Walked: " << astar_walked << '\n';
    }

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

double aux::get_path_distance(knn_graph &graph, const std::vector<int> &path)
{
    double dist = 0;

    int n = path.size();
    for(int i = 0; i < n - 1; ++i) {
        int from = path[i];
        int to = path[i + 1];

        dist += aux::dist(from, to, graph.vertices);
    }

    return dist;
}
std::pair<double, double> aux::get_avg_time_dist(knn_graph &graph, int num_experiments,
        std::pair<std::vector<int>, double> (*search_function)(knn_graph&, int, int))
{
    using namespace std::chrono;

    std::set<std::pair<int, int>> used;

    int n = graph.edges.size();

    long double avg_time = 0.0, avg_dist = 0.0;
    for(int i = 0; i < num_experiments; ++i) {
        int st = rand() % n;
        int target = rand() % n;

        std::pair<int, int> p = std::make_pair(st, target);

        if(used.find(p) == used.end()) {
            auto start = high_resolution_clock::now();

            auto [path, walked] = search_function(graph, st, target);

            auto stop = high_resolution_clock::now();

            long double time = (long double)duration_cast<microseconds>(stop - start).count();

            if(path.front() != -1) {
                avg_time += time / (long double) num_experiments;
                avg_dist += (long double) walked / (long double) num_experiments;
            }

            used.insert(p);
        }
    }

    return std::make_pair(avg_time, avg_dist);
}
