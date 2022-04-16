#include<bits/stdc++.h>
using namespace std;
int l,i;
char c[201],k[201];
int main()
{
	cin>>c;
	l=strlen(c)-1;
	while(c[i++]=='9')
	{
		if(i==l+1)
		{
			for(c[0]='1',l++;i>0;i--) c[i]='0';
		}
	}
	for(i=0;i<=l-i;i++) k[i]=k[l-i]=c[i];
	if(strcmp(k,c)<=0)
	{
		while(k[--i]=='9'); k[i]=k[l-i]=++k[i];
		for(i++;i<=l-i;i++) k[i]=k[l-i]='0';
	}
	cout<<k;
}
