// Implementation of Prim's Algorithm
// Alex Blair
// Utilizing https://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
// Algorithm is adapted from the link above
// File reading capabilities implemented by myself as well as scale to
// Given matrix size for this class
// As well as output format. 
// The program is for adjacency matrix representation of the graph

// Talking point: Read verticies backward to see they are all connected
// Also the weights form the minimum spanning tree set.

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>


// Number of vertices in the graph
#define SIZ 4

// Function to find the minimum key value in the minimum
// spanning tree and including verticies not used yet. 
int minKey(int key[], bool mstSet[])
{
	// Initialize minimum value
	int min = INT_MAX, min_index;

	for (int v = 0; v < SIZ; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed minimum spanning tree stored in parent[]
void printTree(int parent[], int n, int graph[SIZ][SIZ])
{
	printf("Edge.......Weight\n");
	for (int i = 1; i < SIZ; i++)
		printf("%d-%d............%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print minimum spanning tree for a graph represented using adjacency
// matrix representation
void prim(int graph[SIZ][SIZ])
{
	int parent[SIZ]; // Array to store constructed minimum spanning tree
	int key[SIZ]; // Key values used to pick minimum weight edge in cut
	bool mstSet[SIZ]; // To represent set of vertices not yet included in minimum spanning tree

					// Initialize all keys as INFINITE
	for (int i = 0; i < SIZ; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in minimum spanning tree.
	key[0] = 0;	 // Make key 0 so that this vertex is picked as first vertex
	parent[0] = -1; // First node is always root of minimum spanning tree 

					// The minimum spanning tree will have V vertices
	for (int count = 0; count < SIZ - 1; count++)
	{
		// Pick the minimum key vertex from the set of vertices
		// not yet included in minimum spanning tree
		int u = minKey(key, mstSet);

		// Add the picked vertex to the minimum spanning tree Set
		mstSet[u] = true;

		// Update key value and parent index of the adjacent vertices of
		// the picked vertex. Consider only those vertices which are not yet
		// included in the minimum spanning tree
		for (int v = 0; v < SIZ; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// minimum spanning treeSet[v] is false for vertices not yet included in minimum spanning tree
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed minimum spanning tree
	printTree(parent, SIZ, graph);
}


// driver program to test above function
int main()
{

	int graph[SIZ][SIZ];

	std::ifstream in("matrix2.txt");

	if (!in)
	{
		std::cout << "Cannot open file matrix2.txt" << std::endl;
	}

	for (int i = 0; i < SIZ; i++)
	{
		for (int j = 0; j < SIZ; j++)
		{
			in >> graph[i][j];
		}
	}
	in.close();

	// Print the solution
	prim(graph);

	return 0;
}
