#include "BFSIterator.h"

BFSIterator::BFSIterator(Graph* graph)
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

BFSIterator::~BFSIterator()
{
    delete[] isDone;
}

void BFSIterator::Reset()
{
    queue.push_back(minValue);
    isDone[minValue] = true;
    currentKey = queue.front(); 
}

void BFSIterator::Next()
{
    currentKey = queue.front();
    list<int>::iterator i;

    if(!queue.empty())
    {
        queue.pop_front();
        for (i = graph->GetVertices()[currentKey].begin(); i != graph->GetVertices()[currentKey].end(); ++i)
        {
            if(!isDone[*i]) 
            {            
                isDone[*i] = true; 
                queue.push_back(*i); 
            } 
        }
    }
    if(queue.empty())
    {
        for(int i = 0; i < verticesCount; i++) 
        {
            if(isDone[i] == false)
            {
                queue.push_back(i);
                isDone[i] = true;

                break;
            }
        }
    }
}

bool BFSIterator::IsEnd()
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

    if(allTrue && queue.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}  

int BFSIterator::CurrentKey()
{
    return currentKey;
}