#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,ans,t;
bool vis[100860];
int head[100860];
struct edge
{
    int to,next;
}e[961100];
void add(int i,int j)
{
    e[t].to=j;
    e[t].next=head[i];
    head[i]=t++;
}
void del(int x)
{
    for(int i=head[x];i!=-1;i=e[i].next)
    vis[e[i].to]=1;
}
void dfs(int x)
{
    vis[x]=1;ans--;
    for(int i=head[x];i!=-1;i=e[i].next)
    if(!vis[e[i].to]) dfs(e[i].to);
}
void init()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m>>k;
    ans=n;
    for(int i=1;i<=m;i++)
	{
        cin>>x>>y;
        add(x,y),add(y,x);
    }
    for(int i=1;i<=k;i++)
	{
        cin>>x;
        del(x);
    }
}
int main()
{
    init();
    dfs(1);
    cout<<ans;
    return 0;
} 
