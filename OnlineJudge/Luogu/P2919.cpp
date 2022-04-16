#include<bits/stdc++.h>
using namespace std;
int n,m,a[710][710],ans,d[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
bool v[710][710];
void dfs(int x,int y)
{
	if(v[x][y]||x==0||y==0||x>n||y>m) return ;
	v[x][y]=true;
	for(int i=0;i<8;++i)
	{
		if(a[x][y]==a[x+d[i][0]][y+d[i][1]])
		{
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j) cin>>a[i][j];
	}
	for(int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			for(int k=0;k<8;++k)
			{
				if(a[i][j]<a[i+d[k][0]][j+d[k][1]]) dfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(!v[i][j])
			{
				++ans; 
				dfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}


