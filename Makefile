all: a_algorithim.o astar.o aux.o best_first.o dfs.o dijkstra.o knn_graph.o search.o main.cpp
	g++ a_algorithim.o astar.o aux.o best_first.o dfs.o dijkstra.o knn_graph.o main.cpp -o main
a_algorithim.o: a_algorithim.cpp aux.o
	g++ -c a_algorithim.cpp -o a_algorithim.o
astar.o: astar.cpp aux.o
	g++ -c astar.cpp -o astar.o
best_first.o: best_first.cpp aux.o
	g++ -c best_first.cpp -o best_first.o
dfs.o: dfs.cpp
	g++ -c dfs.cpp -o dfs.o
dijkstra.o: dijkstra.cpp
	g++ -c dijkstra.cpp -o dijkstra.o
knn_graph.o: knn_graph.cpp
	g++ -c knn_graph.cpp -o knn_graph.o
aux.o: aux.cpp
	g++ -c aux.cpp -o aux.o
run: ./main
	./main
