#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000

int main(){
	int a[MAX], n = 0, x, y;
	printf("Enter the numbers(The input ends when you enter the first '-1')\nEnter the number 1 :  ");
	while(true){
		scanf("%d",&a[n++]);
		if(a[n - 1] == -1)
			break;
        printf("Enter the number %d :  ", n + 1);
    }
    for(int i = n; i < MAX; i++)
    	a[i] = -1;
    printf("\n1st LOGIC\nThe first '-1' is at position %d\n", n);
    for(int i = 0; i < MAX; i++)
    	if(a[i] == -1){
    		x = i;
    		break;
		}
    printf("\n2nd LOGIC\nThe first '-1' is at position %d\n", x + 1);
    int beg = 0, end = 1;
    float q = 0;
    while(q < log(MAX) / log(2)){
    	if(a[end] == -1){
    		for(int i = beg; i < end; i++)
				if(a[i] == -1){
    				y = i;
    				break;
				}
		}
		else{
			beg = end;
			end *= 2;
			if(end >= MAX)
				end = MAX - 1;
		}
		q++;
	}
    printf("\n3rd LOGIC\nThe first '-1' is at position %d\n", y + 1);
}
