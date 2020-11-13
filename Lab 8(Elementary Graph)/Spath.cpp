#include<cstdlib>
#include<vector>
#include<limits.h>
#include"graph.h"
#include<queue>


using namespace std;

vector<int> BFS_SPATH(Graph G, int s, bool flag)
{
    bool visited[G.n];
    for (int i = 0; i < G.n; i++)
        visited[i] = false;
    vector<int> dist;
    vector<int> paths;
    for (int i = 0; i < G.n; i++)
    {
        dist.push_back(INT_MAX);
        paths.push_back(0);
    }

    dist[s] = 0;
    paths[s] = 1;

    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        struct node* temp = G.N[curr];
        while(temp != NULL)
        {
            int x = temp->data;
            int w = temp->weight;
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }

                    if(flag==false)
                    {

                        if (dist[x] > dist[curr] + 1)
                        {
                            dist[x] = dist[curr] + 1;
                            paths[x] = paths[curr];
                        }


                        else if (dist[x] == dist[curr] + 1)
                            paths[x] += paths[curr];
                    }
                    else
                    {
                        // check if there is a better path.
                        if (dist[x] > dist[curr] + w)
                        {
                            dist[x] = dist[curr] + w;
                            paths[x] = paths[curr];
                        }

                        // additional shortest paths found
                        else if (dist[x] == dist[curr] + w)
                            paths[x] += paths[curr];
                    }

            temp=temp->next;

    }
}
    return dist;

}
