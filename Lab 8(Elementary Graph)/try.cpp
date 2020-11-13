
#include<iostream>
#include<list>
#include<set>
#include <bits/stdc++.h>

using namespace std;


void print_list(list<int> l){
    for(auto l1 : l){
        cout<<l1<<" ";
    }
    cout<<endl;
}
/* 1. MAIN FOR TESTING LIST, VECTOR, SET FUNTION
int main()
{
	list<int> s;
	set<int> p;
	s.push_back(4);
	s.push_back(3);
	s.push_back(1);
	s.push_back(3);
	s.push_back(6);

	for(auto l1 : s)
	{
		p.insert(l1);
	}

	cout<<"Printing all the element from the set.\n";
    set<int>::iterator iter;
    for(iter=p.begin(); iter!=p.end(); iter++){
        cout<<*iter<<" ";
    }

		set<int> s2;
		s2 = {1,3,3,4,6};

		if(p!=s2)
		{
			cout<<"not Equal";
		}
		else
		{
			cout<<"Equal";
		}

return 0;
}
*/

/*2. TRY MST_Kruskal
int main()
{
  	Graph G;
  	Graph K;
  	G.n = 8;
  	K.n = 8;

  	for(int i=0; i<G.n; i++)
	{
		G.N[i] = NULL;
	}

  	for(int i=0; i<G.n; i++)
	{
		K.N[i] = NULL;
	}

  	G.insertEdge(0,1,3);
  	G.insertEdge(0,2,2);
  	G.insertEdge(1,2,6);
  	G.insertEdge(1,3,4);
  	G.insertEdge(2,3,2);
  	G.insertEdge(2,4,5);
  	G.insertEdge(3,4,1);
  	G.insertEdge(3,5,10);
  	G.insertEdge(3,6,8);
  	G.insertEdge(4,6,7);
  	G.insertEdge(6,7,3);

  	G.insertEdge(1,0,3);
  	G.insertEdge(2,0,2);
  	G.insertEdge(2,1,6);
  	G.insertEdge(3,1,4);
  	G.insertEdge(3,2,2);
 	G.insertEdge(4,2,5);
  	G.insertEdge(4,3,1);
  	G.insertEdge(5,3,10);
 	G.insertEdge(6,3,8);
  	G.insertEdge(6,4,7);
  	G.insertEdge(7,6,3);

  	K = MST_Kruskal(G);

  	K.print();

}
*/

