#include<stdio.h>

int TOHmoves(int n, char source, char helper, char dest)
{
	if(n==0)
		return 0;
	int moves=0;
	//moved n-1 disks from source to helper
	moves += TOHmoves(n-1,source,helper,dest);
	//moved 1 remaining(largest) disk from source to dest
	moves++;
	printf("Moved disk %d from peg %c to peg %c\n",n,source,dest);
	//moved n-1 disks from helper to source
	moves += TOHmoves(n-1,helper,source,dest);
	
	return moves;
}

int main()
{
	int n;
	printf("Enter number of disks\n");
	scanf("%d",&n);
	int m=TOHmoves(n,'A','B','C');
	printf("\nTotal number of moves taken are %d",m);
	return 0;
}
