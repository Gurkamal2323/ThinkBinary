#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void perm_str(char *s,int l, int r)
{
	if(l==r)
	{
		cout<<s<<endl;
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			perm_str(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}

int main()
{
	char s[] = {'a','b','c','d'};
	perm_str(s,1,3);
	return 0;
}
