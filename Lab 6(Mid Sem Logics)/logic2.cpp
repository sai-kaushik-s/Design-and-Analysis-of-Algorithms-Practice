#include<iostream> //finding the minimum and maximum in an array in ((3n/2)-2) comparisons
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int max,min;
    cout<<"Enter the size of array:";
    cin>>N;
    int arr[N];
    cout<<"Enter the elements:";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    if(N%2) //odd-sized array
    {   
        max=arr[0];
        min=arr[0];
        for(int i=1;i<N;i=i+2)
        {
            int maxt;
            int mint;
            if(arr[i]<arr[i+1])
            {
                mint=arr[i];
                maxt=arr[i+1];
            }
            else
            {
                mint=arr[i+1];
                maxt=arr[i];    
            }
            if(maxt>max)
                max=maxt;
            if(mint<min)
                min=mint;
        }   
    }
    else //even-sized array
    {
        if(arr[0]<arr[1])
        {
            min=arr[0];
            max=arr[1];
        }
        else
        {
            min=arr[1];
            max=arr[0];
        }
        for(int i=2;i<N;i=i+2)
        {
            int maxt;
            int mint;
            if(arr[i]<arr[i+1])
            {
                mint=arr[i];
                maxt=arr[i+1];
            }
            else
            {
                mint=arr[i+1];
                maxt=arr[i];    
            }
            if(maxt>max)
                max=maxt;
            if(mint<min)
                min=mint;
        }   
    }
    cout<<"Maximum element:"<<max<<endl;
    cout<<"Minimum element:"<<min<<endl;
    return 0;
}