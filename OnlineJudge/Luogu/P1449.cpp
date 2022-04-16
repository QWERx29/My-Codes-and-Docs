#include<bits/stdc++.h>
using namespace std;
long long s[1005],i,x;
char q;
int main()
{
	while((q=getchar())!='@')
	{
		if(q>='0'&&q<='9') 
		{
			x*=10;
			x+=q-'0';
		}
		else if(q=='.')
		{
			s[++i]=x;
			x=0;
		}
		else if(q=='+')
		{
			s[i-1]=s[i-1]+s[i];
			s[i]=0;i--;
		}
		else if(q=='-')
		{
			s[i-1]=s[i-1]-s[i];
			s[i]=0;i--;
		}
		else if(q=='*')
		{
			s[i-1]=s[i-1]*s[i];
			s[i]=0;i--;
		}
		else if(q=='/')
		{
			s[i-1]=s[i-1]/s[i];
			s[i]=0;i--;
		}
	}
	cout<<s[i];
}
