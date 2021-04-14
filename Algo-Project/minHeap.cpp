#include "minHeap.h"


minHeap::minHeap(int maxSize) : allocated(1), m_heapSize(0), m_maxSize(maxSize), m_arr(new Node* [maxSize])
{
}
minHeap::minHeap(Node** arr, int size) : allocated(0)
{
	buildHeap(arr, size); // floyd alogrithm
}

minHeap::~minHeap()
{
	if (allocated)
	{
		for (int i = 0; i < m_maxSize; i++)
		{
			delete m_arr[i];
		}
		delete[] m_arr;
	}
}

void minHeap::insert(Node** item)
{
	if (m_heapSize == m_maxSize)
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	int i = m_heapSize;
	m_heapSize++;
	int parent = (i - 1) / 2;

	while ((i > 0) && (m_arr[parent]->data._freq > (*item)->data._freq))
	{
		m_arr[i] = m_arr[parent];
		i = parent;
		parent = (i - 1) / 2;
	}
	m_arr[i] = *(item);
}

Node* minHeap::DeleteMin()
{
	if (!m_heapSize)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	Node* min = m_arr[0];
	m_heapSize--;
	m_arr[0] = m_arr[m_heapSize];
	fixHeap(0);

	return min;
}

void minHeap::fixHeap(int node)
{
	int min;
	int left = (node * 2) + 1, right = (node * 2) + 2;

	if ((left < m_heapSize) && (m_arr[left]->data._freq < m_arr[node]->data._freq))
		min = left;
	else
		min = node;

	if ((right < m_heapSize) && (m_arr[right]->data._freq < m_arr[min]->data._freq))
		min = right;


	if (min != node)
	{
		swap(m_arr[node], m_arr[min]);
		fixHeap(min);
	}
}

void minHeap::buildHeap(Node** arr, int size) // floyd alogrithm
{
	m_maxSize = m_heapSize = size;
	m_arr = arr;

	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

void minHeap::swap(Node*& a, Node*& b)
{
	Node* temp = a;
	a = b;
	b = temp;
}

