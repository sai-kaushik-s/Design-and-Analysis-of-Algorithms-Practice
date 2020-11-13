#include<stdio.h> //logic 1 : Incremental Design
#include<stdlib.h>

void merge(int* arr, int l, int m, int r);

int main(){
	int k;
	printf("Enter the number of arrays:  ");
	scanf("%d", &k);
	int** a;
	a = (int**)malloc(k * sizeof(int*));
	int size[k], count = 0;
	for(int i = 0; i < k; i++){
		printf("Enter the size of array %d:  ", i + 1);
		scanf("%d", &size[i]);
		count += size[i];
		a[i] = (int*)malloc(size[i] * sizeof(int));
		for(int j = 0; j < size[i]; j++){
			printf("Enter the value %d:  ", j + 1);
			scanf("%d", &a[i][j]);
		}
	}
	int c[count], l = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < size[i]; j++)
			c[l++] = a[i][j];
	}
	int m = size[0] - 1, r = m + size[1];
	for(int i = 2; i <= k; i++){
		merge(c, 0, m, r);
		m = r;
		r += size[i];
	}
	printf("The sorted array: ");
	for(int i = 0; i < count; i++)
		printf("%d  ", c[i]);
}

void merge(int* arr, int l, int m, int r){ 
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
        
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while (i < n1)
        arr[k++] = L[i++];    
    while (j < n2) 
        arr[k++] = R[j++];
}


