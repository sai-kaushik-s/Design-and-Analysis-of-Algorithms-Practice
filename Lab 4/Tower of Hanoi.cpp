#include<stdio.h>
#include<stdlib.h>

void tower(int n,char source,char intermediate,char destination);

int main()
{
	int n;
	char A,B,C;
	printf("This program is for Tower of Hanoi problem\n");
	printf("Enter the number of disk in the source pillar : ");
	scanf("%d",&n);
	printf("In the output we will trace the algorithm for Tower of Hanoi\n");
	printf("Here,\n\tPillar A : Source pillar\n\tPillar B : Intermediate Pillar\n\tPillar C : Destination Pillar\n");
	printf("\n");
	printf("Output :\n");
	tower(n,'A','B','C');
	return 0;
	
}

void tower(int n,char source,char intermediate,char destination)
{
	if(n == 1)
	{
		printf("Move the Disk 1 from Pillar %c to Pillar %c\n",source,destination);
		return;
	}
	
	else
	{
		tower(n-1,source,destination,intermediate);
		printf("Move the disk %d from Pillar %c to Pillar %c\n",n,source,destination);
		tower(n-1,intermediate,source,destination);
	}
}

