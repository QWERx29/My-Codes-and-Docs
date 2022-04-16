#include<bits/stdc++.h>
using namespace std;
const int maxx=10001;
const int INF=0x3ffff;
int f[maxx][maxx];
bool vis[maxx]={false};
int dis[maxx];
int n; 
void dijkstra(int s)
{
    dis[s]=0;
    for(int i=1;i<=n;i++) 
    {
        int u=-1; 
        int min=INF;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==false&&dis[j]<min)
            {
                u=j;
                min=dis[j];
            }
        }
        if (u==-1) break;
        vis[u]=true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false&&f[u][i]!=0&&dis[i]>dis[u]+f[u][i])
                dis[i]=dis[u]+f[u][i];
        }
    }
}
int main()
{
    int s;
    fill(dis,dis+maxx,INF);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>f[i][j];
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        if(i!=s&&dis[i] !=INF)  cout<<dis[i]<<endl;
        else if(i!=s&&dis[i]==INF) cout<<0<<endl;
    }
    return 0;
}
