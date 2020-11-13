#include<iostream>
using namespace std;

#include"merge.h"

#define max_size 100

int main()
{
	int n, a[max_size];
	
	cout << "\nEnter array size : " ;
	cin >> n;
	
	cout << "\nEnter array : ";
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	mergeSort(a, 0, n-1);
	cout << "\nSorted array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " " ;

return 0;
}

