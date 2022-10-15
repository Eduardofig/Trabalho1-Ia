all: a_algorithim.o astar.o aux.o best_first.o dfs.o dijkstra.o knn_graph.o search.o main.cpp
	g++ a_algorithim.o astar.o aux.o best_first.o dfs.o dijkstra.o knn_graph.o main.cpp -o main -std=c++17
a_algorithim.o: a_algorithim.cpp aux.o
	g++ -c a_algorithim.cpp -o a_algorithim.o -std=c++17
astar.o: astar.cpp aux.o
	g++ -c astar.cpp -o astar.o -std=c++17
best_first.o: best_first.cpp aux.o
	g++ -c best_first.cpp -o best_first.o -std=c++17
dfs.o: dfs.cpp
	g++ -c dfs.cpp -o dfs.o -std=c++17
dijkstra.o: dijkstra.cpp
	g++ -c dijkstra.cpp -o dijkstra.o -std=c++17
knn_graph.o: knn_graph.cpp
	g++ -c knn_graph.cpp -o knn_graph.o -std=c++17
aux.o: aux.cpp
	g++ -c aux.cpp -o aux.o -std=c++17
run: ./main
	./main
clear: 
	rm *.o main
