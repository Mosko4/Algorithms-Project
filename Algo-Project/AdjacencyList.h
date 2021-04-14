#pragma once
#include "List.h"
#include <iostream>

class AdjacencyList
{
private:

	const int m_vertices;
	List* m_adjList = nullptr;

public:

	AdjacencyList() = delete;
	AdjacencyList(const AdjacencyList& other) = delete;
	AdjacencyList(int vertices);
	~AdjacencyList();
	void MakeEmptyGraph(int vertices);
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int weight);
	void RemoveEdge(int u, int v);

	// debugging
	void printList();
};

