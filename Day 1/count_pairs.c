/*count no of pairs in a given string
par - two instances of a character are separated by one character
e.g - xx -> 0
	x -> 0
	xxx -> 1
	bxbb -> 1
	axaxa -> 3*/
#include<stdio.h>

int countPairs(char *s)
{
	if(s[0]=='\0' || s[1]=='\0')
		return 0;
		
	int c=countPairs(s+1);
	if(s[0]==s[2])
		c++;
	return c;
}

int main()
{
	char s[100];
	scanf("%[^\n]",s);
	int c=countPairs(s);
	printf("%d",c);
	return 0;
}
