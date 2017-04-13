#include<iostream>
using namespace std;

void revStr(char *s, int n)
{
	if(n<2)
	return;
	
	revStr(s+1,n-2);
	char temp;
	temp = s[0];
	s[0] = s[n-1];
	s[n-1] = temp;
	
}

int main()
{
	char s[] = {'a','b','c','d','e'};
	revStr(s,5);
	for(int i=0;i<5;i++)
	{
		cout<<s[i];
	}
	return 0;
}
