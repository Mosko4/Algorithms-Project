#pragma once
#include <limits>
#include "List.h"
constexpr int INF = INT_MAX;

class AdjacencyMatrix
{
private:

	const int m_vertices;
	int **m_adjMatrix = nullptr;

public:

	AdjacencyMatrix() = delete;
	AdjacencyMatrix(const AdjacencyMatrix& other) = delete;
	AdjacencyMatrix(int vertices);
	~AdjacencyMatrix();
	void MakeEmptyGraph(int vertices);
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int weight);
	void RemoveEdge(int u, int v);
	List GetAdjList(int u);

};

