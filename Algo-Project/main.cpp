#include <iostream>
#include <string>
#include <fstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

using namespace std;
#define rcastc reinterpret_cast<char*>
#define invalid_input cout << "Invalid input" << endl; exit(1);


/*
		TODO:

	1. Valid input - check for simple graph (no edge from vertex to itself, no double edges)
	2. MinHeap 
	3. Algorithms

*/
bool checkUpdateNumber(const string& str, int& num)
{
	bool validInput = true;
	for (auto& itr : str)
	{
		if (!isdigit(itr))
		{
			validInput = false;
			break;
		}
	}

	if (validInput)
	{
		num = atoi(str.c_str());
		if (num < 0)
			validInput = false;
	}

	return validInput;
}

void getInput(fstream& file, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix)
{
	bool validInput1 = true, validInput2 = true, validInput3 = true;
	string currentRead;
	int vertex_i, vertex_j, weight;
	while (!file.eof())
	{
		// get a duo of vertices and their weight while checking for valid input
		file >> currentRead;
		validInput1 = checkUpdateNumber(currentRead, vertex_i);
		file >> currentRead;
		validInput2 = checkUpdateNumber(currentRead, vertex_j);
		file >> currentRead;
		validInput3 = checkUpdateNumber(currentRead, weight);
		if (!validInput1 || !validInput2 || !validInput3)
		{
			invalid_input
		}

		if (vertex_i == vertex_j) // edge from vertex to itself
		{
			invalid_input
		}

		adjList.AddEdge(vertex_i, vertex_j, weight);
		adjMatrix.AddEdge(vertex_i, vertex_j, weight);
	}
}

void main(int argc, char** argv)
{
	fstream file;
	file.open(argv[1]);
	if (!file)
	{
		invalid_input
	}
	string currentRead;
	int vertices, source, dest;
	bool validInput1 = true, validInput2 = true, validInput3 = true;

	file >> currentRead;
	validInput1 = checkUpdateNumber(currentRead, vertices);
	file >> currentRead;
	validInput2 = checkUpdateNumber(currentRead, source);
	file >> currentRead;
	validInput3 = checkUpdateNumber(currentRead, dest);

	if (!validInput1 || !validInput2 || !validInput3)
	{
		invalid_input
	}

	AdjacencyList adjList(vertices);
	AdjacencyMatrix adjMatrix(vertices);
	getInput(file, adjList, adjMatrix);
	adjMatrix.printMatrix();

	cout << "\n\n\n----------------------------\n\n\n";
	adjList.printList();
	file.close();
}