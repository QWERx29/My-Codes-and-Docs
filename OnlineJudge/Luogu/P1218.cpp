#include<iostream>
using namespace std;
int a[200050],b[200050],c[200050],n,minx=0,maxx=-999999;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		c[i]=c[i-1]+a[i];
	}
	b[1]=#include<bits/stdc++.h>
using namespace std;
int n,a[5]={1,3,5,7,9};
bool prime(int x)
{
	if(x==1) return 0;
	if(x==2) return 1;
	else
	{
		for(int i=2;i<=sqrt(x);i++)
			if(x%i==0) return 0;
		return 1;
	}
}
void dfs(int k,int sum)
{
	int p;
	if(sum==n)
	{
		cout<<k<<endl;
		return;
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			p=k*10+a[i];
			if(prime(p)) dfs(p,sum+1);
		}
	}
}
int main()
{
	cin>>n;
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);
}a[1];minx=min(0,c[1]);
	for(int i=2;i<=n;i++)
	{
		b[i]=c[i]-minx;
		minx=min(minx,c[i]);
	}
	for(int i=1;i<=n;i++) maxx=max(maxx,b[i]);
	cout<<maxx<<endl;
}
