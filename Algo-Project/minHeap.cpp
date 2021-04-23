#include "minHeap.h"


minHeap::minHeap(int maxSize) : allocated(1), m_heapSize(0), m_maxSize(maxSize), m_arr(new Item[maxSize]), itemIndex(new int[maxSize])
{
}
minHeap::minHeap(Item* arr, int size) : allocated(0), itemIndex(new int[size])
{
	buildHeap(arr, size); // floyd alogrithm
}

minHeap::~minHeap()
{
	makeEmpty();
}

void minHeap::insert(const Item& item) 
{
	if (m_heapSize == m_maxSize)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	int i = m_heapSize;
	m_heapSize++;
	int parent = (i - 1) / 2;

	while ((i > 0) && (m_arr[parent].key > item.key))
	{
		m_arr[i] = m_arr[parent];
		itemIndex[m_arr[parent].data - 1] = i;
		i = parent;
		parent = (i - 1) / 2;
	}
	m_arr[i] = item;
	itemIndex[item.data - 1] = i;
}

Item minHeap::DeleteMin()
{
	if (!m_heapSize)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	Item min = m_arr[0];
	m_heapSize--;
	m_arr[0] = m_arr[m_heapSize];
	itemIndex[m_arr[0].data - 1] = 0;
	fixHeap(0);

	return min;
}

void minHeap::fixHeap(int node)
{
	int min;
	int left = (node * 2) + 1, right = (node * 2) + 2;

	if ((left < m_heapSize) && (m_arr[left].key < m_arr[node].key))
		min = left;
	else
		min = node;

	if ((right < m_heapSize) && (m_arr[right].key < m_arr[min].key))
		min = right;


	if (min != node)
	{
		swap(m_arr[node], m_arr[min]);
		fixHeap(min);
	}
}

void minHeap::buildHeap(Item* arr, int size) // floyd alogrithm
{
	m_maxSize = m_heapSize = size;
	m_arr = arr;

	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

void minHeap::swap(Item& a, Item& b)
{
	Item temp = a;
	int tempIndex = itemIndex[a.data - 1];
	itemIndex[a.data - 1] = itemIndex[b.data - 1];
	itemIndex[b.data - 1] = tempIndex;
	a = b;
	b = temp;
	
}

bool minHeap::isEmpty() const
{
	return m_heapSize == 0;
}

void minHeap::makeEmpty()
{
	if (allocated)
		delete[] m_arr;

	delete[] itemIndex;
	m_heapSize = 0;
}

void minHeap::DecreaseKey(int place, float newKey)
{
	int i = itemIndex[place - 1];
	int parent = (i - 1) / 2;
	m_arr[i].key = newKey;

	while (i != 0 && m_arr[parent].key > m_arr[i].key)
	{
		swap(m_arr[i], m_arr[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}

}

void minHeap::Build(int vertex)
{
	
	for (int i = 0; i < m_maxSize; i++)
	{
		Item currentItem(i + 1, FLT_MAX);
		if (i + 1 == vertex) // source vertex
			currentItem.key = 0;

		insert(currentItem);
	}
}



