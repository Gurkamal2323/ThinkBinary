#include<iostream>
using namespace std;

int count(char *s, char c)
{
	if(s[0]=='\0')
		return 0;
	
	return ((s[0]==c) + count(s+1,c));
}

int main()
{
	char s[] = {'a','b','c','a','a'};
	char c='a';
	cout<<count(s,c);
	return 0;
}
