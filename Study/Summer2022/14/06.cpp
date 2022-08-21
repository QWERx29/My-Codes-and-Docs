#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,m,x,y,sum,tot,cnt,r;
int hd[N],out[N],dfn[N],low[N],cut[N],ans[N];
struct edge{ int nx,to; }e[N];
inline void adde(int u,int v)
{
	e[++r].nx=hd[u];
	e[r].to=v,hd[u]=r;
}
inline void tarjan(int x,int pre=0)
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
			if(!pre) sum++;
			if(low[v]>=dfn[x]&&pre!=0) cut[x]=1;
		}
		else low[x]=min(low[x],dfn[v]);
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x>>y,adde(x,y),adde(y,x),out[x]++,out[y]++;
	tarjan(1);
	if(sum>=2) cut[1]=1;
	for(int i=1;i<=n;i++)
		if((n-2)==m-out[i]&&!cut[i]) ans[++tot]=i;
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++) cout<<ans[i]<<" ";
	return 0;
}