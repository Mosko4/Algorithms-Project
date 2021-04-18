#include <iostream>
#include <string>
#include <fstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "minArray.h"
#include "minHeap.h"

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

	fstream outFile;
	outFile.open(argv[2],fstream::out);
	if (!outFile)
		cout << "error" << endl;
	outFile << "Gideon ole ole" << endl;


	minHeap heap(6);
	minArray array(6);

	heap.insert(Item(1, 6));
	heap.insert(Item(2, 8));
	heap.insert(Item(3, 3));
	heap.insert(Item(4, 5));
	heap.insert(Item(5, 7));
	heap.insert(Item(6, 2));

	cout << heap.min().key << endl;
	heap.DecreaseKey(1, 1);
	cout << heap.min().key << endl;
	cout << heap.DeleteMin().key << endl;
	cout << heap.DeleteMin().key << endl << "----------------------------------" << endl;


	array.insert(Item(1, 6));
	array.insert(Item(2, 8));
	array.insert(Item(3, 3));
	array.insert(Item(4, 5));
	array.insert(Item(5, 7));
	array.insert(Item(6, 2));
	cout << array.min().key << endl;
	array.DecreaseKey(1, 1);
	cout << array.min().key << endl;
	cout << array.DeleteMin().key << endl;
	cout << array.DeleteMin().key << endl;
	file.close();
}