#include "Graph.h"

Graph::Graph(string Path)
{
	ifstream inputFile(Path,ios::in);

	inputFile >> verticesCount;
	edges = new list<int>[verticesCount]; 

	int vertexOne; 
	int vertexTwo;
	this->minValue = 999999999;
	
    for(int i = 0; inputFile >> vertexOne; i++)
	{	
		if(i == 0 || i%2 == 0)
		{
			vertexTwo = vertexOne;
		}
		else
		{
				edges[vertexTwo].push_back(vertexOne);
				edges[vertexOne].push_back(vertexTwo);

		}

		if(vertexOne < minValue)
		{
			minValue = vertexOne;
		}
	}
	inputFile.close();
}

Graph::~Graph()
{
	delete[] edges;
}

int Graph::GetVerticesCount()
{
	return verticesCount;
}

list<int>* Graph::GetVertices()
{
	return edges;
}

int Graph::GetEdgesCount()
{
	return edgesCount;
}

int Graph::GetMinValue()
{
	return minValue;
}
