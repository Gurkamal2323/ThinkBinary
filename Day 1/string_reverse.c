#include<stdio.h>

void printRevString(char *s, int n)
{
	if(n<=1)
		return;
	//we just hace to reverse the middle characters between first and last character and then swap the two remaining characters i.e first and last
	printRevString(s+1,n-2);
	char ch;
	ch=s[0];
	s[0]=s[n-1];
	s[n-1]=ch;
}

int main()
{
	char s[100];
	//string read format including spaces
	scanf("%[^\n]",s);
	int i,count=0;
	//count number of characters in string excluding '\0'
	for(i=0;s[i]!='\0';i++)
	{
		count++;
	}
	printRevString(s,count);
	//printing reversed string
	for(i=0;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
	}
	return 0;
}
