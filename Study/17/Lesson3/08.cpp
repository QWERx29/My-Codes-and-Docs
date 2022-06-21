#include<bits/stdc++.h>
using namespace std;
const int N=503;
int m,k,a[N],dp[N][N],s[N];
void print(int q,int w)
{
	if(q==0) return ;
	int j,sum=0;
	for(j=q;j>=1&&sum+a[j]<=w;--j) sum+=a[j];
	print(j,w);
	cout<<j+1<<" "<<q<<endl;
}
int main()
{
	cin>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++) dp[i][1]=s[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=k;j++)
		{
			for(int q=j;q<=i;q++)
				dp[i][j]=min(dp[i][j],max(dp[q-1][j-1],s[i]-s[q-1]));
		}
	}
	print(m,dp[m][k]);
	return 0;
}