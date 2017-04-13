#include<iostream>
using namespace std;
int permTable[1000]={0};

void perm(int n, int cur=0)
{
	if(n==cur)
	{
		for(int i=0;i<n;i++)
		{
			cout<<permTable[i];
		}
		cout<<endl;
		return;
	}
	permTable[cur]=0;//writing 0 first will print in increasing order
	perm(n,cur+1);
	permTable[cur]=1;
	perm(n,cur+1);
	
	return;
}

int main()
{
	int n=3;
	perm(n);
	return 0;
}
