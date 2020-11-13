#include "graph.h"
#include<list>
#include<iostream>

using namespace std;

bool reach=false;

bool DFS(struct Graph G, int s, int t)
{
    list<int> D;
    D=DFS(G,s);

    list<int> :: iterator i;
    for(i=D.begin();i!=D.end();i++)
    {
        if(*i == t)
        return true;
    }

    return false;
}
