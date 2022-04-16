#include<bits/stdc++.h>
#define N 96110
using namespace std;
int n,e; 
int w[N],g[240][240],ans,ansi,maxx,maxk;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	cin>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x][y]=g[y][x]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][k]==1&&g[k][j]==1) g[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k=0,s=0;
		for(int j=1;j<=n;j++)
		{
			if(g[i][j])
			{
				k++;
				s+=w[j];
			}
		}
		if(k>ans) {ans=k;ansi=i;}
		if(s>maxx) {maxx=s;maxk=i;}
		if(k==n) break;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[ansi][i]) cout<<i<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(g[maxk][i]) cout<<i<<" ";
	}
	return 0;
}

