#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N][N],q[N*N][2];
int flag[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ans;
bool p[N][N];
void bfs(int x,int y)
{
	int f=0,r=2;
	q[1][0]=x;
	q[1][1]=y;
	while(f<r-1)
	{
		++f;
		x=q[f][0];
		y=q[f][1];
		for(int i=0;i<4;i++)
		{
			int x1=x+flag[i][0];
			int y1=y+flag[i][1];
			if(x1<1||y1<1||x1>n||y1>m||!a[x1][y1]||p[x1][y1])
				continue;
			p[x1][y1]=true;
			q[r][0]=x1;
			q[r++][1]=y1;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++ i)
	{
		for (int j=1;j<=m;++j) cin>>a[i][j];
	}
  	for (int i=1;i<=n;++i)
  	{
  		for(int j=1;j<=m;++j) 
  		{
  			if(a[i][j]&&!p[i][j]) 
           	{
              ++ans; 
			  bfs(i,j);
           	}
		}
           
	}
  	cout<<ans<<endl;
	return 0;
}

