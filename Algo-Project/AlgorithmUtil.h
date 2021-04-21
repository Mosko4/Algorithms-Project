#pragma once
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include <fstream>
#include <string>
using namespace std;
#define invalid_input cout << "Invalid input" << endl; exit(1);


/*	This class holds the distance array and parents array, initialized from source vertex s.
	Contains also the Init, Relax methods learned in class for usage in the algorithms.
 */
class AlgorithmUtil
{
public:
	struct Route 
	{
		float distance;
		bool Inf;
	};
	Route* d;
	int* p;

	AlgorithmUtil(int s, int vertices); 
	~AlgorithmUtil();
	bool relax(int u, int v, float weight);
	void init(int s, int vertices); // Init(vertex s)
};

// Algorithms for implementation in the project
bool Bellman_Ford(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
bool Bellman_Ford(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);


// Methods to get input from file and check if it's valid
bool getVertexFile(string& str, int& vertex);
bool getWeightFile(string& str, float& weight);
void getEdges(fstream& file, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix);
int checkLine(string& currentRead);
void getVertices(fstream& file, int& vertices, int& source, int& dest);

