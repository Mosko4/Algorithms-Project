#pragma once
#include "Item.h"
#include <iostream>

class minArray
{
private :
	Item* m_arr;
	int m_maxSize, m_heapSize;
	Item* m_min;
public:

	minArray(int maxSize);
	minArray(minArray& other) = delete; // no use for a copy ctor
	~minArray();
	minArray& operator=(minArray& other) = delete; // no use for this operator

	void makeEmpty();
	void insert(const Item& item);
	Item DeleteMin();
	void DecreaseKey(int place, float newKey);
	Item min() const { return *m_min; }
	bool isEmpty() const { return m_heapSize == 0; }
	void build(int vertex);
};

