#include <bits/stdc++.h>
using namespace std;
int a[1000][1000],b[1000][1000]={0};
int x,y;
int ans=0;
bool in(int x,int y)
{
	return x<1||x>10||y<1||y>10;
}
void dfs(int x,int y)
{
	if(in(x,y)||a[x][y]!=0)
	return;
		a[x][y]=1;
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
}
int main() {
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1) b[i][j]=-1;
		}
	}
	for(int i=1;i<=10;i++)
	{
		if(a[i][1]!=1)	dfs(i,1);
    	if(a[i][10]!=1)	dfs(i,10);
	}
	for(int i=1;i<=10;i++)
	{
		if(a[1][i]!=1) dfs(1,i);
    	if(a[10][i]!=1)	dfs(10,i);
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(a[i][j]==0)	ans++;
		} 
	}
	cout<<ans;
	return 0;
}
