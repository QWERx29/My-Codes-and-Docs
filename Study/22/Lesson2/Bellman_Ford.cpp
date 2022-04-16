#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int M=1e6;
const int inf=0x3f3f3f3f;
int n,m,s,l;
int cnt;
typedef struct Edge{
	int u,v,w;
	Edge(){};
	Edge(int u,int v,int w):u(u),v(v),w(w){}
}Edge;
Edge edge[M];
int dis[maxn];
void init()
{
	memset(dis,inf,sizeof(dis));
}
int  Bellman_Ford(int S)
{
	dis[S]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			if(dis[edge[j].v]>dis[edge[j].u]+edge[j].w)
				dis[edge[j].v]=dis[edge[j].u]+edge[j].w;
		}
	}
	int flag=0;
	for(int j=0;j<cnt;j++)
	{
		if(dis[edge[j].v]>dis[edge[j].u]+edge[j].w)
		{
			flag=1;
		    break;
		}
	}
	return flag;
}
int main()
{
	cin>>n>>m;
	int u,v,w;
	init();
	cnt=0;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edge[cnt].u=u;
		edge[cnt].v=v;
		edge[cnt].w=w;  
		cnt++;
		/*
		edge[cnt].u=v;
		edge[cnt].v=u;
		edge[cnt].w=w;
		cnt++;
		*/
	}
	cin>>s>>l;
	int S,E;
	int result=Bellman_Ford(s);
	if(result)cout<<"No Result"<<endl;
	cout<<dis[l]<<endl;
	return 0;
}


