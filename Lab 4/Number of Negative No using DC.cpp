#include<stdio.h>
#include<stdlib.h>

int finding_negative(int *a,int beg,int end);

int main()
{
	int s;
	while(true)
	{
		printf("Enter which function you want to perform\n\t1.)No of Negative Numbers\n\t2.)Exit\n");
		scanf("%d",&s);
		printf("\n");
		switch(s)
		{
			case 1:
			{
				int i,n;
				printf("Enter the number of elements in an array : ");
				scanf("%d",&n);
				int a[n];
				for(i=0;i<n;i++)
				{
					printf("Enter the number %d : ",i+1);
					scanf("%d",&a[i]);
				}
				printf("Total number of Negative numbers you entered : %d\n\n",finding_negative(a,0,n-1));
				break;
			}
			case 2:
				{
					exit(0);
				}
		}
	}
	return 0;
}


int finding_negative(int *a,int beg,int end)
{
	if(beg == end)
	{
		if(a[beg]<0)
			return 1;
		return 0;
	}
	
	return finding_negative(a,beg,(beg+end)/2) + finding_negative(a,(beg+end)/2 + 1,end);

}
