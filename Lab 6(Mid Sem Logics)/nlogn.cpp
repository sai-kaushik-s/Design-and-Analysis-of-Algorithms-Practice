#include<iostream>//To check whether a given number is prime number or not in theta(nlogn)
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
    if(n==0)
        return true;
    else if(n<0)
        return false;
    else
        return divide(n-d,d);
}