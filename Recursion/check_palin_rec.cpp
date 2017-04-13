#include<iostream>
using namespace std;

int checkPalin(char *s, int l)
{
	if(l<=1)
		return true;
	else if(s[0]!=s[l-1])
		return false;
	else
		return checkPalin(s+1,l-2);
}

int main()
{
	char s[] = {'b','a','b'};
	cout<<checkPalin(s,3);
	return 0;
}
