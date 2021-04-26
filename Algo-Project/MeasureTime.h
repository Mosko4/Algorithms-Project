#pragma once
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "AlgorithmUtil.h"
#include <chrono>
#include <iomanip>


// Class that holds static methods for measurement of the algorithms
class MeasureTime
{
public:
	// Measurement methods
	static void measureComplexity(int vertices, int source, int dest, const AdjacencyList& adjList, const AdjacencyMatrix& adjMatrix, const char* fileName); // wrapper method

	static void measureDijkstra_Heap(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil, int dest);
	static void measureDijkstra_Array(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil);
	static void measureBellmanFord(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil);

	static void measureDijkstra_Heap(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
	static void measureDijkstra_Array(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
	static void measureBellmanFord(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
};

