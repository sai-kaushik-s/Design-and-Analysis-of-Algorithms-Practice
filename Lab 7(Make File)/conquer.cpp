#include"merge.h"

void merge(int a[], int beg1, int end1, int end2)
{
	int size1 = end1 - beg1 + 1;
	int size2 = end2 - end1;
	
	int l[size1], r[size2];
	
	for(int i=0; i<size1; i++)
		l[i] = a[beg1+i];
	
	for(int i=0; i<size2; i++)
		r[i] = a[end1+i+1];
		
	int k=beg1, k1=0, k2=0;
	
	while(k1<size1 && k2<size2)
	{
		if(l[k1] < r[k2])
		{
			a[k] = l[k1++];
		}
		else
		{
			a[k] = r[k2++];
		}
		k++;
	}
	
	while(k1<size1)
	{
		a[k++] = l[k1++];
	}
	
	while(k2<size2)
	{
		a[k++] = r[k2++];
	}
		
}
