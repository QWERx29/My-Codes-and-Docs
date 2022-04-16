#include<bits/stdc++.h>
#define N 96110
using namespace std;
struct node{
	int x,y;
}f[310][310],k1,k2;
int m,n,x,y;
char c;
node root(node k)
{
	if(f[k.x][k.y].x==k.x&&f[k.x][k.y].y==k.y) return k;
	f[k.x][k.y]=root(f[k.x][k.y]);
	return f[k.x][k.y];
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++) 
    	{
    		f[i][j].x=i;
    		f[i][j].y=j;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		if(c=='D') 
		{
			k1=root(f[x][y]);
			k2=root(f[x+1][y]);
		}
		if(c=='R')
		{
			k1=root(f[x][y]);
			k2=root(f[x][y+1]);
		}
		if(k1.x==k2.x&&k1.y==k2.y) 
		{
			cout<<i;
			return 0;
		}
		else f[k1.x][k1.y]=k2;
	}
	cout<<"draw";
	return 0;
}

