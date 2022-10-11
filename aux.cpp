#include "aux.hpp"

namespace aux
{
    double dist(const int from, const int to, const std::vector<std::pair<int, int>> &vertices)
    {
        const int x1 = vertices[from].first, y1 = vertices[from].second;
        const int x2 = vertices[to].first, y2 = vertices[to].second;

        const double delta_x = x2 - x1;
        const double delta_y = y2 - y1;

        return sqrt(delta_x * delta_x + delta_y * delta_y);
    }
}
