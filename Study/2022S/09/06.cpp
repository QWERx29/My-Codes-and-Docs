#include<bits/stdc++.h>
using namespace std;
const int N=305;

int a[N],dp[N][N],ans[N][N],n; 
bool vis[N][N];

void print(int i,int j,int dep)
{
	if(i==j||dep==0) return;
	if (!vis[i][j]) 
    {
		printf("%d ",ans[i][j]);
		vis[i][j]=1;
	}
	print(i,ans[i][j],dep-1);
	print(ans[i][j]+1,j,dep-1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int len=2;len<=n;len++)
    {
		for(int i=1;i<=n-len+1;i++)
        {
			int j=i+len-1;
			for(int k=i;k<j;k++)
            {
				if(dp[i][k]+dp[k+1][j]+(a[i]+a[j])*a[k]>dp[i][j])
                {
					dp[i][j]=dp[i][k]+dp[k+1][j]+(a[i]+a[j])*a[k];
					ans[i][j]=k;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	for(int i=1;i<=n;i++) print(1,n,i);
    return 0;
}