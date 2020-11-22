#include "Graph.h"
#pragma once
#include <iostream>
#include <list>

using namespace std;

class BFSIterator
{
private:
    Graph* graph;
    list<int> queue; 
    bool *isDone;
    int verticesCount;
    int minValue;
    int currentKey;

public:
    BFSIterator(Graph* graph);
    ~BFSIterator();
    void Reset();
    void Next();
    bool IsEnd();
    int CurrentKey();
    
};
