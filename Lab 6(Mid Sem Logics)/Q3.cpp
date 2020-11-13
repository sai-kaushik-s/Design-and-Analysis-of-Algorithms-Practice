 #include<stdio.h>
  
  int main()
  {
  	int n;
  	printf("Enter the maximum increment in number of rounds on a given day : ");
  	scanf("%d",&n);
  	int a[n];
  	
  	int i;
  	
  	for(i=1;i<=n;i++)
	{
		a[i] = i;
	}
	
	printf("The schedule of person till that day where first schedule is of the day when he made n increments is \n");
	
	int end = n;
	int j = 2;
	
	while(end>1)
	{
		while(j<=end)
		{
			printf("%d " , j);
			j = j*2;
		}
		printf("\n");
		end = end/2;
		j=2;
	}
	
	return 0;
}
