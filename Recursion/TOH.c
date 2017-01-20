#include<stdio.h>

void TOH(int n, char source, char helper, char dest)
{
	//no disks
	if(n==0)
		return;
	//move n-1 disks from source to helper
	TOH(n-1,source,helper,dest);
	//moved nth disk from source to destination
	printf("Moved disk %d from peg %c to peg %c\n",n,source,dest);
	//repeat the same from helper to destination
	TOH(n-1,helper,dest,source);
}
int main()
{
	int n;
	printf("Enter number of disks\n");
	scanf("%d",&n);
	TOH(n,'A','B','C');
	return 0;
}
