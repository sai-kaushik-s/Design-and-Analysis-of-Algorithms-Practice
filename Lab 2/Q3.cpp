#include<Stdio.h>
int main()
{
	int n;
	printf("Please enter any number :");
	scanf("%d",&n);
	int i,j,k;
	printf("The different patterns for entered number is\n");
	
	for(i=n;i>0;i--) //pattern 1
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
	printf("\n");
	
	int space = 0;
	
	for(i=0;i<n;i++) //pattern 2
	{
		while(space--)
			printf("  ");
		for(j=i+1;j<=n;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
			space = i+1;
	}
	printf("\n");
	
	for(i=1;i<=n;i++) //pattern 3
	{
		for(j=1;j<i+1;j++)
		{
			printf("%d ",j);
		}
		
		printf("\n");
	}
	printf("\n");
	
	for(i=n;i>0;i--) //pattern 4
	{
		for(k=1;k<=i-1;k++)
			printf("  ");
			
			for(j=k;j<=n;j++)
				printf("%d ",j);
		
		printf("\n");	
	}
	printf("\n");
	
	for(i=0;i<(n/2);i++) //pattern 5
	{
		for(k=0;k<i;k++)
			printf("  ");
			
		for(j=i+1;j<=n-i;j++)
			printf("%d ",j);
		
		printf("\n");
	}	
	
	if(n%2 != 0)
	{
		for(k=n/2;k>0;k--)
			printf("  ");
		
		printf("%d\n",(n/2)+1);
	}
	
	for(i=n/2;i>0;i--)
	{	
		for(k=i-1;k>0;k--)
			printf("  ");
			
		for(j=i;j<=n+1-i;j++)
			printf("%d ",j);
			
		printf("\n");
	}
	

	return 0;
}
