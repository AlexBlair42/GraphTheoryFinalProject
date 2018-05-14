
#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdio>

#include "Dijkstra.h"
//#include "FileReader.h"

#define V 6

///////////////////////////////////////////////////////////////////////////////////////
int minimum_path(int distance[], bool set[])
{
	// Initialize minimums 
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	{
		if (set[v] == false && distance[v] <= min)
		{
			min = distance[v], min_index = v;
		}
	}
	return min_index;
}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
void Print_Solution(int distance[], int n)
{
	std::cout << "Vertex distance from source is" << std::endl;
	for (int i = 0; i < V; i++)
	{
		printf("%d , %d \n", i, distance[i]);
	}
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void dijkstra(int graph[V][V], int src)
{
	int distance[V];

	bool set[V];

	for (int i = 0; i < V; i++)
	{
		distance[i] = INT_MAX, set[i] = false;

		distance[src] = 0;

	}

	for (int count = 0; count < V - 1; count++)
	{
		int u = minimum_path(distance, set);

		set[u] = true;

		for (int b = 0; b < V; b++)
		{
			if (!set[b] && graph[u][b] && distance[u] != INT_MAX && distance[u] + graph[u][b] < distance[b])
			{
				distance[b] = distance[u] + graph[u][b];
			}
		}
	}
	Print_Solution(distance, V);
}
///////////////////////////////////////////////////////////////////////////////////////////////////  
