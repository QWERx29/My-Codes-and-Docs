#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e7+10;
const int INF=0x3f3f3f3f;

int n,x,cnt;
int hd[N],con[N],dis[N];
struct edge{
	int nx,to,val;
}e[N];

inline void adde(int u,int v,int w)
{
	e[++cnt].nx=hd[u];
	e[cnt].to=v,e[cnt].val=w;
	hd[u]=cnt;
}
priority_queue<pii,vector<pii>,greater<pii> > q;
inline int prim()
{
	int ans=0;
	memset(dis,INF,sizeof dis);
	q.push(pii(0,1));
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(con[u]) continue;
		con[u]=1;
		ans+=dis[u];
		for(int i=hd[u];i;i=e[i].nx)
		{
			int v=e[i].to;
			if(dis[v]>e[i].val) dis[v]=e[i].val,q.push(pii(dis[v],v));
		}
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			cin>>x,adde(i-1,j,x),adde(j,i-1,x);
	cout<<prim()<<endl;
	return 0;
}