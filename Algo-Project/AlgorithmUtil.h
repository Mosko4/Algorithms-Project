#pragma once
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

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


