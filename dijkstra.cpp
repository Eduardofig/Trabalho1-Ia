#include "dijkstra.hpp"

std::pair<std::vector<int>, double> search::dijkstra(knn_graph &graph, int st, int target)
{
    int n = graph.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<double> dist(n, MAXFLOAT);
    std::vector<double> walked_increment(n, 0.0);
    std::vector<int> par(n, -1);


    pq.emplace(0.0, st);
    dist[st] = 0.0;
    par[st] = st;

    double walked = 0.0;
    while(!pq.empty()) {

        int curr = pq.top().second;
        pq.pop();

        walked += walked_increment[curr];

        if(curr == target) {
            break;
        }

        for(auto &[next, weight]: graph.edges[curr]) {
            if(par[next] == -1) {
                // Custo g(x)
                float g = dist[curr] + weight;
                pq.emplace(g, next);
                walked_increment[next] = weight;
            }

            if(dist[next] > dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                par[next] = curr;
            }
        }
    }

    std::vector<int> path;

    int curr = target;
    path.push_back(target);

    while(curr != st) {
        path.push_back(par[curr]);
        curr = par[curr];
    }

    std::reverse(path.begin(), path.end());

    return std::make_pair(path, walked);
}
