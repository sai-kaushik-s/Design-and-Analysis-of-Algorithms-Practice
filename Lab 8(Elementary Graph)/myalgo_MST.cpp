#include"graph.h"


bool isConnected(Graph G) 
{ 
	
    clearGlobalList();
  	clearGlobalVisit(G.n);

  	list<int> l = DFS(G,0); //returns list of reachable vertices

    if(l.size()<G.n)//If it is less than the toal number of vertices then it is not connected
		return false; 
	return true; 
} 



Graph MST_youralgo(Graph G)
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


	int mst_wt = 0; // Initialize weight of MST 

	cout << "Edges in MST\n"; 

	// Iterate through all sorted edges in 
	// decreasing order of weights 
	for (int i=v.size()-1; i>=0; i--) 
	{ 
		int u1 = u[i];
		int v1 = v[i];

		
        G.deleteEdge(u1,v1);

		// Adding the edge back if removing it 
		// causes disconnection. In this case this 
		// edge becomes part of MST. 
		if (isConnected(G) == false) 
		{ 
            G.insertEdge(u[i],v[i],w[i]);  
		} 
	} 

    return G;
}
