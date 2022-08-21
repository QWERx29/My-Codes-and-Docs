#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+50;
int n,m,x,y;
int cnt,f,hd[N],vis[N];
double l,r,mid,z,dis[N];
struct edge{
	int nx,to;
	double val;
}e[N];
void adde(int u,int v,double w)
{
	e[++cnt].nx=hd[u];
	e[cnt].to=v,e[cnt].val=w;
	hd[u]=cnt;
}
void spfa(int u,double mid)
{
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(dis[v]>dis[u]+e[i].val-mid)
		{
			if(vis[v]||f) 
			{
				f=1;
				break;
			}
			dis[v]=dis[u]+e[i].val-mid;
			spfa(v,mid);
		}
	}
	vis[u]=0;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>x>>y>>z,adde(x,y,z);
	l=-1e6,r=1e6;
	while(r-l>1e-10)
	{
		mid=(l+r)/2;
		memset(dis,0,sizeof dis),memset(vis,0,sizeof vis);
		f=0;
		for(int i=1;i<=n;i++)
		{
			spfa(i,mid);
			if(f) break;
		}
		if(f) r=mid;
		else l=mid;
	}
	cout<<fixed<<setprecision(8)<<r<<endl;
	return 0;
}