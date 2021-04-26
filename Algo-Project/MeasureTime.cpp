#include "MeasureTime.h"


void MeasureTime::measureComplexity(int vertices, int source, int dest, const AdjacencyList& adjList, const AdjacencyMatrix& adjMatrix, const char* fileName)
{
	AlgorithmUtil algoUtil(source, vertices);

	measureDijkstra_Heap(fileName, adjList, source, algoUtil, dest);
	cout << "Adjacency Dijkstra heap " << algoUtil.getWeight(dest) << endl;
	measureDijkstra_Array(fileName, adjList, source, algoUtil);
	cout << "Adjacency Dijkstra array " << algoUtil.getWeight(dest) << endl;
	measureBellmanFord(fileName, adjList, source, algoUtil);
	cout << "Adjacency Bellman Ford " << algoUtil.getWeight(dest) << endl;

	measureDijkstra_Heap(fileName, adjMatrix, source, algoUtil);
	cout << "Matrix Dijkstra heap " << algoUtil.getWeight(dest) << endl;
	measureDijkstra_Array(fileName, adjMatrix, source, algoUtil);
	cout << "Matrix Dijkstra array " << algoUtil.getWeight(dest) << endl;
	measureBellmanFord(fileName, adjMatrix, source, algoUtil);
	cout << "Matrix Bellman Ford " << algoUtil.getWeight(dest) << endl;
}

void MeasureTime::measureDijkstra_Heap(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil, int dest)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Dijkstra_Heap(adjList, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	if (algoUtil.d[dest - 1].Inf)
	{
		cout << "No route from " << source << " to " << dest << endl;
		invalid_input;
	}

	ofstream myfile(fileName); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Dijkstra heap is :\t" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void MeasureTime::measureDijkstra_Array(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Dijkstra_Array(adjList, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(fileName, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Dijkstra array is :" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void MeasureTime::measureBellmanFord(const char* fileName, const AdjacencyList& adjList, int source, AlgorithmUtil& algoUtil)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Bellman_Ford(adjList, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(fileName, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Adjacency Bellman Ford is :\t" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void MeasureTime::measureDijkstra_Heap(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Dijkstra_Heap(adjMatrix, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(fileName, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Dijkstra heap is :\t" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void MeasureTime::measureDijkstra_Array(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Dijkstra_Array(adjMatrix, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(fileName, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Dijkstra array is :\t" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}

void MeasureTime::measureBellmanFord(const char* fileName, const AdjacencyMatrix& adjMatrix, int source, AlgorithmUtil& algoUtil)
{
	auto start = chrono::high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	Bellman_Ford(adjMatrix, source, algoUtil);

	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	ofstream myfile(fileName, ios::app); // The name of the file which is in argv[2]

	myfile << "Time taken by function Matrix Bellman Ford is :\t\t" << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}
