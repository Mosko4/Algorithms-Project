#pragma once
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

class AlgorithmUtil
{
public:
	struct Route {
		int distance;
		bool Inf;
	};
	Route* d;
	int* p;

	AlgorithmUtil(int s, int vertices); // Init(vertex s)
	~AlgorithmUtil();
	bool relax(int u, int v, int weight);
	void init(int s, int vertices);
};


bool Bellman_Ford(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
bool Bellman_Ford(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);


