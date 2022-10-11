#include "astar.hpp"
#include "aux.hpp"

std::pair<std::vector<double>, double> search::best_first(knn_graph &g, int st, int target)
{
    int n = g.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<double> dist(n, -1.0);
    std::vector<double> walked_increment(n, 0.0);

    pq.emplace(0.0, st);
    dist[st] = 0.0;

    double walked = 0.0;
    while(!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();

        walked += walked_increment[curr]

        for(auto &[next, weight]: g.edges[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + weight;
                walked_increment[next] = weight;

                pq.emplace(aux::dist(next, st, g.vertices) + aux::dist(next, target, g.vertices), next);
            }
        }
    }

    return std::make_pair(dist, walked);
}
