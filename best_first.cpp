#include "best_first.hpp"

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

    const auto &vref = g.vertices;
    const auto dist_to_target = [vref, target](const int from) {

        const int x1 = vref[from].first, y1 = vref[from].second;
        const int x2 = vref[target].first, y2 = vref[target].second;

        const double delta_x = x2 - x1;
        const double delta_y = y2 - y1;

        return sqrt(delta_x * delta_x + delta_y * delta_y);
    };

    while(!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();

        for(auto &[next, weight]: g.edges[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + weight;
                pq.emplace(dist_to_target(next), next);
            }
        }
    }

    return dist;


}
