#include"graph.h"
#include <bits/stdc++.h>

using namespace std;

set<int> findSet(Graph G,int u); // utility to get set of vertices reachable from vertex u

Graph MST_Kruskal(Graph G)       // Returns MST as an object of Class Graph
{
  	Graph K;
  	K.n = G.n;
                            //_
  	for(int i=0; i<G.n; i++)// |
  	{                       // |    
  		K.N[i] = NULL;      // |
  	}                       //_|

  	vector<int> u,v,w;  //u = list for edge vertex 1
                        //v = list for edge vertex 2
                		//w = list for edge weight

	//MAKE-SET (Start)-----------------Get edges weights in vectors for sorting
  	struct node *temp;
  	for(int i=0; i<G.n; i++)
  	{
      	temp = G.N[i];

      	while(temp!=NULL)
      	{
        	u.push_back(i);
        	v.push_back(temp->data);
        	w.push_back(temp->weight);

        	temp = temp->next;
      	}

  	}
  	//MAKE-SET (End)

  	//Bubble Sort (Start)--------------Sorting edges by weight value (asc)
  	for(int i=0; i<w.size()-1; i++)
    	for(int j=0; j<w.size()-i-1; j++)
    	{
      		if(w[j] > w[j+1])
      		{
        		swap(w[j], w[j+1]);
        		swap(u[j], u[j+1]);
        		swap(v[j], v[j+1]);
      		}
    	}
	//Bubble Sort (End)


  	for(int i=0; i<u.size(); i++)
  	{
    	if(findSet(K,u[i]) != findSet(K,v[i])) // Check if Vertex v[i] is reachable from vertex u[i] or not (Graph K)
    	{                                      //                           |__________|
      		K.insertEdge(u[i],v[i],w[i]);        //  If v[i] is not reachable from u[i], add edge(u,v)
    	}
  	}


  	return K;
}


set<int> findSet(Graph G,int u)      // utility to get set of vertices reachable from vertex u
{
	clearGlobalList();
  	clearGlobalVisit(G.n);

  	set<int> s;
  	list<int> l = DFS(G,u);

  	for(auto l1 : l)
  	{
		s.insert(l1);
    }

  	return s;
}
