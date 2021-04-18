#include "List.h"


List::List()
{
	MakeEmptyList();
}
List::~List()
{
	clearList();
}


void List::MakeEmptyList()
{
	_head = _tail = nullptr;
	vertices = 0;
}

void List::clearList()
{
	Node* temp = _head;
	if (temp == nullptr) // empty list
		return;
	while (temp != nullptr)
	{
		_head = _head->_next;
		delete temp;
		temp = _head;
	}
}


void List::addToList(const int vertex, const int weight)
{
	Node* node = new Node(vertex, weight);
	if (!_head) // empty list
		_head = _tail = node;
	else
	{
		_tail->_next = node;
		_tail = node;
	}
	vertices++;
}

void List::DeleteNode(int vertex)
{
	Node* curr = _head, * prev = nullptr;

	if (_head == _tail) 
	{
		if (_head && _head->vertex == vertex) 
		{
			clearList();
		}
		return;
	}
	else if (_head->vertex == vertex)
	{
		_head = curr->_next;
		delete curr;
		return;
	}
	else
	{
		while (curr->vertex != vertex && curr != nullptr)
		{
			prev = curr;
			curr = curr->_next;
		}

		if (!curr) // not found in list
			return;

		if (curr == _tail)
			_tail = prev;
		prev->_next = curr->_next;
		delete curr;
	}
	
	
}

bool List::findNode(const int vertex) const
{
	bool found = false;
	Node* current = _head;

	while (current && !found)
	{
		if (current->vertex == vertex)
			found = true;

		current = current->_next;
	}

	return found;
}

void List::printList()
{
	Node* temp = _head;

	while (temp)
	{
		std::cout << temp->vertex << '(' << temp->weight << ')' << " -> ";
		temp = temp->_next;
	}
}
