#include<bits/stdc++.h>
using namespace std;
const int N=404;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,a[N][N],s[N][N],ans;
int search(int x,int y)
{
	if(s[x][y]>0) return s[x][y];
	s[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int q=dx[i]+x,w=dy[i]+y;
		if(q>0&&w>0&&q<=n&&w<=m&&a[x][y]>a[q][w])
		{
			search(q,w);
			s[x][y]=max(s[x][y],s[q][w]+1);
		}
	}
	return s[x][y];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans=max(ans,search(i,j));
	cout<<ans;
	return 0;
}