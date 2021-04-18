#include "AlgorithmUtil.h"

AlgorithmUtil::AlgorithmUtil(int s, int vertices) : d(new Route[vertices]) , p(new int[vertices+1]())
{
	init(s, vertices);
}

AlgorithmUtil::~AlgorithmUtil()
{
	delete[] p;
	delete[] d;
}

bool AlgorithmUtil::relax(int u, int v , int weight)
{
	bool improved = false;
	if (d[v - 1].Inf == true && d[u - 1].Inf == true) // u and v == INF
		improved = false;
	else if (d[u - 1].Inf == true) // u == INF
		improved = false;
	else if (d[v - 1].Inf == true || (d[v - 1].distance > d[u - 1].distance + weight)) // v == INF or u->v improve distance
	{
		d[v - 1].distance = d[u - 1].distance + weight;
		p[v] = u;
		improved = true;
	}
	return improved;
}

void AlgorithmUtil::init(int s, int vertices)
{
	for (int i = 0; i < vertices; i++)
	{
		d[i].Inf = true;
	}
	d[s - 1].distance = 0;
	d[s - 1].Inf = false;
}

bool Bellman_Ford(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil)
{
	algoUtil.init(vertex, graph.getNumVertices());

	for (int i = 1; i < graph.getNumVertices(); i++) // main loop
	{
		List edges;
		graph.GetAdjList(i, edges);
		auto temp = edges.getListHead();
		
		while (temp) // relax edges from vertex i
		{
			algoUtil.relax(i, temp->vertex, temp->weight);
			temp = temp->_next;
		}
	}

	for (int i = 1; i < graph.getNumVertices(); i++)
	{
		for (int j = 1; j < graph.getNumVertices(); j++)
		{
			if (graph.IsAdjacent(i, j) && algoUtil.relax(i, j, graph.getWeight(i, j)))
				return false; // negative cycle
		}
	}

	return true; // success
}
