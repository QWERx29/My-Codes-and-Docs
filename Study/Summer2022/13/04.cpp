#include<bits/stdc++.h>
using namespace std;
const int N=5e7+50;
int n,a,b,c,cnt,m;
int hd[N],dis[N],f[N];
struct edge{ int to,nx,val; }e[N];
inline void adde(int u,int v,int w)
{
    e[++cnt].nx=hd[u];
    e[cnt].to=v,e[cnt].val=w;
    hd[u]=cnt;
}
inline void spfa()
{
    memset(dis,-0x3f,sizeof dis);
    queue<int> q;
    dis[0]=0,f[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop(),f[u]=0;
        for(int i=hd[u];~i;i=e[i].nx)
        {
            int v=e[i].to;
            if(dis[v]<dis[u]+e[i].val)
            {
                dis[v]=dis[u]+e[i].val;
                if(!f[v]) f[v]=1,q.push(v);
            }
        }
    }
}

signed main()
{
    int t;
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(hd,-1,sizeof hd);
        memset(f,0,sizeof f);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b>>c;
            adde(a,b+1,c);
            m=max(m,b+1);
        }
        for(int i=0;i<=m;i++) adde(i,i+1,0),adde(i+1,i,-1);
        spfa();
        cout<<dis[m]<<endl;
        if(t) cout<<"\n";
    }
    return 0;
}