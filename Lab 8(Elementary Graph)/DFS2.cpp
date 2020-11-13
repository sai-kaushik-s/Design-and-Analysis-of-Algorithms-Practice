#include "graph.h"
#include <list>
#include <iostream>

using namespace std;

bool visited[1000];
list<int> D;

list<int> DFS(Graph G, int s)
{
	struct node *temp = (struct node*)malloc(sizeof(G.N[s]));
	temp = G.N[s];

	visited[s] = true;
	D.push_back(s);

//cout << "Visited " << s << "\n";

	while(temp!=NULL)
	{
		int connectedvertex = temp->data;
		if(visited[connectedvertex] == 0)
		{
			DFS(G, connectedvertex);
		}
	temp = temp->next;
	}
	return D;
}

void clearGlobalList()
{
	D.clear();
}

void clearGlobalVisit(int n)
{
	for(int i=0; i<n; i++)
		visited[i] = false;
}
