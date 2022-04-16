#include<bits/stdc++.h>
#define N 2204
#define ll long long
using namespace std;
int g[N][N],dfn[N],num[N],n,m,cnt,ans;
void dfs1(int k)
{
	num[k]=1;
	for(int i=1;i<=n;i++) 
	{
		if(g[k][i]&&!num[i]) dfs1(i);
	}
	dfn[++cnt]=k;
}
void dfs2(int k)
{
	num[k]=ans;
	for(int i=1;i<=n;i++) 
	{
		if(g[i][k]&&!num[i]) dfs2(i);
	}
}
void Kosaraju()
{
	for(int i=1;i<=n;i++)
	{
		if(!num[i]) dfs1(i);
	}
	memset(num,0,sizeof(num));
	for(int i=n;i>=1;i--)
	{
		if(!num[dfn[i]])
		{
			ans++;
			dfs2(dfn[i]);
		}
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a][b]=1;
	}
	Kosaraju();
	return 0;
}

