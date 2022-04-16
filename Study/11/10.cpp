#include<bits/stdc++.h>
using namespace std;
int a,b,c,c1,c2;
int n[100000],n1[100000],n2[100000];
void j(int a[],int b[],int d[])
{
	int x=0;
	c2=c1;
	for(int i=1;i<=c2;i++)
	{
		d[i]=a[i]+b[i]+x;
		x=d[i]/10;
		d[i]%=10;
	}
	if(x!=0)
		c2++,d[c2]=x;
}
void f(int &ac,int &bc,int a[],int b[])
{
	for(int i=1;i<=bc;i++)
		a[i]=b[i];
	ac=bc;
}
int main()
{
	c=c1=1;
	n[1]=n1[1]=1;
	cin>>a>>b;
	a=b-a;
	for(int i=2;i<=a;i++)
	{
		j(n,n1,n2);
		f(c,c1,n,n1);
		f(c1,c2,n1,n2);
	}
	for(int i=c1;i>=1;i--)
		cout<<n1[i];
	return 0;
}

