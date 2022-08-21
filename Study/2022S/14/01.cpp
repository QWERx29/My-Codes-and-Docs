#include<bits/stdc++.h>
using namespace std;
const int N=5e4+50;
int n,m,x,y,ans,r,cnt,top,tot,hd[N],dfn[N],low[N],st[N],col[N],sum[N],out[N],cntt;
struct edge { int nx,to; } e[N];
inline void adde(int u,int v)
{
	e[++r].nx=hd[u];
	e[r].to=v;
	hd[u]=r;
}
inline void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	st[++top]=u;
	for(int i=hd[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!col[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		tot++;
		for(;st[top+1]!=u;--top) col[st[top]]=tot,sum[tot]++;
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x>>y,adde(x,y);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++)
	{
		for(int i=hd[u];i;i=e[i].nx)
		{
			int v=e[i].to;
			if(col[u]!=col[v]) out[col[u]]++;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		if(!out[i])
		{
			if(ans) {cout<<0<<endl;return 0;}
			ans=i;
		}
	}
	cout<<sum[ans]<<endl;
	return 0;
}