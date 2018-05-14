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

#define V 6;

int main()
{

	int graph = [V][V] ={
	{ 1,0,7,0,0,0},
	{1, 0, 0, 0, 0, 0},
	{0, 0, 4, 2, 0, 0},
	{0, 0, 0, 0, 1, 6},
	{8, 11, 0, 1, 0, 7},
	{0, 0, 2, 6, 7, 8}
};
	//ReadMatrix();
	//FillGraph(6,6);
	dijkstra(graph, 0);


	std::cin.get();
}