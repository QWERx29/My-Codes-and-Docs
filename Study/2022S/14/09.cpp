#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=503;
int n,m,x,y,cnt,r,ans1,ans2,cut,ncut,cse,rt,cal,tot;
int hd[N],dfn[N],low[N],jug[N],vis[N];
struct edge{ int nx,to; }e[N];
inline void adde(int u,int v)
{
	e[++r].nx=hd[u];
	e[r].to=v,hd[u]=r;
}
inline void tarjan(int x,int pre)
{
	dfn[x]=low[x]=++cnt;
	for(int i=hd[x];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(v==pre) continue;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x])
			{
				if(x!=rt) jug[x]=1;
				else cal++;
			}
		}
		else low[x]=min(low[x],dfn[v]);
	}
}
inline void dfs(int u)
{
	vis[u]=tot;
	ncut++;
	for(int i=hd[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(jug[v]&&vis[v]!=tot) cut++,vis[v]=tot;
		if(!vis[v]) dfs(v);
	}
}
inline void init()
{
	memset(e,0,sizeof e);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(jug,0,sizeof jug);
	memset(vis,0,sizeof vis);
	memset(hd,0,sizeof hd);
	n=cnt=r=tot=0;
	ans1=0,ans2=1;
	++cse;
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cin.tie(0);
	while(1)
	{
		cin>>m;
		if(m==0) break;
		init();
		for(int i=1;i<=m;i++) cin>>x>>y,n=max(n,max(x,y)),adde(x,y),adde(y,x);
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
			{
				rt=i,cal=0;
				tarjan(i,i);
				if(cal>=2) jug[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&!jug[i]) 
			{
				++tot;
				cut=ncut=0;
				dfs(i);
				if(cut==0) ans1+=2,ans2*=(ncut-1)*ncut/2;
				if(cut==1) ans1+=1,ans2*=ncut;
			}
		}
		cout<<"Case "<<cse<<": "<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}