#include "dfs.hpp"

void recurse_dfs(knn_graph &g, const int curr, const int target, std::vector<double> &dist,
        std::vector<double> &walked_increment, double &walked)
{
    walked += walked_increment[curr];

    for(auto &[next, weight]: g.edges[curr]) {
        if(dist[next] == -1.0) {
            dist[next] = dist[curr] + weight;
            walked_increment[next] = weight;

            recurse_dfs(g, next, target, dist, walked_increment, walked);
        }
    }
}

std::pair<std::vector<double>, double> search::dfs(knn_graph &g, int st, int target)
{
    int n = g.vertices.size();
    std::vector<double> dist(n, -1.0);
    std::vector<double> walked_increment(n, 0.0);

    double walked = 0.0;

    recurse_dfs(g, st, target, dist, walked_increment, walked);

    return std::make_pair(dist, walked);
}
