#include<iostream>
using namespace std;
int a[101],g[101][101],n,l,r,minn,total;
int main()
{
	
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) g[i][j]=1000000;
	}
	for(int i=1;i<=n;i++)
	{
		g[i][i]=0;
		cin>>a[i]>>l>>r;
		if(l>0) g[i][l]=g[l][i]=1;
		if(r>0) g[i][r]=g[r][i]=1; 
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j&&k!=j&&g[i][k]+g[k][j]<g[i][j])
						g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	minn=0x7fffffff;
	for(int i=1;i<=n;i++)
	{
		total=0;
		for(int j=1;j<=n;j++) total+=g[i][j]*a[j];
		if(total<minn) minn=total;
	}
	cout<<minn;
	return 0;
}
