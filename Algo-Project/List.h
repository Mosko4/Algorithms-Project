#pragma once
#include <iostream>

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
	~List();

	void MakeEmptyList();
	void clearList();
	void addToList(const int vertex, const float weight);
	void DeleteNode(int vertex);
	bool findNode(const int vertex) const;
	int getNumEdges() const { return vertices; }
	Node* getListHead() const { return _head; }

	// debugging
	void printList();
};
