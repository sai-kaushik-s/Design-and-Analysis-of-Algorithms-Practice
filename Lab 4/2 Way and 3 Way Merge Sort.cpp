#include<stdio.h>
#include<stdlib.h>

void mergeSort2(int* a, int l, int r);
void mergesort3(int* a, int start, int end);
void merge2(int* a, int l, int m, int r);
void merge3(int* arr, int start, int m, int n, int end);

int size;

int main(){
	while(true){
		int s;
		printf("Enter which function you wish to perform: \n\t1)2-Way Merge Sort\n\t2)3-Way Merge Sort\n\t3)Exit\n");
		scanf("%d", &s);
		switch(s){
			case 1:{
				int n;
				printf("Enter the length of the array:  ");
				scanf("%d", &n);
				int a[n];
				for(int i = 0; i < n; i++){
					printf("Enter the number %d:  ", i + 1);
					scanf("%d", &a[i]);
				}
				mergeSort2(a, 0, n - 1);
				printf("\nThe sorted array is: ");
				for(int i = 0; i < n; i++)
					printf("%d   ", a[i]);
				printf("\n\n");
				break;
			}
			case 2:{
				printf("Enter the length of the array:  ");
				scanf("%d", &size);
				int a[size];
				for(int i = 0; i < size; i++){
					printf("Enter the number %d:  ", i + 1);
					scanf("%d", &a[i]);
				}
				mergesort3(a, 0, size - 1);
				printf("\nThe sorted array is: ");
				for(int i = 0; i < size; i++)
					printf("%d   ", a[i]);
				printf("\n\n");
				break;
			}
			case 3:{
				exit(0);
			}
		}
	}
}

void mergeSort2(int* a, int l, int r){
    if (l < r){ 
        int m = (l + r) / 2;
        
        mergeSort2(a, l, m);
        mergeSort2(a, m+1, r);
  
        merge2(a, l, m, r);
    }
}

void merge2(int* a, int l, int m, int r){ 
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
        
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    
    while (i < n1)
        a[k++] = L[i++];    
    while (j < n2) 
        a[k++] = R[j++];
}

void merge3(int* arr, int start, int m, int n, int end){ 
	int i = start, j = m + 1, k = n + 1,l = start;
	int a[size];
	while(i <= m && j <= n && k <= end){ 
		if(arr[i] < arr[j] && arr[i] < arr[k])
			a[l++] = arr[i++];
		else if(arr[j] < arr[i] && arr[j] < arr[k])
			a[l++] = arr[j++];
		else
			a[l++] = arr[k++];
	}
 
	if(i > m){
		while(j <= n && k <= end){
			if(arr[j] < arr[k])
				a[l++] = arr[j++];
			else
				a[l++] = arr[k++];
		} 
		if(j > n)
			while(k <= end)
				a[l++] = arr[k++];
			if(k > end)
				while(j <= n)
					a[l++] = arr[j++];
	}
 
	if(j > n){
		while(i <= m && k <= end){
			if(arr[i] < arr[k])
				a[l++] = arr[i++];
			else
				a[l++] = arr[k++];
		}
		if(i > m)
			while(k <= end)
				a[l++] = arr[k++];
		if(k > end)
			while(i <= m)
				a[l++] = arr[i++];
	}

	if(k > end){
		while(j <= n && i <= m){
			if(arr[j] < arr[i])
				a[l++] = arr[j++];
			else 
				a[l++] = arr[i++];
		}
		if(j > n)
			while(i <= m)
				a[l++] = arr[i++];
			
		if(i > m)
			while(j <= n)
				a[l++] = arr[j++];
	}
	for(int p = start; p < l ;p++)
		arr[p] = a[p];
}

void mergesort3(int* a, int start, int end){
	if(start < end){
		int m = start + (end - start) / 3;
		int n = start + 2 * ((end - start) / 3);
		mergesort3(a, start,m);
		mergesort3(a, m + 1,n);
		mergesort3(a, n + 1,end);
		merge3(a, start, m, n, end);
	}
}
