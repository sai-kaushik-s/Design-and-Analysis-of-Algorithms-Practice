#include<stdio.h>
#include<stdlib.h>

struct Heap
{
	int a[50];
	int r; 
};

struct Heap Heap;

int check1(int* a, int n, int p);
int check2(int* a, int n, int p);
int check3(int* a, int n, int p);
void sort(int* a, int n);
int BS(int* a, int l, int r, int x);
void insert(int p);
int del();
void swap(int* m, int* n);

int main(){
	int n;
	printf("Enter the size of the array:  ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		printf("Enter the number %d : ", i + 1);
		scanf("%d", &a[i]);
	}
	int p;
	printf("Enter the number 'p': ");
	scanf("%d", &p);
	printf("\n1st LOGIC\n");
	if(check1(a, n, p))
		printf("There exist q and r in the array such that p = q + r\n");
	else
		printf("There does not exist q and r in the array such that p = q + r\n");
	printf("\n2nd LOGIC\n");
	if(check2(a, n, p))
		printf("There exist q and r in the array such that p = q + r\n");
	else
		printf("There does not exist q and r in the array such that p = q + r\n");
	printf("\n3rd LOGIC\n");
	if(check3(a, n, p))
		printf("There exist q and r in the array such that p = q + r\n");
	else
		printf("There does not exist q and r in the array such that p = q + r\n");
}

int check1(int* a, int n, int p) //logic 1
{
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(p == a[i] + a[j])
				return 1;
		}
	}
	return 0;
}

int check2(int* a, int n, int p) //logic 2
{
	Heap.r = 0;
	sort(a, n);
	int x;
	for(int i = 0; i < n; i++){
		x = p - a[i];
		if(BS(a, 0, n - 1, x))
			return 1;
	}
	return 0;
}

int check3(int* a, int n, int p) //logic 3
{
	Heap.r = 0;
	sort(a, n);
	int k = 0, l = n - 1;
	for(int i = 0; i < n; i++){
		if(a[k] + a[l] > p)
			k++;
		else if(a[k] + a[l] < p)
			l--;
		else
			return 1;
		if(2 * a[i] == p)
			return 1;
	}
	return 0;
}

void sort(int* a, int n){
	for(int i = 0; i < n; i++)
		insert(a[i]);
	for(int i = 0; i < n; i++)
		a[i] = del();
}

int BS(int* a, int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return 1;
        if (a[mid] > x)
            return BS(a, l, mid - 1, x);
        return BS(a, mid + 1, r, x);
    }
    return 0;
}

void insert(int p){
	Heap.r++;
	Heap.a[Heap.r] = p;
	int t = Heap.r;
	while((t/2 >= 1) && (Heap.a[t] <= Heap.a[t / 2])){
		swap(&Heap.a[t], &Heap.a[t/2]);
		t /= 2;
	}
}

int del()
{
	int x = Heap.a[1];
	Heap.a[1] = Heap.a[Heap.r];
	Heap.r--;
	int t = 1;
	int i;
	while(2*t <= Heap.r){
		if(2*t + 1 <= Heap.r){
			if(Heap.a[2*t] < Heap.a[2*t + 1])
				i = 2*t;
			else 
				i = 2*t+1;
		}
		else
			i = 2*t;
		if(Heap.a[t] > Heap.a[i]){
			swap(&Heap.a[t], &Heap.a[i]);
			t = i;
		}
		else
			break;
	}
	return x;
}

void swap(int* m, int* n){
	int temp = *m;
	*m = *n;
	*n = temp;
}
