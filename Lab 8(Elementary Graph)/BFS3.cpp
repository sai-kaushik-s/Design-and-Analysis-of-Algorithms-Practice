#include "graph.h"
#include<cstdlib>
#include<queue>

using namespace std;

bool BFS(Graph G, int s, int t)
{
    queue<int> Q;
    bool visit[G.n];
    for(int i = 0; i < G.n; i++)
        visit[i] = false;
    visit[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        struct node* temp = G.N[x];
        int i;
        while(temp)
        {
            i = temp->data;
            if(!visit[i])
            {
                if(t == i)
                     return true;
                visit[i] = true;
                Q.push(i);
            }
            temp = temp->next;
        }
    }
    return false;
}
