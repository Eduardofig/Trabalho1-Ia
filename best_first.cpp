#include "best_first.hpp"
#include "aux.hpp"

std::pair<std::vector<int>, double> search::best_first(knn_graph &graph, int st, int target)
{
    int n = graph.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<int> par(n, -1);

    pq.emplace(0.0, st);
    par[st] = st;

    double walked = 0.0;
    while(!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        walked += 1.0;

        if(curr == target) {
            break;
        }

        for(auto &[next, weight]: graph.edges[curr]) {
            if(par[next] == -1) {
                par[next] = curr;
                // Heuristica h(x)
                float h = aux::dist(next, target, graph.vertices);
                pq.emplace(h, next);
            }
        }
    }

    std::vector<int> path;

    int curr = target;
    path.push_back(target);

    while(curr != st) {
        if(curr == -1) {
            break;
        }
        path.push_back(par[curr]);
        curr = par[curr];
    }

    std::reverse(path.begin(), path.end());

    return std::make_pair(path, walked);
}
