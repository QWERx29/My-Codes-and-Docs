#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u,v,tot;
struct edge{
    int start,to;long long v;
}g[2001020];
int f[100000];
long long ans;
int find(int x)
{
    if(f[x]==x) return x; else 
    {
        f[x]=find(f[x]);
        return f[x];
    }	
}
bool cmp(edge a,edge b)
{
    return a.v<b.v;
}
bool ask(int x,int y)
{
   	if(find(x)==find(y)) return true;
    else return false;
}
void kruskal()
{
    
    for(int i=1;i<=m;i++)
    {
        u=find(g[i].start);
        v=find(g[i].to);
        if(u==v) continue;
        ans+=g[i].v;
        f[u]=v;
        tot++;
        if(tot==n-1) break;
    }
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&g[i].start,&g[i].to,&g[i].v);
    sort(g+1,g+m+1,cmp);
	
    kruskal();
	for(int i=2;i<=n;i++)
    {
    	if(!ask(1,n))
		{
			printf("orz");
			return 0;
		}
	}	
    printf("%d",ans);
    return 0;
}
