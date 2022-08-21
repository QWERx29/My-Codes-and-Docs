#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,x,y,fa[N][20],d[N];
struct edge
{
	int nx,to;
	inline void init(int t,int n){ to=t,nx=n; }
}e[N<<1];
int hd[N],cnt;
inline void adde(int u,int v)
{
	e[++cnt].init(v,hd[u]),hd[u]=cnt;
	e[++cnt].init(u,hd[v]),hd[v]=cnt;
}
inline void dfs(int pos,int pnt=0)
{
	d[pos]=d[pnt]+1;
	fa[pos][0]=pnt;
	for(int i=0;i+1<20;i++) fa[pos][i+1]=fa[fa[pos][i]][i];
	for(int i=hd[pos];i;i=e[i].nx)
	{
		if(e[i].to==pnt) continue;
		dfs(e[i].to,pos);
	}
}
inline int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=19;i>=0;i--)
		if(d[fa[u][i]]>=d[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++) cin>>x>>y,adde(x,y);
	dfs(1);
	cin>>m;
	for(int i=1;i<=m;i++) cin>>x>>y,cout<<(d[x]+d[y]-2*d[lca(x,y)])<<endl;
	return 0;
}