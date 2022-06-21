#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
int n,m,s,l;
int cnt,head[200005];
int f[100005],vis[100005];
struct Edge
{
	int to,next,dis;
}edge[200005];
void Add_edge(int from,int to,int w)
{
	edge[++cnt].dis=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
struct node
{
	int dis,id;
	bool operator<(const node &a)const{return a.dis<dis;}
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
	cin>>n>>m>>s>>l;
	for(int i=1;i<=m;i++)
	{
 		cin>>u>>v>>w;
		Add_edge(u,v,w);
		Add_edge(v,u,w);
	}
 	Dijkstra();
 	//for(int i=1;i<=n;i++) 
 	printf("%d ",f[l]);
}