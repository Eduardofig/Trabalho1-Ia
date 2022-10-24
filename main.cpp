#include "search.hpp"
#include "dfs.hpp"
#include "aux.hpp"
#include <iostream>

int main()
{
    // Criação do grafo KNN e funcionalidades usadas para o experimento 1 
    knn_graph graph(30, 2);
    
    aux::print_graph(graph);
    // Roda uma busca usando todos os algoritmos, definindo o grafo, nó inicial e final
    aux::run_experiment(graph, 1, 30);

    /*
        Cálculo da distância e tempo médios para os experimento 2, mudamos o algoritmo
        de busca em search:: e definimos quantas vezes queremos rodar para tirar as médias
    */ 
    auto [avg_time, avg_dist, avg_walked] = aux::get_avg_time_dist(graph, 20, search::dfs);

    std::cout << "\nCurrent Search:\n";
    std::cout << "Average time : " << avg_time << " microseconds " << '\n';
    std::cout << "Average path distance: " << avg_dist << '\n';
    std::cout << "Average nodes walked: " << avg_walked << '\n';

}
