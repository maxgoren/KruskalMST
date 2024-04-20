kruskal:
	g++ --std=c++17 -c disjointset.cpp
	g++ --std=c++17 -c graph.cpp
	g++ --std=c++17 -c kruskal.cpp
	g++ --std=c++17 -c app.cpp
	g++ --std=c++17 -c main.cpp
	g++ *.o -o kruskal -lsfml-graphics -lsfml-window -lsfml-system