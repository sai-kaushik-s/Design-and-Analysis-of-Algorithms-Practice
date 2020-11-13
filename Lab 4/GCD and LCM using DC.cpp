#include<stdio.h>
#include<stdlib.h>

int divide_GCD(int* a,int beg, int end);
int GCD(int a, int b);
int divide_LCM(int* a,int beg, int end);
int LCM(int a, int b);

int main(){
	while(true){
		int x;
		printf("Enter which function you wish to perform:\n\t1)GCD\n\t2)LCM\n\t3)Exit\n");
		scanf("%d", &x);
		switch(x){
			case 1:{
				int n;
				printf("Enter the length of the array:  ");
				scanf("%d", &n);
				int a[n];
				for(int i = 0; i < n; i++){
					printf("Enter the number %d:  ", i + 1);
					scanf("%d", &a[i]);
				}
				printf("The GCD of the given array is:  %d\n\n", divide_GCD(a, 0, n - 1));
				break;
			}
			case 2:{
				int n;
				printf("Enter the length of the array:  ");
				scanf("%d", &n);
				int a[n];
				for(int i = 0; i < n; i++){
					printf("Enter the number %d:  ", i + 1);
					scanf("%d", &a[i]);
				}
				printf("The LCM of the given array is:  %d\n\n", divide_LCM(a, 0, n - 1));
				break;
			}
			case 3:{
				exit(0);
				break;
			}
		}
	}
}

int divide_GCD(int* a,int beg, int end){
	if(beg == end)
		return a[beg];
    return GCD(divide_GCD(a, beg, (beg + end)/2), divide_GCD(a, (beg + end)/2 + 1, end));
}

int GCD(int a, int b){
	if(a < 0)
		a = -a;
	if(b < 0)
		b = -b;
	if(a == 0)
		return b;
	if(b == 0)
		return a;
    return GCD(b % a, a); 
}

int divide_LCM(int* a,int beg, int end){
	if(beg == end)
		return a[beg];
	return LCM(divide_LCM(a, beg, (beg + end)/2), divide_LCM(a, (beg + end)/2 + 1, end));
}

int LCM(int a, int b){
	if(a < 0)
		a = -a;
	if(b < 0)
		b = -b;
	int m = a, n = b;
	while(m != n){
		if(m > n)
			n += b;
		else
			m += a;
	}
	return m;
}
