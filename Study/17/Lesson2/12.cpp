#include<bits/stdc++.h>
using namespace std;
int n,m,f[1101][1010];
int main()
{
	cin>>n;
	m=(n*(n+1))/2;
	if(m%2==1) 
	{
		cout<<0;
		return 0;
	}
	f[1][1]=f[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(j>i) f[i][j]=f[i-1][j]+f[i-1][j-i];
			else f[i][j]=f[i-1][j];
		}
	}
	cout<<f[n][m/2];
	return 0;
}