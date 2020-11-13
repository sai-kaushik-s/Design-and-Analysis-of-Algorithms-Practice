#include<stdio.h> // sorting ternary array 
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node table[3];

int p = 0, q = 0;

void arrange1(int* a, int n);
void number(int* a, int n);
void arrange2(int* a, int n);
void swap(int *x, int *y);
void arrange3(int* a, int n);
void insert(int key);

int main(){
	int n;
	printf("Enter the length of the array:  ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		printf("Enter the number:  ");
		scanf("%d", &a[i]);
	}
	printf("\n1st LOGIC\n");
	arrange1(a, n);
	printf("\n2nd LOGIC\n");
	arrange2(a, n);
	printf("\n3rd LOGIC\n");
	arrange3(a, n);
}

void arrange1(int* a, int n) //logic 1
{
	number(a, n);
	int b[n];
	int l = 0, m = p, o = p + q;
	for(int i = 0; i < n; i++){
		if(a[i] == 0)
			b[l++] = 0;
		if(a[i] == 1)
			b[m++] = 1;
		if(a[i] == 2)
			b[o++] = 2;
	}
	printf("The arranged number is: ");
	for(int i = 0; i < n; i++){
		printf("%d  ", b[i]);
	}
}

void number(int* a, int n){
	for(int i = 0; i < n; i++){
		if(a[i] == 0)
			p++;
		if(a[i] == 1)
			q++;
	}
}

void arrange2(int* a, int n) //logic 2
{
	int c[n];
	for(int i = 0; i < n; i++)
		c[i] = a[i];
	for (int i = 0; i < n - 1; i++)    
    	for (int j = 0; j < n - i - 1; j++)
        	if (c[j] > c[j + 1])
            	swap(&c[j], &c[j + 1]);
    printf("The arranged number is: ");
	for(int i = 0; i < n; i++){
		printf("%d  ", c[i]);
	}
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void arrange3(int* a, int n) //logic 3
{
	int e = n - 1, d[n];
	for(int i = 0; i < 3; i++)
		table[i].next = NULL;
	for(int i = 0; i < n; i++)
		insert(a[i]);
	struct node* temp;
	for(int i = 2; i >= 0; i--){
		temp = table[i].next;
		while(temp != NULL){
			d[e--] = temp->data;
			temp = temp->next;
		}
	}
    printf("The arranged number is: ");
	for(int i = 0; i < n; i++){
		printf("%d  ", d[i]);
	}
}

void insert(int key){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = key;
	temp->next = table[key].next;
	table[key].next = temp;
}
