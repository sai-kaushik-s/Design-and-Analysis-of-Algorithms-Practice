#include"graph.h"

void Test_bridges(Graph G){
	int count = 0;
	for(int i = 0; i < G.n; i++){
		struct node* temp = G.N[i];
		while(temp){
			if(i < temp->data){
				int j = temp->data;
				int w = temp->weight;
				G.deleteEdge(i, j);
				if(!BFS(G, i, j)){
					cout<<i<<"-->"<<j<<" is a bridge"<<endl;
					count++;
				}
				G.insertEdge(i, j, w);
			}
			temp = temp->next;
		}
	}
	if(count == 0)
		cout<<"There are no bridges"<<endl;
}
