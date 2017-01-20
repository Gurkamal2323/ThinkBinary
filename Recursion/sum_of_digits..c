#include<stdio.h>

int sumNum(int n)
{
	if(n!=0)
		return (n%10 + sumNum(n/10));
	else 
		return 0;
}

int main()
{
	int n;
	printf("Enter number\n");
	scanf("%d",&n);
	int s=sumNum(n);
	printf("\nSum of digits of number %d is %d",n,s);
	return 0;
}
