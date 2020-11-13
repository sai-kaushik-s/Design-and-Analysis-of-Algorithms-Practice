//using euclidean algorithm
#include<stdio.h>
int gcditterative(int a,int b);
int gcdrecursion(int a,int b);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

int main()
{
	int n;
	printf("Enter the number of numbers you want to insert : \n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the numbers\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	bubbleSort(a,n);
	printf("Array in ascending order is :");
	printArray(a,n);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]<0)
			a[i] = -a[i];
		else
			a[i] = a[i];
	}
	
	int p = gcditterative(a[0],a[1]);
	int o;
	
	for(int i=2; i<n;i++)
	{
		o = gcditterative(p,a[i]);
		p = o;
	}	
	
	printf("GCD of given numbers is :");
	printf("%d",o);
	return 0;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)         
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int gcditterative(int a,int b)
{
	while(a!=0)
	{
		int d = a;
		a = b%a;
		b = d;
	}
	return b;
}


int gcdrecursion(int a,int b)
{
	if(a==0)
		return b;
	else
		return gcdrecursion(b%a,a);
}
	
