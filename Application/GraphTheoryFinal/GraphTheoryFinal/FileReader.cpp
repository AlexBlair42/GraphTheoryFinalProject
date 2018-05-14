#include "FileReader.h"
//#include "Dijkstra.h"

#include <fstream>
#include <iostream>


// File to read in a matrix for adjacency
///////////////////////////////////////////////////////////////////////////
void ReadMatrix()
{
	int storage[6][6];
	std::ifstream in("matrix.txt");

	if (!in)
	{
		std::cout << "Cannot open matrix file." << std::endl;
		return;
	}

	for (int i = 0; i < sizeof storage; i++)
	{
		for (int j = 0; j < sizeof storage; j++)
		{
			in >> storage[i][j];
		}
	}
	in.close();

	////////////////// Loop for testing input of array

	for (int k = 0; k < 6; k++)
	{
		for (int y = 0; y < 6; y++)
		{
			std::cout << storage[k][y] << " ";
		}
		std::cout << std::endl;
	}
}
///////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
/*
int** FillGraph(int height, int width)
{
	int** graph = 0;
	graph = new int*[height];

	for (int h = 0; h < height; h++)
	{
		graph[h] = new int[width];
		for (int w = 0; w < width; w++)
		{
			storage[h][w] = graph[h][w];
			graph[h][w] = w + width * h;
		}
	}

	for (int k = 0; k < 6; k++)
	{
		for (int y = 0; y < 6; y++)
		{
			std::cout << storage[k][y] << " ";
		}
		std::cout << std::endl;
	}
	return graph;
}
////////////////////////////////////////////////////////////////////////
*/


