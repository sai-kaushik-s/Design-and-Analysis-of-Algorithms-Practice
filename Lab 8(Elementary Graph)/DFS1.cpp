#include "graph.h"
#include <list>
#include <iostream>

using namespace std;


list<int> DFS(Graph G)
{
	list<int> D;
	D=DFS(G,0);
	return D;
}
