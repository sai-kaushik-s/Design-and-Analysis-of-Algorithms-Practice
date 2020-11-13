#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int suml=0,sumr=0;
    int diff=0;
    cout<<"Enter the size of the array:";
    cin>>N;
    int arr[N];
    int M=N/2;
    int left[M];
    int right[M];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    for(int j=0;j<M;j++)
    {
        left[j]=arr[j];
        suml+=arr[j];
        right[j]=arr[M+j];
        sumr+=arr[M+j];
    }
    diff=sumr-suml;
    for(int i=0;i<M;i++)
    {
        for(int j=M-1;j>=0;j--)
        {
            if(left[j]<right[i])
            {
                int temp;
                temp=abs(diff-(2*(abs(left[j]-right[i]))));
                if(temp<diff)
                {
                    left[j]=left[j]^right[i];
                    right[i]=left[j]^right[i];
                    left[j]=left[j]^right[i];
                    diff=temp;
                }
            }
        }
    }
    cout<<"Left array:";
    for(int i=0;i<M;i++)
        cout<<left[i]<<" ";
    cout<<"Right array:";
    for(int i=0;i<M;i++)
        cout<<right[i]<<" ";
    cout<<endl;
    return 0;
}