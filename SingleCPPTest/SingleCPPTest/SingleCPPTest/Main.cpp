#include <iostream>
#include <fstream>
using std::cin;
using std::endl;
using std::cout;

#define V 6

void ReadMatrix();

int** FillGraph(unsigned height, unsigned width);

int storage[6][6];

int minimum_path(int distance[], bool set[]);

void Print_Solution(int distance[], int n);

void dijkstra(int graph, int src);


int main()
{

	int graph[6][6];
	ReadMatrix();
	FillGraph(6, 6);
	//dijkstra(ReadMatrix(graph, 0);


	std::cin.get();
}


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
			in >> storage[i][j];
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

///////////////////////////////////////////////////////////////////////////////////////
int minimum_path(int distance[], bool set[])
{
	// Initialize minimums 
	int min = INT_MAX, min_index;

	for (int v = 0; v<V; v++)
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
		printf("%d tt %d \n", i, distance[i]);
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

