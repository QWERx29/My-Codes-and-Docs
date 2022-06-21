#include<bits/stdc++.h>
using namespace std;
int a[55][55],f[55][55][55][55];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int q=1;q<=n;q++)
			{
				for(int w=1;w<=m;w++)
				{
					if(i==q&&j==w) f[i][j][q][w]=max(max(f[i][j-1][q-1][w],f[i-1][j][q][w-1]),max(f[i-1][j][q-1][w],f[i][j-1][q][w-1]))+a[i][j];
					else f[i][j][q][w]=max(max(f[i][j-1][q-1][w],f[i-1][j][q][w-1]),max(f[i-1][j][q-1][w],f[i][j-1][q][w-1]))+a[i][j]+a[q][w];
				}
			}
		}
	}
	cout<<f[n][m][n][m];
	return 0;
}