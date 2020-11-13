#include <bits/stdc++.h>  //n+logn-2 logic
using namespace std; 

struct Node 
{ 
    int num; 
    Node *left;
    Node *right; 
}; 

void findSecondMin(int arr[], int n);
void traverseHeight(Node *root, int arr[], int &res);
int main()
{
    int a[1000]; int n; int min1; int min2; 
    
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    
    printf("Enter the elements of the array\n");
    for(int i = 0; i < n; i = i+1)
    {
        scanf("%d",&a[i]);
    }
    
    printf("The entered array is :-\n");
    for(int i = 0; i < n; i = i+1)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n");
    
    findSecondMin(a,n);
}

Node *createNode(int num) 
{ 
    Node *top = new Node; 
    top->left = top->right = NULL; 
    top->num = num; 
    return top; 
} 
 
void traverseHeight(Node *root, int arr[], int &res) 
{ 
    
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return; 
    
    if (res > arr[root->left->num] && root->left->num != root->num) 
    { 
        res = arr[root->left->num]; 
        traverseHeight(root->right, arr, res); 
    } 
 
    else if (res > arr[root->right->num] && root->right->num != root->num) 
    { 
        res = arr[root->right->num]; 
        traverseHeight(root->left, arr, res); 
    } 
} 
 
void findSecondMin(int arr[], int n) 
{ 
    list<Node *> li; 

    Node *root = NULL; 
    for (int i = 0; i < n; i += 2) 
    { 
        Node *top1 = createNode(i); 
        Node *top2 = NULL; 
        if (i + 1 < n) 
        { 
            top2 = createNode(i + 1); 

            root = (arr[i] < arr[i + 1])? createNode(i) : createNode(i + 1); 
            
            root->left = top1; 
            root->right = top2; 
 
            li.push_back(root); 
        } 
        else
            li.push_back(top1); 
    } 

    int lsize = li.size(); 
 
    while (lsize != 1) 
    { 
        int last = (lsize & 1)? (lsize - 2) : (lsize - 1); 

        for (int i = 0; i < last; i += 2) 
        { 
            Node *front1 = li.front(); 
            li.pop_front(); 

            Node *front2 = li.front(); 
            li.pop_front(); 
            root = (arr[front1->num] < arr[front2->num])? createNode(front1->num) : createNode(front2->num); 

            root->left = front1; 
            root->right = front2; 

            li.push_back(root); 
        } 
        if (lsize & 1) 
        { 
            li.push_back(li.front()); 
            li.pop_front(); 
        } 
        lsize = li.size(); 
    } 
 
    int res = INT_MAX; 
    traverseHeight(root, arr, res); 
    printf("Minimum is %d\n",arr[root->num]);
    printf("Second Minimum is %d\n",res); 
} 


