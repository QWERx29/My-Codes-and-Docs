#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int n,m,x,y,cnt,r,ans[N];
int hd[N],dfn[N],low[N],sz[N];
struct edge{ int nx,to; }e[N];
inline void adde(int u,int v)
{
	e[++r].nx=hd[u];
	e[r].to=v,hd[u]=r;
}
inline void tarjan(int x,int pre=0)
{
	dfn[x]=low[x]=++cnt;
	int pos=0;sz[x]=1;
	for(int i=hd[x];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(v==pre) continue;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			sz[x]+=sz[v];
			if(low[v]>=dfn[x]) pos+=sz[v],ans[x]+=2*sz[v]*(n-pos-1);
		}
		else low[x]=min(low[x],dfn[v]);
	}
	ans[x]+=2*(n-1);
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x>>y,adde(x,y),adde(y,x);
	tarjan(1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;	
	return 0;
}