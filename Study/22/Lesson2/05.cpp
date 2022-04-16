#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
double a[2001][2001],dis[2001],minn;
int n,m,i,j,k,x,y,f[10086];
void init()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>j>>k;
		cin>>a[j][k];
		a[j][k]=(100-a[j][k])/100;
		a[k][j]=a[j][k];
	}
	cin>>x>>y;
}
void dijkstra(int x)
{
	for(i=1;i<=n;i++) dis[i]=a[x][i];
	dis[x]=1;f[x]=1;
	for(i=1;i<n;i++)
	{
		minn=0;
		for(j=1;j<=n;j++)
		{
			if(f[j]==0&&dis[j]>minn) 
			{
				k=j;
				minn=dis[j];
			}
		}
		f[k]=1;
		if(k==y) break;
		for(j=1;j<=n;j++)
		{
			if(f[j]==0&&dis[k]*a[k][j]>dis[j]) dis[j]=dis[k]*a[k][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	dijkstra(x);
	printf("%.8lf",100/dis[y]);
	return 0;
}

