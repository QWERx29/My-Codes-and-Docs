#include<iostream>
#include<algorithm>
using namespace std;
int a[55][55],f[110][55][55];
int n,m,w;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	f[1][1][1]=a[1][1];
	for(int i=2;i<=n+m-1;i++)
	{
		for(int j=1;j<=n&&j<=i;j++)
		{
			for(int q=1;q<=n&&q<=i;q++)
			{
				if(j==1&&q==1) continue;
				f[i][j][q]=max(max(f[i-1][j][q],f[i-1][j-1][q-1]),max(f[i-1][j][q-1],f[i-1][j-1][q]));
				f[i][j][q]+=j==q?a[j][i-j+1]:a[j][i-j+1]+a[q][i-q+1];
			}
		}
	}
	cout<<f[n+m-1][n][n];
	return 0;
}