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
	m_adjMatrix = new int*[vertices];
	for (int i = 0; i < vertices; i++)
		m_adjMatrix[i] = new int[vertices];

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
			m_adjMatrix[i][j] = INF;
	}
}

bool AdjacencyMatrix::IsAdjacent(int u, int v)
{
	return m_adjMatrix[u - 1][v - 1] != INF;
}

void AdjacencyMatrix::AddEdge(int u, int v, int weight)
{
	m_adjMatrix[u - 1][v - 1] = weight;
}

void AdjacencyMatrix::RemoveEdge(int u, int v)
{
	m_adjMatrix[u - 1][v - 1] = INF;
}

List AdjacencyMatrix::GetAdjList(int u)
{
	List resList;

	for (int v = 0; v < m_vertices; v++)
	{
		int weight = m_adjMatrix[u - 1][v - 1];
		if (weight != INF)
			resList.addToList(v, weight);
	}
	return resList;
}

void AdjacencyMatrix::printMatrix()
{
	for (int i = 0; i < m_vertices; i++)
	{
		std::cout << '\t' << i + 1;
	}
	std::cout << '\n' << '\n';
	for (int i = 0; i < m_vertices; i++)
	{
		std::cout << i + 1 << '\t';
		for (int j = 0; j < m_vertices; j++)
		{
			if (m_adjMatrix[i][j] == INF)
				std::cout << '\\' << '\t';
			else
				std::cout << m_adjMatrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
