#include "a_algorithim.hpp"
#include "aux.hpp"

std::vector<double> best_first(knn_graph &g, int st, int target)
{
    int n = g.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<double> dist(n, -1);

    pq.emplace(0.0, st);
    dist[st] = 0.0;

    while(!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();

        for(auto &[next, weight]: g.edges[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + weight;
                pq.emplace(aux::dist(next, st, g.vertices), next);
            }
        }
    }

    return dist;


}
