#include "DFSIterator.h"

DFSIterator::DFSIterator(Graph* graph)
{
    this->graph = graph; 
    this->verticesCount = graph->GetVerticesCount();
    this->minValue = graph->GetMinValue();

    isDone = new bool[verticesCount];

    for(int i = 0; i < verticesCount; i++) 
    {
        isDone[i] = false; 
    }  
}

DFSIterator::~DFSIterator()
{
    delete[] isDone;
}

void DFSIterator::Reset()
{
    stack.push(minValue);
    isDone[minValue] = true;
    currentKey = stack.top(); 
}

void DFSIterator::Next()
{
    currentKey = stack.top();
    list<int>::iterator i;
    
    if(!stack.empty())
    {
        stack.pop();
        for (i = graph->GetVertices()[currentKey].begin(); i != graph->GetVertices()[currentKey].end(); ++i)
        {
            if(!isDone[*i]) 
            { 
                isDone[*i] = true;
                stack.push(*i);
            } 
        }
    }
    
    if(stack.empty())
    {
        for(int i = 0; i < verticesCount; i++) 
        {
            if(isDone[i] == false)
            {               
                stack.push(i);
                isDone[i] = true;

                break;
            }
        }
    }
}

bool DFSIterator::IsEnd()
{
   bool allTrue = true;

   for(int i = 0; i < verticesCount; i++) 
    {
        if(isDone[i] == true )
        {
            allTrue = true;
        }
        else
        {
            allTrue = false;
            break;
        }
    }

    if(allTrue && stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int DFSIterator::CurrentKey()
{
    return currentKey;
}  