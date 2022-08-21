#include<bits/stdc++.h>
using namespace std;
int dp[110][110];
char s[1005];
int main()
{
	cin>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<len;i++)
	{
		for(int j=1;j<=len-i;j++)
		{
			int l=j,r=j+i;
			if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')) dp[l][r]=dp[l+1][r-1]+2;
			for(int k=l;k<r;k++) dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
		}
	}
	cout<<len-dp[1][len];
	return 0;
}