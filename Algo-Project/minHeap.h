#pragma once
#include "Item.h"
#include <iostream>
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

	class minHeap // minimum heap implemented with an array of Node* 
	{
	private:
		Item* m_arr;
		int* itemIndex;
		int m_maxSize, m_heapSize;
		int allocated;

	public:

		minHeap(int maxSize);
		minHeap(Item* arr, int size); // creates the heap using floyd alogrithm
		minHeap(minHeap& other) = delete; // no use for a copy ctor
		~minHeap();
		minHeap& operator=(minHeap& other) = delete; // no use for this operator

		void insert(const Item& item);
		Item DeleteMin();
		void fixHeap(int node);
		void buildHeap(Item* arr, int size);
		Item min() const { return m_arr[0]; }
		void swap(Item& a, Item& b);
		bool isEmpty() const;
		void makeEmpty();
		void DecreaseKey(int place, float newKey);
		void Build(int vertex); // initialize heap for dijkstra - only source vertex key = 0

		
	};

