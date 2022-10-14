#include "search.hpp"
#include <iostream>

int main()
{
    knn_graph g;
    g.gen_vertices(10);
    g.gen_edges(5);

    g.print_graph();
    g.print_edges();
}
