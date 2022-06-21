#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int dp[1010][1010],a[N],b[N],c[N],m,n,k;
int main()
{
	cin>>m>>n>>k;
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		for(int j=m;j>=0;j--)
		{
			for(int q=n;q>=0;q--)
			{
				int w=min(m,j+a[i]),r=min(n,q+b[i]);
				dp[w][r]=min(dp[w][r],dp[j][q]+c[i]);
			}
		}
	}
	cout<<dp[m][n];
	return 0;
}