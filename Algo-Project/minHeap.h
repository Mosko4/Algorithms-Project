#pragma once
#include "Node.h"
#include "binaryTree.h"

	class minHeap // minimum heap implemented with an array of Node* 
	{
	private:

		Node** m_arr;
		int m_maxSize, m_heapSize;
		int allocated;

	public:

		minHeap(int maxSize);
		minHeap(Node** arr, int size); // creates the heap using floyd alogrithm
		minHeap(minHeap& other) = delete; // no use for a copy ctor
		~minHeap();

		minHeap& operator=(minHeap& other) = delete; // no use for this operator

		void   insert(Node** item);
		Node* DeleteMin();
		void   fixHeap(int node);
		void   buildHeap(Node** arr, int size);
		Node* min() const { return m_arr[0]; }
		void   swap(Node*& a, Node*& b);
	};

