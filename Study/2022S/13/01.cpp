#include<bits/stdc++.h>
//#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e6+50;
struct edge
{
	int nx,to,c,f;
}e[N];
int n,m,k,s,t,x,y,w,cnt;
int hd[N],vis[N],dis[N];
inline void adde(int u,int v,int w)
{
	e[++cnt].nx=hd[u];
	e[cnt].to=v,e[cnt].c=w;
	hd[u]=cnt;
}
inline void dijkstra(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > p;
	p.push(make_pair(0,s));
	while(!p.empty())
	{
		int u=p.top().second;
		p.pop();
		if(!vis[u])
		{
			vis[u]=1;
			for(int i=hd[u];i;i=e[i].nx)
			{
				int v=e[i].to;
				if(dis[v]>dis[u]+e[i].c) dis[v]=dis[u]+e[i].c,p.push(make_pair(dis[v],v));
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		adde(x,y,w),adde(y,x,w);
		for(int j=1;j<=k;j++)
		{
			adde(x+j*n,y+j*n,w),adde(y+j*n,x+j*n,w);
			adde(x+(j-1)*n,y+j*n,0),adde(y+(j-1)*n,x+j*n,0);
		}
	}
	for(int i=1;i<=k;i++) adde(t+(i-1)*n,t+i*n,0);
	dijkstra(s);
	cout<<dis[t+k*n]<<endl;
	return 0;
}