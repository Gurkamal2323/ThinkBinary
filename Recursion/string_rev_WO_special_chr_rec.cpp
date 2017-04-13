#include<iostream>
using namespace std;

//checking cpecial character
bool isSpecial(char c)
{
	if((c>='A' && c<='Z') || (c>='a' && c<='z'))
		return false;
	else
		return true; 
}

void revStr(char *s, int n)
{
	//special character at first position
	if(isSpecial(s[0]))
	{
		revStr(s+1,n-1);
		return;
	}
	//special character at last position
	else if(isSpecial(s[n-1]))
	{
		revStr(s,n-1);
		return;
	}
	//special character inbetween
	char temp;
	temp = s[0];
	s[0] = s[n-1];
	s[n-1] = temp;
	revStr(s+1,n-2);
}

int main()
{
	char s[] = {'$','a','b','c','d','e'};
	revStr(s,7);
	for(int i=0;i<7;i++)
	{
		cout<<s[i];
	}
	return 0;
}
