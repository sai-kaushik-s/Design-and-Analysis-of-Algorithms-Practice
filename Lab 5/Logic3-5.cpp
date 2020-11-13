#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root = NULL;

struct heap
{
	int a[100];
	int last;
};
struct heap H;

void insertheap(int p);
int del();
void insert(int x);
void inorder(struct node *print);
int point(int a[][100],int *p,int *n,int k,int size);
int point2(int a[][100],int *p,int *n,int k,int size);

int main()
{
	while(true)
	{
		int s;
		printf("\nHere we are going to insert k sorted arrays and find the sorted array of the union of given array\n\nEnter which logic you want to perform : 
			\n\t1. Maintaining k pointers\n\t2. Construct BST\n\t3. Using Heap\n\t4. Exit\n ");
		scanf("%d",&s);
		switch(s)
		{		
			case 1 :{
						int k;
						printf("Enter the number of sorted arrays you want to enter : ");
						scanf("%d",&k);
						printf("\nWe are going to store all sorted arrays in 2d array where each row represents an array\n");
						int n[k];
						int x,y,size = 0;
						int a[k][100];
						for(x=0;x<k;x++)
						{
							printf("Enter the size of %d sorted array : ",x+1);
							scanf("%d",&n[x]);
							printf("Enter the %d sorted array : ",x+1);
							for(y=0;y<n[x];y++)
							{
								scanf("%d",&a[x][y]);
								size++;
							}
						}
						
						int p[k];
						for(int i=0;i<k;i++)
						{
							p[i] = 0;
						}
						
						printf("Sorted union of array is : \n");
						point(a,p,n,k,size);						
							printf("\n *************************************************** \n");
						break;
					}	
				
			case 2 :{
						int k;
						printf("Enter the number of sorted arrays you want to enter : ");
						scanf("%d",&k);
						printf("\nWe are going to store all sorted arrays in 2d array where each row represents an array\n");
						int n[k];
						int x,y;
						int a[k][100];
						for(x=0;x<k;x++)
						{
							printf("Enter the size of %d sorted array : ",x+1);
							scanf("%d",&n[x]);
							printf("Enter the %d sorted array : ",x+1);
							for(y=0;y<n[x];y++)
							{
								scanf("%d",&a[x][y]);
							}
						}
						
						for(x=0;x<k;x++)
						{
							for(y=0;y<n[x];y++)
							{
								insert(a[x][y]);
							}
						}
						printf("The sorted union of array's is : \n");
						inorder(root);
						
						printf("\n *************************************************** \n");
						break;
					}	
				
			case 3 :{	
						int k;
						printf("Enter the number of sorted arrays you want to enter : ");
						scanf("%d",&k);
						printf("\nWe are going to store all sorted arrays in 2d array where each row represents an array\n");
						int n[k];
						int x,y,size = 0;
						int a[k][100];
						for(x=0;x<k;x++)
						{
							printf("Enter the size of %d sorted array : ",x+1);
							scanf("%d",&n[x]);
							printf("Enter the %d sorted array : ",x+1);
							for(y=0;y<n[x];y++)
							{
								scanf("%d",&a[x][y]);
								size++;
							}
						}
						
						int p[k];
						for(int i=0;i<k;i++)
						{
							p[i] = 0;
						}
						
						H.last = 0;
						printf("Sorted union of array is : \n");
						point2(a,p,n,k,size);					
						printf("\n *************************************************** \n");
						break;
					}	
				
			case 4 :{
						exit(0);
						break;
					}	
				
		}
	}
	
	return 0;
}


void insert(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;	
	temp->left=NULL;
	temp->right=NULL;
	struct node *tptr = root;
	struct node *pptr = NULL;
	
	if (tptr== NULL)
	{
		root = temp;
	}
	
	else
	{
		while(tptr!=NULL)
		{
		pptr = tptr;			
			if(x<tptr->data)
				tptr = tptr->left;
			else
				tptr = tptr->right;
		}
		if(x<pptr->data)
			pptr->left = temp;
		else
			pptr->right = temp;
	}
}

void inorder(struct node *print)
{

	if(print!=NULL)
	{
		inorder(print->left);
		printf("%d ", print->data);
		inorder(print->right);
	}
}

int point(int a[][100],int *p,int *n,int k,int size)
{
	int z=0;
	while(z<size)
	{
		int min = 100000, index = 0;
		for(int i=0;i<k; i++)
		{
			if(p[i]>=n[i])
				continue;
			if(a[i][p[i]] < min)
			{
				min = a[i][p[i]];
				index = i;
			}
		}
			printf("%d  ",min);
			p[index]++;
			z++;
	}
	printf("\n");
}

int point2(int a[][100],int *p,int *n,int k,int size)
{
	int index;
	for(int i=0;i<k;i++)
	{
		insertheap(a[i][p[i]]);
	}
	while(H.last != 0)
	{
		int min = del();
		printf("%d ",min);
		
		for(int i=0;i<k;i++)
		{
			if(min == a[i][p[i]])
				index = i;
		}
		
		p[index]++;
			
		if(p[index]>=n[index])
			continue;
		insertheap(a[index][p[index]]);
	}
	printf("\n");
}

void insertheap (int p)
{
	H.last++;
	H.a[H.last] = p;
	int t = H.last;
	while((t/2 >= 1) && (H.a[t] <= H.a[t/2])) 
	{
		H.a[t] = H.a[t]+H.a[t/2];
		H.a[t/2] = H.a[t]-H.a[t/2];
		H.a[t] = H.a[t]-H.a[t/2];
		t= t/2;
	}
}

int del()
{
	int x = H.a[1];
	H.a[1] = H.a[H.last];
	H.last--;
	int t = 1;
	int mi;
	while(2*t <= H.last)
	{
		if(H.last >= 2*t+1)
		{
			if(H.a[2*t] > H.a[2*t+1])
				mi = 2*t ;
			else
				mi = 2*t + 1;
		}
		else
			mi = 2*t;
		if(H.a[t] > H.a[mi])
		{	
			H.a[t] = H.a[t] + H.a[mi]; 
		 	H.a[mi] = H.a[t] - H.a[mi]; 
		 	H.a[t] = H.a[t] - H.a[mi]; 
		 	t=mi;
		}
		else break;
	}
	return x;
}




