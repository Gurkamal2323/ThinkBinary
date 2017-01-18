/*gievn a string, give recursively a cleaned string where adjacent characters that are same have been reduced to a single charcater
e.g - abbbcdd -> abcd
	yyzzyyyabbaa -> yzyaba*/
#include<stdio.h>

void stringClean(char *s)
{
	if(s[0]=='\0')
		return;
		
	if(s[0]!=s[1])
		printf("%c",s[0]);
	stringClean(s+1);
}

int main()
{
	char s[100];
	scanf("%[^\n]",s);
	stringClean(s);
	return 0;
}
