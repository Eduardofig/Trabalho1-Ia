#include <utility>
#include <vector>

class knn_graph
{
    private:
        std::vector<std::pair<int, int>> vertices;
        std::vector<std::vector<std::pair<int, double>>> edges;

    public:
        void gen_vertices(int n);
        void gen_edges(int k);
        knn_graph(int n, int k);
};


