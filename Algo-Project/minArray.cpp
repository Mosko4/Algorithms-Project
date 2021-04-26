#include "minArray.h"

minArray::minArray(int maxSize) : m_arr(new Item[maxSize]), m_maxSize(maxSize), m_heapSize(0), m_min(nullptr)
{

}

minArray::~minArray()
{
	makeEmpty();
}

void minArray::makeEmpty()
{
	if (m_arr != nullptr)
		delete m_arr;

	m_heapSize = 0;
	m_maxSize = 0;
	m_min = nullptr;
}

void minArray::insert(const Item& item)
{
	if (m_heapSize == m_maxSize)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	
	m_arr[item.data - 1] = item;
	if (m_min == nullptr || item.key < m_min->key) // new min or empty array
	{
		m_min = &m_arr[item.data - 1];
	}
	m_heapSize++;

}

Item minArray::DeleteMin()
{
	Item min = *m_min,* newMin = nullptr;
	bool foundMin = false;
	m_arr[m_min->data - 1].key = -1;
	if (m_heapSize == 0)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	else if (--m_heapSize == 0) // array becomes empty
		return min;
	
	for (int i = 0; i < m_maxSize && !foundMin; i++)
	{
		if (m_arr[i].key != -1) // get new starting value
		{
			newMin = &m_arr[i];
			foundMin = true;
		}
	}

	if (foundMin)
	{
		for (int i = 0; i < m_maxSize; i++)
		{
			if (newMin->key > m_arr[i].key && m_arr[i].key != -1)
				newMin = &m_arr[i]; // new min
		}

		m_min = newMin;
	}
	else { // empty array
		std::cout << "Invalid input";
		exit(1);
	}

	return min;
}

void minArray::DecreaseKey(int place, float newKey)
{
	m_arr[place - 1].key = newKey;
	if (m_min == nullptr || newKey < m_min->key) // new min or empty array
		m_min = &m_arr[place - 1];
}

void minArray::build(int vertex)
{
	for (int i = 0; i < m_maxSize; i++)
	{
		Item item(i + 1, MAX);
		if (i + 1 == vertex)
			item.key = 0;

		insert(item);
	}
}
