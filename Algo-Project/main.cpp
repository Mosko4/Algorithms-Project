#include <iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "AlgorithmUtil.h"
#include "MeasureTime.h"

/*
	Algorithms - Project by Omer Moskowitz & Yarden Yaakov Naim
	============================================================

	The program receives two file names via command line arguments.
	The first file in argv[1] is an input file represnting a graph.
	The program builds two graphs (adjacency list, adjacency matrix) from the input file.
	After the graphs are complete, it uses the algorithms: Dijkstra & Bellman Ford, measures their operation time and prints the results to output file in argv[2],
	and also prints the result (total weight) from source vertex to destination vertex to the terminal window.
*/

void main(int argc, char** argv)
{
	fstream file;
	file.open(argv[1]);
	if (!file)
	{
		invalid_input
	}

	int vertices, source, dest;
	// Get input from file and build graphs
	getVertices(file, vertices, source, dest);
	AdjacencyList adjList(vertices);
	AdjacencyMatrix adjMatrix(vertices);
	getEdges(file, adjList, adjMatrix);
	file.close();

	// Activate algorithms and measure their complexity
	measureComplexity(vertices, source, dest, adjList, adjMatrix, argv[2]);
}