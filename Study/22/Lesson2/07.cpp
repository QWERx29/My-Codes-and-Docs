#include<bits/stdc++.h>
#define N 911
#define INF 0x7fffffff
#define ll long long
using namespace std;
int n,p,c,x,y,t,minn,head,tail,tot,u,i,j;
int a[N][N],b[N],dis[N],num[N],w[N][N],team[2*N];
bool exist[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p>>c;
	for(i=1;i<=p;i++)
	{
		b[i]=num[i]=0;
		for(j=1;j<=p;j++) w[i][j]=INF/3;
	}
	for(i=1;i<=n;i++) cin>>b[i];
	for(i=1;i<=c;i++)
	{
		cin>>x>>y>>t;
		w[x][y]=w[y][x]=t;
		a[x][++num[x]]=y;
		a[y][++num[y]]=x;
	}
	minn=INF/3;
	for(i=1;i<=p;i++)
	{
		for(j=1;j<=p;j++) dis[j]=INF/3;
		memset(team,0,sizeof(team));
		memset(exist,false,sizeof(exist));
		dis[i]=0;team[1]=i;head=0;tail=1;exist[i]=true;
		do
		{
			head++;
			head=((head-1)%1601)+1;
			u=team[head];
			exist[u]=false;
			for(j=1;j<=num[u];j++)
			{
				if(dis[a[u][j]]>dis[u]+w[u][a[u][j]])
				{
					dis[a[u][j]]=dis[u]+w[u][a[u][j]];
					if(!exist[a[u][j]])
					{
						tail++;
						tail=(tail-1)%1601+1;
						team[tail]=a[u][j];
						exist[a[u][j]]=true;
					}
				}
			}
		}while(head!=tail);
		tot=0;
		for(j=1;j<=n;j++) tot+=dis[b[j]];
		if(tot<minn) minn=tot;
	}
	cout<<minn;
	return 0;
}

