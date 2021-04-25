#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int vertices) : m_vertices(vertices)
{
	MakeEmptyGraph(vertices);
}

AdjacencyList::~AdjacencyList()
{
	if (m_adjList != nullptr)
	{
		delete[] m_adjList;
		m_adjList = nullptr;
	}
}

void AdjacencyList::MakeEmptyGraph(int vertices)
{
	m_adjList = new List[vertices];
}

bool AdjacencyList::IsAdjacent(int u, int v) const
{
	return m_adjList[u - 1].findNode(v);
}

void AdjacencyList::AddEdge(int u, int v, float weight)
{
	m_adjList[u - 1].addToList(v, weight);
}

void AdjacencyList::RemoveEdge(int u, int v)
{
	m_adjList[u - 1].DeleteNode(v);
}

void AdjacencyList::printList()
{
	for (int i = 0; i < m_vertices; i++)
	{
		std::cout << i + 1 << " |\t";
		m_adjList[i].printList();
		std::cout << "\n\n";
	}
	std::cout << "------------------------" << std::endl;
}
