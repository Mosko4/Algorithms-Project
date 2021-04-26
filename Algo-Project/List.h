#pragma once
#include <iostream>

// This class defines a linked list. Each node represents an edge
class List 
{
	friend class AdjacencyList;
private:
	struct Node
	{
		int vertex;
		float weight;
		Node* _next;

		Node(const int v,const float w, Node* next = nullptr) : vertex(v), weight(w) ,_next(next) {}
	};
	Node* _head, * _tail;
	int vertices;

public:
	List();
	List(const List& other) = delete; // no use for a copy ctor
	~List();
	List& operator=(List& other) = delete; // no use for this operator

	void MakeEmptyList();
	void clearList();
	void addToList(const int vertex, const float weight);
	void DeleteNode(int vertex);
	bool findNode(const int vertex) const;
	int getNumEdges() const { return vertices; }
	Node* getListHead() const { return _head; }
};
