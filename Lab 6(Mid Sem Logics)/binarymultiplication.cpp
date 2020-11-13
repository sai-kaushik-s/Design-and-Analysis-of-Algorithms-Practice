include<iostream>  //convert the given decimal number into binary number and then multiplication is performed
#include<cmath>  // yields logn^2 running time
using namespace std;
int ba(int,int);
int bm(int,int);
int dectobin(int);
int main()
{
    int n1,n2;
    cout<<"Enter a number:";
    cin>>n1;
    n2=dectobin(n1);
    int res=bm(n2,n2);
    cout<<"Square of the number in binary format:"<<res<<endl;
    return 0;
}
int bm(int b1,int b2)
{
    int q=b2;
    int r,tsum,sum=0,count=0;
    while(q!=0)
    {
        r=q%10;
        tsum=(r>0)?b1:0;
        sum=ba(tsum*pow(10,count),sum);
        count++;
        q/=10;
    }
    return sum;
}
int ba(int b1,int b2)
{
    int q1,r1,q2,r2,tsum=0,carry=0;
    int sum=0;
    int count=0;
    q1=b1;
    q2=b2;
    while(q1!=0||q2!=0)
    {
        r1=q1%10;
        r2=q2%10;
        tsum=(r1+r2+carry)%2;
        carry=(r1+r2+carry)/2;
        sum=tsum*pow(10,count)+sum;
        count++;
        q1/=10;
        q2/=10;
    }
    sum=carry*pow(10,count)+sum;
    return sum;
}
int dectobin(int n)
{
    int sum=0;
    int count=0;
    int q=n;
    int r;
    while(q!=0)
    {
        r=q%2;
        sum=pow(10,count)*r+sum;
        count++;
        q/=2;
    }
    return sum;
}
   