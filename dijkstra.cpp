#include "dijkstra.hpp"

std::pair<std::vector<double>, double> search::dijkstra(knn_graph &g, int st, int target)
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

        walked += walked_increment[curr];

        if(curr == target) {
            break;
        }

        for(auto &[next, weight]: g.edges[curr]) {
            if(dist[next] == -1.0 || dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                walked_increment[next] = weight;

                pq.emplace(dist[next], next);
            }
        }
    }

    return std::make_pair(dist, walked);
}
