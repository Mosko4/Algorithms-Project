#include <iostream>
#include <string>
#include <fstream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "minArray.h"
#include "minHeap.h"
#include "AlgorithmUtil.h"

using namespace std;
#define rcastc reinterpret_cast<char*>
#define invalid_input cout << "Invalid input" << endl; exit(1);


/*
		TODO:

	1. Valid input - check for simple graph 
	2. Algorithms 
	3. BFS ???
	4. add operator= delete

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
bool checkUpdateNumber(const string& str, float& num)
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
		num = atof(str.c_str());
		if (num < 0)
			validInput = false;
	}

	return validInput;
}

bool getVertexFile(string& str, int& vertex)
{
	bool validInput = true;
	string numStr;
	int indexBegin = 0, indexEnd;
	indexEnd = str.find_first_of(' ', indexBegin);

	for (int i = indexBegin; i < indexEnd; i++)
	{
		if (str[i] > '9' || str[i] < '0')
		{
			validInput = false;
			break;
		}
		else 
		{
			numStr.push_back(str[i]);
		}
	}

	str = string(str.c_str() + indexEnd + 1); // string str = string(char *str + indexBegin)
	vertex = atoi(numStr.c_str());
	return validInput;
	
}

bool getWeightFile(string& str, float& weight)
{
	bool validInput = true, firstDecimalPoint = false;
	string numStr;
	int indexBegin = 0, indexEnd;
	if (str.find_first_of(' ') != string::npos) // more than a single number
		validInput = false;
	else 
	{
		for (auto& itr : str)
		{
			if (itr == '.')
			{
				if (firstDecimalPoint)
					validInput = false;
				else
					firstDecimalPoint = true;
			}
			else if (itr > '9' || itr < '0')
				validInput = false;

			if (!validInput)
				break;
		}
			
		weight = stof(str,nullptr);
	}

	return validInput;
}

void getEdges(fstream& file, AdjacencyList& adjList, AdjacencyMatrix& adjMatrix)
{
	string currentRead;
	int vertices = adjMatrix.getNumVertices(), source, dest, vertex_i, vertex_j;
	float weight;
	bool valid1, valid2, valid3;

	


	// get edges and their weight
	while (!file.eof())
	{
		getline(file, currentRead);
		valid1 = getVertexFile(currentRead, vertex_i);
		valid2 = getVertexFile(currentRead, vertex_j);
		valid3 = getWeightFile(currentRead, weight);

		if (!valid1 || !valid2 || !valid3 ||
			vertex_i == vertex_j || vertex_i > vertices 
			|| vertex_j > vertices || adjMatrix.IsAdjacent(vertex_i, vertex_j))
		{
			invalid_input
		}


		adjList.AddEdge(vertex_i, vertex_j, weight);
		adjMatrix.AddEdge(vertex_i, vertex_j, weight);

	}
}


int checkLine(string& currentRead)
{
	string numberStr;
	for (auto& itr : currentRead)
	{
		if (itr >= '0' && itr <= '9') {
			numberStr.push_back(itr);
		}
		else if (itr != '\n' && itr != '\0')
		{
			invalid_input
		}
	}

	return stoi(numberStr,nullptr,10);
}

void getVertices(fstream& file, int& vertices, int& source, int& dest)
{
	string currentRead;

	// get no. of vertices, source and destination vertex
	getline(file, currentRead);
	vertices = checkLine(currentRead);
	getline(file, currentRead);
	source = checkLine(currentRead);
	getline(file, currentRead);
	dest = checkLine(currentRead);
	if (source > vertices || vertices < 1 || source < 1 || dest < 1 || dest > vertices)
	{
		invalid_input
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

	int vertices, source, dest;
	getVertices(file, vertices, source, dest);

	AdjacencyList adjList(vertices);
	AdjacencyMatrix adjMatrix(vertices);
	getEdges(file, adjList, adjMatrix);


	adjMatrix.printMatrix();
	cout << "\n\n\n----------------------------\n\n\n";
	adjList.printList();

	fstream outFile;
	outFile.open(argv[2], fstream::out);
	if (!outFile)
	{
		invalid_input
	}

	AlgorithmUtil algoUtil(source, vertices);
	Bellman_Ford(adjMatrix, source, algoUtil);

	if (algoUtil.d[dest - 1].Inf)
	{
		invalid_input;
	}

	cout << "Bellman Ford Matrix: " <<"Weight from " << source << " to " << dest << " is " << algoUtil.d[dest - 1].distance << endl;
	
	Bellman_Ford(adjList, source, algoUtil);
	cout << "Bellman Ford List: " << "Weight from " << source << " to " << dest << " is " << algoUtil.d[dest - 1].distance << endl;

	
	file.close();
}