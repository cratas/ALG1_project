#include <iostream>
#include "BFSIterator.cpp"
#include "DFSIterator.cpp"
#include "Graph.cpp"

using namespace std;

int main()
{   
    int i = 0;
    Graph* graph1 = new Graph("Graf1.txt");
    Graph* graph2 = new Graph("Graf3.txt");

    DFSIterator* dfsIterator = new DFSIterator(graph1);
    BFSIterator* bfsIterator = new BFSIterator(graph2);

    dfsIterator->Reset();
    while(!dfsIterator->IsEnd())
    {
        dfsIterator->Next();
        cout << "prvek: " << dfsIterator->CurrentKey() << endl;
    }  

    cout << "\n-------\n";

    bfsIterator->Reset();
    while(!bfsIterator->IsEnd())
    {
        bfsIterator->Next();
        cout << i << " prvek: " << bfsIterator->CurrentKey() << endl;
        i++;
    }  

    delete graph1;
    delete graph2;
    delete dfsIterator;
    delete bfsIterator;


	return 0;
}
