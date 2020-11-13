#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void merge(int arr[],int start,int mid,int end);
void sort(int arr[],int start,int end,int size);

int main()
{
    srand(time(0));
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size;i++)
    {
        arr[i] = rand()%100000;
    }
    sort(arr,0,size - 1,size);
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}

void sort(int arr[],int start,int end,int size)
{
    if(size <= 10000)
    {
        int val,t;
        for(int i = start; i <= end; i++)
        {
            val = arr[i];
            int j = i - 1;
            while(j >= start && arr[j] > val)
            {
                arr[j + 1] = arr[j];
                j--;
            } 
            arr[j + 1] = val;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        sort(arr,start,mid,size/2);
        int remain = size - (size/2);
        sort(arr,mid + 1,end,remain);
        merge(arr,start,mid,end);
    }
    
}
void merge(int arr[],int start,int mid,int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int left[size1];
    int right[size2];

    int l = 0,r = 0,z = start;

    for(int i = 0; i < size1; i++)
    {
        left[i] = arr[z];
        z++;
    }
    for(int i = 0; i < size2; i++)
    {
        right[i] = arr[z];
        z++;
    }
    z = 0;
    while( l < size1 && r < size2)
    {
        if(left[l] < right[r])
        {
            arr[z] = left[l];
            l++;
        }
        else
        {
            arr[z] = right[r];
            r++;
        }
        z++; 
    }


    while(l < size1)
    {
        arr[z] = left[l];
        l++;
        z++;
    }
    
    while(r < size2)
    {
        arr[z] = right[r];
        r++;
        z++;
    }

}
