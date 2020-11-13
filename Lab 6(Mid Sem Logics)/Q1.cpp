#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the values in array : ");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	
	int min,smin;
	
	if(a[0]<a[1])
	{
		min = a[0];
		smin = a[1];
	}
	else
	{
		min = a[1];
		smin = a[0];
	}

	for(i=2;i<n;i++)
	{
		if(a[i]<smin)
		{
			if(a[i]<min)
			{
				smin = min;
				min = a[i];
			}
			else
			{
				smin = a[i];
			}
		}
	}
	
	
	printf("The first minimum element and second minimum element of array is : %d , %d \n",min,smin);
	
	return 0;
	
}
	


