#include<stdio.h>

void printRevString(char *s, int n)
{
	if(n<=1)
		return;
	printRevString(s+1,n-2);
	char ch;
	ch=s[0];
	s[0]=s[n-1];
	s[n-1]=ch;
}

int main()
{
	char s[100];
	scanf("%[^\n]",s);
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
	{
		count++;
	}
	printRevString(s,count);
	for(i=0;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}
