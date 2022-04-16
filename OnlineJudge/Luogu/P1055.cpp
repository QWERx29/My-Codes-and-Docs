#include<bits/stdc++.h>
using namespace std;
char c[14],a[12]="0123456789X";
int b,j=1;
int main()
{
	gets(c);
	for(int i=0;i<12;i++)
	{
		if(c[i]=='-') continue;
		else
		{
			b+=(c[i]-'0')*j;
			j++;
		}
	}
	int x=b%11;
	if(a[x]==c[12]) cout<<"Right";
	else
	{
		c[12]=a[x];
		puts(c);
	}
}
