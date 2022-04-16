#include<bits/stdc++.h>
#define N 110
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int n,m,a,b,c;
int dis[N][N],g[N][N];
int ans=INF;
int main()
{
	ios::sync_with_stdio(false);
	memset(g,0x7f,sizeof(g));
//	memset(dis,0x7f,sizeof(dis));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=c;
		dis[a][b]=dis[b][a]=c;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=k-1;i++)
		{
			for(int j=i+1;j<=k-1;j++)
				ans=min(ans,dis[i][j]+g[j][k]+g[k][i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	if(ans==INF) cout<<"no";
	else cout<<ans;
	return 0;
}

