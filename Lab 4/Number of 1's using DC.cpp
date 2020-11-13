#include<stdio.h>
#include<stdlib.h>

int find1(int* a, int beg, int end);

int main()
{
	while(true){
		int s;
		printf("Enter which function you wish to perform: \n\t1)Find number of 1s\n\t2)Exit\n");
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
				printf("The number of 1s in the given array is:  %d\n\n", find1(a, 0, n - 1));
				break;
			}
			case 2:{
				exit(0);
				break;
			}
		}
	}
}

int find1(int* a, int beg, int end){
	if(beg == end){
		if(a[beg] == 1)
			return 1;
		return 0;
	}
	return find1(a, beg, (beg + end) / 2) + find1(a, (beg + end) / 2 + 1, end);
}
