#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n,m,x,y,rt,cnt,r,ans;
int hd[N],dfn[N],low[N],cut[N];
struct edge{ int nx,to; }e[N];
inline void adde(int u,int v)
{
	e[++r].nx=hd[u];
	e[r].to=v,hd[u]=r;
}
inline void tarjan(int x,int pre)
{
	dfn[x]=low[x]=++cnt;
	int tot=0,sum=0;
	for(int i=hd[x];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(v==pre) continue;
		if(!dfn[v])
		{
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(x==rt) sum++;
			if(x!=rt&&low[v]>=dfn[x]) tot++;
		}
		else low[x]=min(low[x],dfn[v]);
		ans=max(ans,max(sum,tot+1));
	}
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cin.tie(0);
	while(1)
	{
		memset(hd,0,sizeof hd),memset(e,0,sizeof e),memset(dfn,0,sizeof dfn),memset(low,0,sizeof low);
		cnt=r=ans=0;
		cin>>n>>m;
		if(n==0) return 0;
		for(int i=1;i<=m;i++) cin>>x>>y,adde(x,y),adde(y,x);
		int cal=0;
		for(int i=0;i<n;i++) 
			if(!dfn[i]) cal++,rt=i,tarjan(i,i);
		cout<<cal-1+ans<<endl;
	}
	return 0;
}