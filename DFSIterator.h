#include "Graph.h"
#pragma once
#include <iostream>
#include <list>
#include <stack>

using namespace std;

class DFSIterator
{
private:
    Graph* graph;
    stack<int> stack; 
    bool *isDone;
    int verticesCount;
    int minValue;
    int currentKey;

public:
    DFSIterator(Graph* graph); 
    ~DFSIterator(); 
    void Reset();
    void Next();
    bool IsEnd();
    int CurrentKey();
    
};
