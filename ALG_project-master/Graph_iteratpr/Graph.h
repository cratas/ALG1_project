#pragma once
#include <iostream>
#include <list>
#include <fstream>


using namespace std;

class Graph
{
private:
    list<int> *edges; 
    int verticesCount;
    int edgesCount;
    int minValue;

public:
    Graph(string Path);
    ~Graph();
    int GetVerticesCount();
    list<int>* GetVertices();
    int GetEdgesCount();
    int GetMinValue();
    
};