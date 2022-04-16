#include<bits/stdc++.h>
using namespace std;
char a[1010],b[110],c[1010];
int a1[1010],b1[110],c1[1010];
bool v[1010];
int x[60];
int main()
{
	cin>>b>>a;
	for(int i=1;i<=26;i++)
		x[i]=i+1,x[26+i]=i+1+26;
	int l=strlen(a),l2=strlen(b);
	for(int i=0;i<l;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
			a1[i]=a[i]-'a'+1;
		else
		{
			a1[i]=a[i]-'A'+1;
			v[i]=1;
		}	
	}
	for(int i=0;i<l2;i++)
	{
		if(b[i]>='a'&&b[i]<='z')
			b1[i]=b[i]-'a'+1;
		else
			b1[i]=b[i]-'A'+1;
	}
	int n=0;
	for(int i=0;i<l;i++)
	{
		if(x[a1[i]]>b1[n])
			c1[i]=x[a1[i]]+b1[n]-2;
		else
			c1[i]=x[a1[i]+26]+b1[n]-2;
		n++;
		if(n==l2) n=0;
	}
	for(int i=0;i<l;i++)
	{
		if(!v[i])
		c[i]=c1[i]-1+'a';
		else
		c[i]=c1[i]-1+'A';
	}
	cout<<c;
	return 0;
}
