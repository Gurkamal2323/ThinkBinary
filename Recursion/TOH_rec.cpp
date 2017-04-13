#include<iostream>
using namespace std;

void TOH(int n, char S, char H, char D)
{
	if(n==0)
		return;
		
	TOH(n-1,S,H,D);
	cout<<"Moved disk "<<n<< " from peg "<<S<<" to peg "<<D<<endl;
	TOH(n-1,H,D,S);
}

int main()
{
	char S,H,D;
	int n=3;
	TOH(n,S,H,D);
	return 0;
}
