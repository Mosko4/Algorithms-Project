#pragma once
#include "List.h"
#include <iostream>

// This class defines a directed weighted graph using an adjacency list with an array of 'List' (self-implemented linked list class)

class AdjacencyList
{
private:

	const int m_vertices;
	List* m_adjList = nullptr;

public:

	AdjacencyList(const AdjacencyList& other) = delete; // no use for a copy ctor
	AdjacencyList(int vertices);
	~AdjacencyList();
	AdjacencyList& operator=(AdjacencyList& other) = delete; // no use for this operator

	void MakeEmptyGraph(int vertices);
	bool IsAdjacent(int u, int v) const;
	void AddEdge(int u, int v, float weight);
	void RemoveEdge(int u, int v);
	int getNumVertices() const { return m_vertices; }
	List::Node* getListHead(int i) const { return m_adjList[i].getListHead();}

	// debugging
	void printList();
};

