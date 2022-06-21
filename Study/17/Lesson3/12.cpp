#include<bits/stdc++.h>
using namespace std;
int n,a[510],f[510][510],p[510];
int main()
{
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++) 
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[i-1]*a[j]*a[k]);
		}
	}
	cout<<f[1][n];
	return 0;
}