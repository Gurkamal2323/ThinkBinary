#include<iostream>
using namespace std;

void TOH(int n, char S, char H, char D)
{
	if(n==0)
		return;
		
	TOH(n-1,S,H,D);//assumed that n-1 disks are already at the destination
	cout<<"Moved disk "<<n<< " from peg "<<S<<" to peg "<<D<<endl;//moving last disk from source to destination
	TOH(n-1,H,D,S);//moving the disks at the helper to destination
}

int main()
{
	char S,H,D;
	int n=3;
	TOH(n,S,H,D);
	return 0;
}
