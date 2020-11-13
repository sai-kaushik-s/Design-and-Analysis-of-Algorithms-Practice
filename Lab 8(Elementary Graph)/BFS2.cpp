#include"graph.h"
#include<queue>
#include<cstdlib>

using namespace std;



list<int> BFS(Graph G, int s)
{
	list<int> D;
	bool visit[G.n];
	queue<int> Q;
	
	for(int i = 0; i<G.n; i++){    
		visit[i] = false;
	}

	visit[s] = true;
	Q.push(s);
	struct node* temp;
	int x;
	int u;
	while(Q.empty() == 0){
		x = Q.front();
		Q.pop();
		temp = G.N[x];
		while(temp!=NULL){
			u = temp->data;
			if(visit[u] == 0){
				visit[u] = 1;
				D.push_back(u);
				Q.push(u);
				temp = temp->next;
			}
			else
				temp = temp->next;
		}
	}
	return D;
}