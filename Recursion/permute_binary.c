/*order doesn't matter
eg - n=4
o/p - 0000
1000
0100
1100
0010
1010
0110
1110
0001
1001
0101
1101
0011
1011
0111
1111*/
#include<stdio.h>
char a[10];
void perm_bin(int n)
{
	if(n<1)
		printf("%s\n",a);
	else
	{
		//setting n-1th digit to 0 and permuting till n-1
		a[n-1]='0';
		perm_bin(n-1);
		//setting n-1th digit to 1 and permuting till n-1
		a[n-1]='1';
		perm_bin(n-1);
	}
}
int main()
{
	perm_bin(4);
	return 0;
}
