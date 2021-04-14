#pragma once

struct Pair {
	int _key;
	int _freq = 0;
};

class Node // node class used by the trees & the minimum heap
{
	friend class BSTree;
	//friend class minHeap;
	//friend class HuffmanTree;

private:

	Pair data;
	Node* left, * right, * parent;

public:

	Node() : data({ 0,0 }), left(nullptr), right(nullptr), parent(nullptr) {}
	Node(const Node& other) : data(other.data), left(other.left), right(other.right), parent(other.parent) {}
	Node(const Pair& item) : data({ item._key , item._freq }), left(nullptr), right(nullptr), parent(nullptr) {}

	Pair getPair() const { return data; }
	Node& operator=(const Node& other) {
		if (this != &other)
		{
			data = other.data; left = other.left; right = other.right; parent = other.parent;
		}
		return *this;
	}

};