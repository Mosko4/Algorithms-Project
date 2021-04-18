#pragma once
#include <limits>
#include "List.h"
#include <iostream>
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
	bool IsAdjacent(int u, int v) const;
	void AddEdge(int u, int v, int weight);
	void RemoveEdge(int u, int v);
	void GetAdjList(int u, List& list) const;
	int getNumVertices() const { return m_vertices; }
	int getWeight(int u, int v)const;
	// debugging
	void printMatrix();

};

