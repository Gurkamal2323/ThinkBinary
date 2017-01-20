#include<stdio.h>
#include<string.h>

char firstCapital(char *str)
{
	static int i=0;
	
	if(i<strlen(str))
	{
		if(isupper(str[i]))
		{
			return str[i];
		}
		else
		{
			i++;
			return firstCapital(str);
		}
	}
	else
		return 0;
}

int main()
{
	char str[20],letter;
	printf("Enter the word\n");
	scanf("%s",&str);
	letter=firstCapital(str);
	if(letter==0)
		printf("No capital letter is present in the word %s",str);
	else
		printf("First capital letter in word %s is %c",str,letter);
	
	return 0;
}
