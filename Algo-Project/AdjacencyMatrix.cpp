#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int vertices) : m_vertices(vertices)
{
	MakeEmptyGraph(vertices);
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	if (m_adjMatrix != nullptr)
	{
		for (int i = 0; i < m_vertices; i++)
		{
			delete[] m_adjMatrix[i];
		}
		delete[] m_adjMatrix;
		m_adjMatrix = nullptr;
	}
}

void AdjacencyMatrix::MakeEmptyGraph(int vertices)
{
	m_adjMatrix = new float*[vertices];
	for (int i = 0; i < vertices; i++)
		m_adjMatrix[i] = new float[vertices];

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
			m_adjMatrix[i][j] = INF;
	}
}

bool AdjacencyMatrix::IsAdjacent(int u, int v) const
{
	return m_adjMatrix[u - 1][v - 1] != INF;
}

void AdjacencyMatrix::AddEdge(int u, int v, float weight)
{
	m_adjMatrix[u - 1][v - 1] = weight;
}

void AdjacencyMatrix::RemoveEdge(int u, int v)
{
	m_adjMatrix[u - 1][v - 1] = INF;
}

void AdjacencyMatrix::GetAdjList(int u, List& list) const
{
	for (int v = 0; v < m_vertices; v++)
	{
		float weight = m_adjMatrix[u - 1][v];
		if (weight != INF)
			list.addToList(v + 1, weight);
	}
}

float AdjacencyMatrix::getWeight(int u, int v) const
{
	if (!IsAdjacent(u, v))
		return -1;
	else
		return m_adjMatrix[u - 1][v - 1];
}

Item* AdjacencyMatrix::BuildItemArray()
{
	Item* res = new Item[m_vertices];



	return res;
}
