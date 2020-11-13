#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;

struct node
{
	int data;
	int weight;
	struct node *next;
};

struct node* myinsert(int data, struct node *head, int w);
void printList(struct node *head);
void myDelete(int data,struct node *head);

class Graph
{
	public :

	int n;
	struct node *N[100];

	//Graph()
	//{
		//for(int i=0; i<n; i++)
		//{
			//N[i] = NULL;
		//}
	//}

	void insertEdge(int n1, int n2, int w)
	{

		N[n1];
		struct node *myinsert=(struct node*)malloc(sizeof(struct node));
		myinsert->next = NULL;
		myinsert->data = n2;
		myinsert->weight = w;
		if(N[n1]!=NULL)
		{
		myinsert->next = N[n1]->next;
		N[n1]->next = myinsert;
		}
		else
		{
		N[n1]=myinsert;
		}
	}

	void deleteEdge(int n1,int n2)
	{
		struct node* temp = N[n1];
		struct node* prev;
		if(N[n1]->data == n2)
			N[n1] = N[n1]->next;
		else{
			while(temp){
				if(temp->data == n2){
					prev->next = temp->next;
					break;
				}
				prev = temp;
				temp = temp->next;
			}
		}
	}

	void print()
	{
		cout<<"---------------------Graph Adj List-------------------"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<i<<"-->";
			struct node *temp = N[i];
			while(temp!=NULL)
			{
			cout << temp->data << ", ";
			temp = temp->next;
			}
			cout<<endl;
		}
	}

};

bool DFS(Graph G, int s, int t);
list<int> DFS(Graph G, int s);
list<int> DFS(Graph G);

bool BFS(Graph G, int s, int t);
list<int> BFS(Graph G, int s);
list<int> BFS(Graph G);

vector<int> BFS_SPATH(Graph G, int s, bool flag);

vector<int> LPATH(Graph G, bool flag);

Graph MAX_Weight_MST(Graph G);

bool TEST_bipartite(Graph G);
void Test_articulationpoints(Graph G);
void Test_bridges(Graph G);

Graph MST_Prim(Graph G);
Graph MST_Kruskal(Graph G);
Graph MST_youralgo(Graph G);

void clearGlobalList();
void clearGlobalVisit(int n);
void clearReach();

set<int> findSet(Graph G,int u);
