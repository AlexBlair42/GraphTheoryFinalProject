/////////////////////////////////////////////////////////////
// Alex Blair
// MA 430
// Final Project
// Implementation of Dijkstra's Algorithm
// As Well as Prim's/Kruskal's Algorithms
// This file will read in a matrix of weights
// Then run the data through each algorithm
// And print time results as well as shortest path weight
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Dijkstra.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph, 0);


	std::cin.get();
}