// Alex Blair
// Utilizing https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
// As a source for basic algorithm

// Talking point: 
// This does go through Dijkstra's Algorithm successfully for
// A given adjacency matrix, however the output is in an ordered format for the 
// Vertex numbers. This is due to the fact that they are read from an array using a loop. 
// A better approach would be to have the results pushed onto a stack and then
// Popped off when read. This could be achieved given more time. 

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <fstream>

// Macro to set the size of the matrix
// Number of vertices in the graph
#define SIZ 8

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool is_included[])
{
	// Set minimum value of the inicies and the max.
	int min = INT_MAX, min_index;

	for (int d = 0; d < SIZ; d++)
		if (is_included[d] == false && dist[d] <= min)
			min = dist[d], min_index = d;

	return min_index;
}

// Print the solution for the algorithm
void printSolution(int dist[], int n)
{
	printf("Vertex........Distance from Source\n");
	for (int i = 0; i < SIZ; i++)
		printf("%d ................%d\n", i, dist[i]);
}

// Funtion that implements Dijkstra's shortest path algorithm
// for a graph represented using adjacency matrix representation
// Takes the constructed 2D array as a parameter and a source vertex
void dijkstra(int graph[SIZ][SIZ], int src)
{
	int dist[SIZ];	 // This array will hold the shortest path from source to destination

	bool is_included[SIZ]; // This is a check to make sure that the given value is in the solution set.
					

					// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < SIZ; i++)
		dist[i] = INT_MAX, is_included[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < SIZ - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, is_included);

		// Mark the picked vertex as processed
		is_included[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int d = 0; d < SIZ; d++)

			// Update dist[v] only if is not in is_included, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v]
			if (!is_included[d] && graph[u][d] && dist[u] != INT_MAX
				&& dist[u] + graph[u][d] < dist[d])
				dist[d] = dist[u] + graph[u][d];
	}

	// print the array for the constructed distances
	printSolution(dist, SIZ);
}

// Main function for the program
int main()
{
	// Set up a genral 2D array for a graph
	int graph[SIZ][SIZ];

	// Open file for reading of matrix
	std::ifstream in("matrix2.txt");

	// If file does not open throw an exception
	if (!in)
	{
		std::cout << "Cannot open file matrix2.txt" << std::endl;
	}

	// Read through the file and place each value into the graph array
	for (int i = 0; i < SIZ; i++)
	{
		for (int j = 0; j < SIZ; j++)
		{
			in >> graph[i][j];
		}
	}
	// Close the file once finished
	in.close();

	// Call function to run the graph through Dijkstra's Algorithm
	dijkstra(graph, 0);

	return 0;
}
