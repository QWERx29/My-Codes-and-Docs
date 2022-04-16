#include<bits/stdc++.h>
#define N 961100
using namespace std;
int g[5010][5010],minv[N];
bool vis[N];
int n,m; 
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(g,0x7f,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
//		for(int j=1;j<=n;j++) cin>>g[i][j];
	}
	memset(minv,0x7f,sizeof(minv));
	memset(vis,true,sizeof(vis));
	minv[1]=0;
	for(int i=1;i<=n;i++)
	{
		int v=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]&&minv[j]<minv[v]) v=j;
		}
		vis[v]=false;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]&&g[v][j]<minv[j])
				minv[j]=g[v][j];
		}
	}
	int mst=0;
	for(int i=1;i<=n;i++) mst+=minv[i];
	cout<<mst<<endl;
	return 0;
}

