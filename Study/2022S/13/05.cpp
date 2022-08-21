#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
const int INF=0x3f3f3f3f;
struct edge
{
	int to,nx,val;
}e[N<<3];
int n,ml,md,cnt,hd[N];
int a,b,d,vis[N],dis[N],cir[N];
inline void adde(int u,int v,int w)
{
	e[++cnt].nx=hd[u];
	e[cnt].to=v,e[cnt].val=w;
	hd[u]=cnt;
}
inline void spfa(int o)
{
	queue<int> q;
	memset(dis,INF,sizeof dis);;
	memset(vis,0,sizeof vis),memset(cir,0,sizeof cir);
	vis[o]=1,cir[o]=1,dis[o]=0;
	q.push(o);
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;
		for(int i=hd[u];i;i=e[i].nx)
		{
			int v=e[i].to;
			if(dis[u]+e[i].val<dis[v])
			{
				dis[v]=dis[u]+e[i].val;
				cir[v]++;
				if(cir[v]>=n) return cout<<-1<<endl,exit(0);
				if(!vis[v]) vis[v]=1,q.push(v);
			}

		}
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>ml>>md;
	for(int i=1;i<=n;i++) adde(0,i,0);
	for(int i=1;i<=n;i++) adde(i+1,i,0);
	for(int i=1;i<=ml;i++) cin>>a>>b>>d,adde(a,b,d);
	for(int i=1;i<=md;i++) cin>>a>>b>>d,adde(b,a,-d);
	spfa(0),spfa(1);
	if(dis[n]==INF) cout<<-2<<endl;
	else cout<<dis[n]<<endl;
	return 0;
}