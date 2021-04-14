#pragma once


class List 
{
private:
	struct Node
	{
		int vertex;
		int weight;
		Node* _next;

		Node(const int v,const int w, Node* next = nullptr) : vertex(v), weight(w) ,_next(next) {}
	};

	Node* _head, * _tail;
	int vertices;
public:
	List();
	~List();

	// data & update related methods
	void MakeEmptyList();
	void clearList();
	void addToList(const int vertex, const int weight);
	void DeleteNode(int vertex);
};
