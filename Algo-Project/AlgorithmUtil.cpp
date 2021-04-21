#include "AlgorithmUtil.h"
#include "List.h"

AlgorithmUtil::AlgorithmUtil(int s, int vertices) : d(new Route[vertices]) , p(new int[vertices+1]())
{
	init(s, vertices);
}

AlgorithmUtil::~AlgorithmUtil()
{
	delete[] p;
	delete[] d;
}

bool AlgorithmUtil::relax(int u, int v , float weight)
{
	bool improved;
	if (d[v - 1].Inf == true && d[u - 1].Inf == true) // u and v = INF
		improved = false;
	else if (d[u - 1].Inf == true) // u = INF
		improved = false;
	else if (d[v - 1].Inf == true || (d[v - 1].distance > d[u - 1].distance + weight)) // v = INF or u->v improved distance
	{
		d[v - 1].distance = d[u - 1].distance + weight;
		d[v - 1].Inf = false;
		p[v] = u;
		improved = true;
	}
	else
		improved = false;

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
	int NumVertices = graph.getNumVertices();

	algoUtil.init(vertex, NumVertices);
	for (int j = 0; j < NumVertices - 1; j++)// main loop
	{
		for (int i = 1; i < NumVertices; i++)
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
	}
	for (int i = 1; i < NumVertices; i++)
	{
		for (int j = 1; j < NumVertices; j++)
		{
			if (graph.IsAdjacent(i, j) && algoUtil.relax(i, j, graph.getWeight(i, j)))
				return false; // negative cycle
		}
	}

	return true; // success
}

bool Bellman_Ford(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil)
{
	int NumVertices = graph.getNumVertices();
	algoUtil.init(vertex, NumVertices);
	for (int j = 0; j < NumVertices-1; j++)// main loop
	{
		for (int i = 1; i < NumVertices; i++) 
		{
			auto temp = graph.getListHead(i - 1);
			while (temp)
			{
				algoUtil.relax(i, temp->vertex, temp->weight);
				temp = temp->_next;
			}
		}
	}
	for (int i = 1; i < NumVertices; i++) 
	{
		auto temp = graph.getListHead(i - 1);
		while (temp)
		{
			if (algoUtil.relax(i, temp->vertex, temp->weight))
				return false; // Negative cycle
			temp = temp->_next;
		}
	}
	return true; // success
}
