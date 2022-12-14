#include "bfs.hpp"

std::pair<std::vector<int>, double> search::bfs(knn_graph &graph, int st, int target)
{
    int n = graph.edges.size();
    std::queue<int> q;

    q.push(st);

    std::vector<int> par(n, -1);

    par[st] = st;

    double walked = 0.0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        walked += 1.0;

        for(auto &[next, weight]: graph.edges[curr]) {
            if(par[next] == -1) {
                par[next] = curr;
                q.push(next);
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
