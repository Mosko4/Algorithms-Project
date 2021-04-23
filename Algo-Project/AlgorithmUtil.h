#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define invalid_input cout << "Invalid input" << endl; exit(1);
#include "minHeap.h"
#include "minArray.h"
#include <fstream>
#include <string>

using namespace std;
constexpr int MAX_SIZE = 201;


/*	This class holds the distance array and parents array, initialized from source vertex s.
	Contains also the Init, Relax methods learned in class for usage in the algorithms.
 */
class AlgorithmUtil
{
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
};

// Algorithms for implementation in the project
bool Bellman_Ford(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
bool Bellman_Ford(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);

void Dijkstra_Heap(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
void Dijkstra_Heap(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);

void Dijkstra_Array(const AdjacencyMatrix& graph, int vertex, AlgorithmUtil& algoUtil);
void Dijkstra_Array(const AdjacencyList& graph, int vertex, AlgorithmUtil& algoUtil);


// Methods to get input from file and check if it's valid
bool getVertexFile(string& str, int& vertex);
bool getWeightFile(string& str, float& weight);
void getEdges(fstream& file, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix);
int checkLine(string& currentRead);
void getVertices(fstream& file, int& vertices, int& source, int& dest);

