#include<bits/stdc++.h>
using namespace std;
const int N=5e7+50;
int dep[N],fa[N],sn[N],tp[N],sz[N],hd[N];
int n,m,cnt,ans;
struct edge{ int to,nx; }e[N];
inline void adde(int u,int v)
{
	e[++cnt].nx=hd[u];
	e[cnt].to=v,hd[u]=cnt;
}
inline void dfs1(int u)
{
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(dep[v]) continue;
		dep[v]=dep[u]+1,fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[sn[u]]) sn[u]=v;
	}
}
inline void dfs2(int u,int top)
{
	tp[u]=top;
	if(!sn[u]) return ;
	dfs2(sn[u],top);
	for(int i=hd[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(v==fa[u]||v==sn[u]) continue;
		dfs2(v,v);
	}
}
inline int lca(int u,int v)
{
	while(tp[u]!=tp[v])
	{
		if(dep[tp[u]]<dep[tp[v]]) swap(u,v);
		u=fa[tp[u]];
	}
	return dep[u]<dep[v]?u:v;
}
inline int cal(int x,int y,int z)
{
	if(x==y) return z;
	else if(x==z) return y;
	else return x;
}
signed main()
{
	int a,b,c;
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++) cin>>a>>b,adde(a,b),adde(b,a);
	dep[1]=1;
	dfs1(1),dfs2(1,0);
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		int x=lca(a,b),y=lca(b,c),z=lca(a,c);
		ans=cal(x,y,z);
		cout<<ans<<" "<<dep[a]+dep[b]+dep[c]-dep[x]-dep[y]-dep[z]<<"\n";
	}
	return 0;

}