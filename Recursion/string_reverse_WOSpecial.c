#include<stdio.h>

int isSpecial(char a)
{
	if((a>=65 && a<=90) || (a>=97 && a<=122))
		return 0;
	else
		return 1;
}

void revStrWOSpecial(char *s,int n)
{
	if(n<2)
		return;
	//when the special character is at index 0
	if(isSpecial(s[0]))
	{
		revStrWOSpecial(s+1,n-1);
	}
	//when the special character is at last index
	else if(isSpecial(s[n-1]))
	{
		revStrWOSpecial(s,n-1);
	}
	//when the special character is at both first(0th) and last index
	else if(isSpecial(s[0]) && isSpecial(s[n-1]))
	{
		revStrWOSpecial(s+1,n-2);
	}
	//when the special charact is inbetween
	else
	{
		char temp;
		temp=s[0];
		s[0]=s[n-1];
		s[n-1]=temp;
	
		revStrWOSpecial(s+1,n-2);
	}
}

int main()
{
	char s[100];
	printf("Enter string\n");
	scanf("%[^\n]s",s);
	int i,len;
	for(i=0;s[i]!='\0';i++)
	{
		len++;
	}
	revStrWOSpecial(s,len);
	printf("\nReversed string is %s",s);
	return 0;
}
