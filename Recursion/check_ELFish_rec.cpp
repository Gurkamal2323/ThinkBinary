#include<iostream>
using namespace std;

int checkELFish(char *s, int needle=0)
{
	if(needle==7)
	{
		return 1;
	}
	
	if(s[0]=='\0')
		return 0;
	else if(s[0]=='e')
		needle = needle|1;
	else if(s[0]=='l')
		needle = needle|2;
	else if(s[0]=='f')
		needle = needle|4;
	
	return checkELFish(s+1,needle);
}

int main()
{
	char s[] = {'e','l','f','e','l','f'};
	cout<<checkELFish(s);
	return 0;
}
