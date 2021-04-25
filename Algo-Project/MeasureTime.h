#pragma once
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "AlgorithmUtil.h"
#include <chrono>
#include <iomanip>

// Measurement methods
void measureComplexity(int vertices, int source, int dest, const AdjacencyList& adjList, const AdjacencyMatrix& adjMatrix, const char* fileName); // wrapper method

void measureDijkstra_Heap(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil, int dest);
void measureDijkstra_Array(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil);
void measureBellmanFord(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil);

void measureDijkstra_Heap(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
void measureDijkstra_Array(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
void measureBellmanFord(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil);
