#include<bits/stdc++.h>
using namespace std;
int n;
int f[310][310],s[310];
int main()
{
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++) 
	{
		int p;
		cin>>p;
		s[i]=s[i-1]+p;
	}
	
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
		}
	}
	cout<<f[1][n];
	return 0;
}