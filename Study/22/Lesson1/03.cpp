#include<bits/stdc++.h>
using namespace std;
#define N 10086
int g[1001][1001],du[N],c[N];
int n,e,cp=0,x,y,s,maxn=0;
void find(int i)
{
	int j;
	for(j=1;j<=maxn;j++)
	{
		if(g[i][j]>=1)
		{
			g[j][i]--;
			g[i][j]--;
			find(j);
		}
	}
	c[++cp]=i;
}
int main()
{
	memset(g,0,sizeof(g));
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		g[y][x]++;
		g[x][y]++;
		du[x]++;
		du[y]++;
		maxn=max(maxn,max(x,y));
	}
	s=1;
	for(int i=1;i<=maxn;i++)
	{
		if(du[i]%2==1) {s=i;break;}
	}
	find(s);
	for(int i=cp;i>=1;i--) cout<<c[i]<<endl;
}
