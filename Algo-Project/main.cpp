#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define rcastc reinterpret_cast<char*>

void main(int argc, char** argv)
{
	string fileName = argv[1];
	fstream file;
	file.open(fileName);
	if (!file)
	{
		cout << "Invalid input" << endl;
		exit(1);
	}
	string vertices, source, dest, currentNum;

	file >> vertices;
	atoi(vertices);
	file >> source;
	file >> dest;
	atoi(source);
	atoi(dest);
	while (!file.eof())
	{
		file >> currentNum;
		cout << currentNum << endl;
	}

	//file.read(rcastc(vertices), sizeof(int));




	file.close();
}