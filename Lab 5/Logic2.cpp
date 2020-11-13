#include<stdio.h> //logic 2 : Divide and Conquer
#include<stdlib.h>

void divide(int a[][100], int beg1, int end2, int size[]);
void merge(int a[][100], int beg1, int end1, int end2, int size[]);

int main()
{
	int k, a[100][100], tsize=0, size[40];
	printf("Enter the no of arrays you want to insert : ");
	scanf("%d",&k);
	
	for(int i=0; i<k; i++)
	{
		printf("Enter the size of Array %d : ",i+1);
		scanf("%d",&size[i]);
		tsize += size[i];
		for(int j=0; j< size[i]; j++)
		{
			printf("Enter the value %d of array %d : ",j+1,i+1);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	divide(a, 0, k-1, size);
	
	printf("The sorted union of array is :\n");
	for(int j=0; j<k; j++)
	for(int i=0; i<size[j]; i++)
	{
		printf("%d ",a[j][i]);
	}
	printf("\n");
	
	
return 0;
}

void divide(int a[][100], int beg1, int end2, int size[])
{
	int end1 = (beg1+end2)/2;
	if(beg1<end2)
	{
		divide(a, beg1, end1, size);
		divide(a, end1+1, end2, size);
		merge(a, beg1, end1, end2, size);
	}
}

void merge(int a[][100], int beg1, int end1, int end2, int size[])
{
	int l[100], r[100];
	int k=0;
	int b[100];
	int size1, size2;
	
	for(int j=beg1; j<=end1; j++)
	for(int i=0; i<size[j]; i++)
	{
		l[k++] = a[j][i];
	}
	size1=k;
	
	k=0;
	for(int j=end1+1; j<=end2; j++)
	for(int i=0; i<size[j]; i++)
	{
		r[k++] = a[j][i];
	}
	size2=k;
	
	k=0;
	int k1=0, k2=0;
	
	while(k1<size1 && k2<size2)
	{
		if(l[k1] < r[k2])
		{
			b[k] = l[k1++];
		}
		else
		{
			b[k] = r[k2++];
		}
		k++;
	}
	
	while(k1<size1)
	{
		b[k++] = l[k1++];
	}
	
	while(k2<size2)
	{
		b[k++] = r[k2++];
	}
	
	
	k=0;
	for(int j=beg1; j<=end2; j++)
	for(int i=0; i<size[j]; i++)
	{
		a[j][i] = b[k++];
	}
	
}
