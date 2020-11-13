#include"graph.h"
#include<queue>
#include<cstdlib>

using namespace std;

bool TEST_bipartite(Graph G){
    int color[G.n];
    for (int i = 0; i < G.n; ++i)
        color[i] = -1;
    
    color[0] = 1;
    queue <int> q;
    q.push(0);
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
		struct node* temp = G.N[u];
		while(temp!=NULL){
			int v = temp->data;
			if(color[v] == -1){
				color[v] = 1 - color[u];
                q.push(v);
			}
			else if(color[v] == color[u])
				return false;
			temp = temp->next;
		}
	}
	return true;
}
