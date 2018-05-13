#include "FileReader.h"
#include "Dijkstra.h"

#include <fstream>
#include <iostream>

// File to read in a matrix for adjacency
void ReadMatrix()
{	
	std::ifstream in("matrix.txt");

	if (!in)
	{
		std::cout << "Cannot open matrix file." << std::endl;
		return;
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			in >> graph[i][j];
		}
	}
	in.close();

	////////////////// Loop for testing input of array

	/*
	for (int k = 0; k < 6; k++)
	{
		for (int y = 0; y < 6; y++)
		{
			std::cout << storage[k][y] << " ";
		}
		std::cout << std::endl;
	}
	*/
}