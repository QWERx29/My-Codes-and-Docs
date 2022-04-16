#include<bits/stdc++.h>
using namespace std;
#define N 110
bool vis[N],v1[N];
int ans[N],num[N],g[N][N];
int s,l,x,n;
void print()
{
	int i;
	for(i=1;i<=l;i++) cout<<ans[i]<<' ';
	cout<<endl;
}
void dfs(int last,int i)
{
	vis[i]=true;
	v1[i]=true;
	ans[++l]=i;
	for(int j=1;j<=num[i];j++)
	{
		if(g[i][j]==x&&g[i][j]!=last)
		{
			ans[++l]=g[i][j];
			print();
			l--;
			break;
		}
		if(!vis[g[i][j]]) dfs(i,g[i][j]);
	}
	l--;
	vis[i]=false;
}
int main()
{
	memset(vis,false,sizeof(vis));
	memset(v1,false,sizeof(v1));
	int m,u,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		g[u][++num[u]]=v;
		g[v][++num[v]]=u;
	}
	for(x=1;x<=n;x++)
	{
		if(!v1[x])
		{
			l=0;
			dfs(0,x);
		}
	}
	return 0;
}
