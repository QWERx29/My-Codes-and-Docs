#include<bits/stdc++.h>
using namespace std;
#define N 110
int g[N][N],du[N],c[N];
int n,e,cp,x,y,s;
void find(int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(g[i][j]==1)
		{
			g[j][i]=g[i][j]=0;
			find(j);
		}
	}
	c[++cp]=i;
}
int main()
{
	memset(g,0,sizeof(g));
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y;
		g[y][x]=g[x][y]=1;
		du[x]++;
		du[y]++;
	}
	s=1;
	for(int i=1;i<=n;i++)
	{
		if(du[i]%2==1) s=i;	
	}
	cp=0;
	find(s);
	for(int i=1;i<=cp;i++) cout<<c[i]<<' ';
}
