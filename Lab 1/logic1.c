//Using Linear Checking
#include<stdio.h>
int greatest(int a,int b);
int gcditterative(int a,int b);
int gcdrecursion(int a,int b,int i,int gcd);
int grt;
int main()
{
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d %d",&a,&b);
	
	if(a<0)
		a = -a;
	if (b<0)
		b = -b;
		
	printf("GCD of given two numbers using itterative method is :");
	
	int gcd,gd;
	int j=1;
	
	grt = greatest(a,b);
	gcd = gcditterative(a,b);
	gd = gcdrecursion(a,b,1,0);
	printf("%d\n",gcd);
	printf("GCD of given two numbers using recursive method is :");
	printf("%d\n",gd);
	return 0;
}

int greatest(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
	
int gcditterative(int a,int b)
{
	int i,gcd;
	if(a!=0 || b!=0)
	{
		for(i=1;i<=grt;i++)
		{
			if(a%i==0 && b%i==0)
			gcd = i;
		}
		return gcd;
	}
	else 
		return 0;
}

/*int gcdrecursion(int a,int b)
{
	if(a==0 || b==0)
		return 0;
	else if(a == b)
		return a;
	else if(a>b)
		return gcdrecursion(a-b,a);
	else
		return gcdrecursion(a,b-a);
}
*/

int gcdrecursion(int a,int b,int i,int gcd)
{
	if(i>grt)
		return gcd;
	else
	{
		if(a%i==0 && b%i==0)
			gcd=i;
		return gcdrecursion(a,b,i+1,gcd);
	}
}
	
