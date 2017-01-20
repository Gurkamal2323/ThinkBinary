#include<stdio.h>
int decToBinary(int n)
{
	if(n==0)
		return 0;
	else
		return (n%2 + 10*decToBinary(n/2));
}
int main()
{
	int dtb=decToBinary(10);
	printf("%d",dtb);
	return 0;
}
