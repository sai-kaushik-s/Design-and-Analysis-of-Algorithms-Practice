#include<iostream> //To check whether a given number is prime number using theta(n^1.5)
#include<cmath>
using namespace std;
bool divide(int,int);
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int m=sqrt(n);
    int count=0;
    for(int j=2;j<=m;j++)
    {
        if(divide(n,j))
            count++;
    }
    if(count)
        cout<<n<<" is not a prime number"<<endl;
    else
        cout<<n<<" is a prime number"<<endl;
    return 0;
}
bool divide(int n,int d)
{
    char str[n+1]="";
    for(int i=0;i<n;i++)
        str[i]='1';
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count==d-1)
            str[i]='$';
        count=(count+1)%d;
    }
    if(str[n-1]=='1')
        return false;
    else
        return true;
}