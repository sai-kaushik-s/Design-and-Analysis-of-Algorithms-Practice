#include"graph.h"
#include <list>
#include <iostream>
using namespace std;
#define NIL -1 

void APTransverse(int u, bool visited[], int disc[],int low[], int parent[], bool ap[],Graph G) 
{ 
    
    static int time = 0; 
  
    // Count of children
    int children = 0; 

    visited[u] = true; 
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    struct node *temp = (struct node*)malloc(sizeof(G.N[u]));
	temp = G.N[u];

    while(temp!=NULL)
    { 
        int v = temp->data;  // v 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APTransverse(v, visited, disc, low, parent, ap,G); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            //1)u is root of DFS tree and has two or more chilren. 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
  
            //2)If u is not root and low value of one of its child is more than discovery value of u
            //(meaning the child cant reach a earlier discovered node,hence it has no backedge)
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
        
        temp=temp->next;
    } 
} 

void Test_articulationpoints(Graph G)
{
    // Mark all the vertices as not visited 
    bool *visited = new bool[G.n]; 
    int *disc = new int[G.n]; 
    int *low = new int[G.n]; 
    int *parent = new int[G.n]; 
    bool *ap = new bool[G.n]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < G.n; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < G.n; i++) 
        if (visited[i] == false) 
            APTransverse(i, visited, disc, low, parent, ap,G); 
  
    
    cout<<"Articulation Points:-"<<endl;
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < G.n; i++) 
        if (ap[i] == true) 
            cout << i << " "; 
    cout<<endl;
}