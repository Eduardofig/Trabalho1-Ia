#include "search.hpp"
#include "a_algorithim.hpp"
#include "aux.hpp"

std::pair<std::vector<int>, double> search::a_algorithm(knn_graph &graph, int st, int target)
{
    int n = graph.vertices.size();
    std::priority_queue<
        std::pair<double, int>,
        std::vector<std::pair<double, int>>,
        std::greater<std::pair<double, int>>
    > pq;

    std::vector<double> dist(n, MAXFLOAT);
    std::vector<int> par(n, -1);

    dist[st] = 0.0;
    pq.emplace(0.0, st);
    par[st] = st;

    double walked = 0.0;
    while(!pq.empty()) {

        int curr = pq.top().second;
        pq.pop();

        walked += 1;

        if(curr == target) {
            break;
        }

        for(auto &[next, weight]: graph.edges[curr]) {
            if(par[next] == -1) {
                par[next] = curr;
                dist[next] = dist[curr] + weight;

                // Custo g(x)
                double g = dist[next];
                // Heuristica h(x)
                double h = aux::dist(next, target, graph.vertices);

                // Evaluation function f(x) = g(x) + h(x)
                double f = g + h;
                pq.emplace(f, next);
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
