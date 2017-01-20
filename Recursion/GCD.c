#include<stdio.h>
int getGCD(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
		{
			return getGCD(a-b,b);
		}
		else
			return getGCD(b,b-a);
		
		return a;
	}
}
int main()
{
	int gcd=getGCD(24,36);
	printf("%d",gcd);
	return 0;
}
