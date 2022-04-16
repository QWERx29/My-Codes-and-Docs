#include<bits/stdc++.h>
const int N=404;
const int INF=1e9+7;
typedef long long ll;
using namespace std; 
inline int read() 
{
	int x=0;char s=getchar();
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=getchar();
	}
	return x;
}
string c,s;
int dp[N][N][N],sum[N];
ll qkpow(ll a,ll b)
{
	ll res=1,tmp=a;
	while(b)
	{
		if(b&1) res=res*tmp%INF;
		tmp=tmp*tmp%INF;
		b/=2;
	}
	return res;
}
int main()
{
	int t=read();
	while(t--)
	{
		int n=read(),m=read();
		c.clear();s.clear();
		cin>>c>>s;
		memset(sum,0,sizeof(sum));
		for(int i=0;i<c.size();i++)
		{
			if(c[i]=='-') sum[i+1]++;
			sum[i+1]+=sum[i];
		}
		dp[1][0][0]=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,m);j++)
			{
				for(int k=0;k<i;k++)
				{
					int l=i-1-j-k-sum[i-1]*2;
					if(l<0) break;
					if(j==0&&i-1-sum[i-1]*2==k) dp[i][0][i-1-sum[i-1]*2]=qkpow(2,sum[i-1]);
					if(c[i-1]!='-')
					{
						dp[i+1][j][k]=(dp[i+1][j+1][k]+dp[i][j][k])%INF;
						if(j!=m&&c[i-1]==s[j]&&l==0) dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k])%INF;
					}
					else 
					{
						if(k) dp[i+1][j][k-1]=(dp[i+1][j][k-1]+dp[i][j][k])%INF;
						if(l>0) dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%INF;
					}
				}
			}
		}
		cout<<dp[n+1][m][0]<<endl;
	}
	return 0;
}

