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
#include "FileReader.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{

	//int graph[6][6];
	ReadMatrix();
	FillGraph(6,6);
	//dijkstra(ReadMatrix(graph, 0);


	std::cin.get();
}