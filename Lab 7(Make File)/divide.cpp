#include"merge.h"

void mergeSort(int a[], int beg1, int end2)
{
	int end1 = (beg1+end2)/2;
	if(beg1 < end2)
	{
		mergeSort(a, beg1, end1);
		mergeSort(a, end1+1, end2);
		merge(a, beg1, end1, end2);
	}
}
