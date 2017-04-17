#include<iostream>
using namespace std;

int TOH(int n, char s,char h, char d)
{
	if(n==0)
		return 0;
		
	int moves=0;
	moves+=TOH(n-1,s,d,h);
	moves+=1;
	cout<<"Moved disk from peg "<<s<<" to peg "<<d<<endl;
	moves+=TOH(n-1,h,s,d);
	
	return moves;
}

int main()
{
	char s='A';
	char h='B';
	char d='C';
	int result=TOH(3,s,h,d);
	cout<<result;
	return 0;
}
