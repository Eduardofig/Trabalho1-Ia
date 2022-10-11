#include "astar.hpp"
#include "aux.hpp"

std::pair<std::vector<int>, double> search::best_first(knn_graph &g, int st, int target)
{
    int n = g.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<double> dist(n, -1.0);
    std::vector<double> walked_increment(n, 0.0);
    std::vector<int> par(n, -1.0);

    pq.emplace(0.0, st);
    dist[st] = 0.0;
    par[st] = st;

    double walked = 0.0;
    while(!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();

        if(curr == target) {
            break;
        }

        walked += walked_increment[curr]

        for(auto &[next, weight]: g.edges[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + weight;
                walked_increment[next] = weight;
                par[next] = curr;

                pq.emplace(aux::dist(next, st, g.vertices) + aux::dist(next, target, g.vertices), next);
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
};
