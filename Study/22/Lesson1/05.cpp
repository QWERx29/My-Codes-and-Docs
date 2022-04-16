#include<bits/stdc++.h>
int n,e,x,y,i,g[110][110],bn;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>e;
	memset(g,false,sizeof(g));
	for(i=1;i<=e;i++)
	{
		cin>>x>>y;
		g[x][y]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][j]==1||(g[i][k]==1&&g[k][j]==1)) g[i][j]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		bn=1;
		for(int j=1;j<=n;j++) 
		{
			if(i!=j&&!g[i][j]) 
			{
				bn=0;
				break;
			}
		}
		if(bn==1) break;
	}
	if(bn==1) cout<<i;
	else cout<<"not found";
	return 0;
}

