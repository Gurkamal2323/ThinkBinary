#include<stdio.h>
int getLCM(int a,int b)
{
	static int common = 1;
	
	if(common%a==0 && common%b==0)
	{
		return common;
	}
	common++;
	getLCM(a,b);
	return common;
}
int main()
{
	int lcm=getLCM(72,120);
	printf("%d",lcm);
	return 0;
}
