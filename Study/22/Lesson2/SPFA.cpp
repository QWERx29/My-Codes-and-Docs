//SPFA
#include<bits/stdc++.h>
using namespace std;
#define N 10100
#define M 500500
#define INF 0x3f3f3f3f
struct edge{
    int to,next,w;
}e[M];
int using_v[N],using_times[N],head[N],dis[N];
int cnt=0,n,m;
void addedge(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int SPFA(int start)
{
    queue<int>q;
    dis[start]=0;
    using_v[start]=1;
    q.push(start);
    while(!q.empty())
	{
        int top=q.front();
        q.pop();
        using_v[top]=0;
        using_times[top]++;
        if(using_times[top]>n) return 0;
        for(int i=head[top];i;i=e[i].next)
		{
            if(dis[e[i].to]>dis[top]+e[i].w)
			{
                dis[e[i].to]=dis[top]+e[i].w;
                if(!using_v[e[i].to])
				{
                    using_v[e[i].to]=1;
                    q.push(e[i].to);
                }
            }
        }
    }
    return 1;
}
int main()
{
    int u,v,w,s,l;
    cin>>n>>m;
    memset(dis,INF,sizeof(dis));
    for(int i=0;i<m;i++)
	{
        cin>>u>>v>>w;
        addedge(u,v,w);
        //addedge(v,u,w);
    }
	cin>>s>>l;
    SPFA(s);
    cout<<dis[l];
    return 0;
}



