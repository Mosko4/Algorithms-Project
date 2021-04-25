#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define invalid_input cout << "Invalid input" << endl; exit(1);
#include "minHeap.h"
#include "minArray.h"
#include <fstream>
#include <string>
using namespace std;
constexpr int MAX_SIZE = 201;

	
// This file defines the algorithms needed to implement in the project, a helper class and utility methods for input.


class AlgorithmUtil
{
	/*
		This class holds the distance array and parents array, initialized from source vertex s.
		Contains also the Init, Relax methods learned in class for usage in the algorithms.
    */
public:
	struct Route 
	{
		float distance;
		bool Inf;
	};
	Route* d;
	int* p;

	AlgorithmUtil(int s, int vertices); 
	~AlgorithmUtil();
	bool relax(int u, int v, float weight);
	void init(int s, int vertices); // Init(vertex s)
	float getWeight(int destination); // Returns the weight in d[dest]
};

// Algorithms for implementation in the project
bool Bellman_Ford(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
bool Bellman_Ford(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);

void Dijkstra_Heap(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
void Dijkstra_Heap(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);

void Dijkstra_Array(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
void Dijkstra_Array(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);

// Methods to get input from file and check if it's valid
void getVertices(fstream& file, int& vertices, int& source, int& dest); // Gets no. of vertices, source vertex & destination vertex
void getEdges(fstream& file, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix); // Gets the edges and their weights from file
int checkLine(string& currentRead); // Checks validity of lines 1-3 in file
