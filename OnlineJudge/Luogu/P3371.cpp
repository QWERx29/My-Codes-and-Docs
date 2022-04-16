#include<bits/stdc++.h>
const int INF=2147483647;
#define N 2000005
#define M 1000005
using namespace std;
int n,m,s,l;
int cnt,head[N];
int f[N],vis[M];
struct Edge{
	int to,next,dis;
}edge[N];
void addedge(int from,int to,int w)
{
	edge[++cnt].dis=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
struct node{
	int dis,id;
 bool operator <(const node &a)const{return a.dis<dis;}
};
void Dijkstra()
{
	priority_queue<node> q;
	q.push(node{0,s});
	for(int i=1;i<=n;i++) f[i]=INF; f[s]=0;
	while(!q.empty())
	{
		node a=q.top(); q.pop();
		int now=a.id;
		if(vis[now]) continue;
		int i=head[now]; vis[now]=1;
		for(;i;i=edge[i].next)
    	{
			int j=edge[i].to;
			if(f[now]+edge[i].dis<f[j]) 
			{
				f[j]=f[now]+edge[i].dis;
				q.push(node{f[j],j});
			}
		} 
	}
}
int main()
{
	int u,v,w;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		cin >> u >> v >> w;
		addedge(u,v,w);
//		addedge(v,u,w);
	}
//	cin>>s>>l;
	Dijkstra();
	for(int i=1;i<=n;i++) 
	cout<<f[i]<<" ";
}

