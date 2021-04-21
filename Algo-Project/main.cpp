#include <iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "minArray.h"
#include "minHeap.h"
#include "AlgorithmUtil.h"

/*
		TODO:

	1. Valid input - check for simple graph 
	2. Algorithms 
	3. BFS ???
	4. add operator= delete

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
	getVertices(file, vertices, source, dest);

	AdjacencyList adjList(vertices);
	AdjacencyMatrix adjMatrix(vertices);
	getEdges(file, adjList, adjMatrix);


	adjMatrix.printMatrix();
	cout << "\n\n\n----------------------------\n\n\n";
	adjList.printList();

	fstream outFile;
	outFile.open(argv[2], fstream::out);
	if (!outFile)
	{
		invalid_input
	}

	AlgorithmUtil algoUtil(source, vertices);
	Bellman_Ford(adjMatrix, source, algoUtil);

	if (algoUtil.d[dest - 1].Inf)
	{
		invalid_input;
	}

	cout << "Bellman Ford Matrix: " <<"Weight from " << source << " to " << dest << " is " << algoUtil.d[dest - 1].distance << endl;
	
	Bellman_Ford(adjList, source, algoUtil);
	cout << "Bellman Ford List: " << "Weight from " << source << " to " << dest << " is " << algoUtil.d[dest - 1].distance << endl;

	
	file.close();
}