#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int MOD=1e9+7;

int n,m,c[N][N],f[N],inv[N];

inline void init()
{
	for(int i=0;i<=m+1;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	inv[1]=1;
	for(int i=2;i<=m+1;i++)
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	init();
	f[0]=n,f[1]=n*(n+1)/2%MOD;
	int pw=n*n%MOD*n%MOD;
	for(int i=2;i<=m;i++,pw=pw*n%MOD)
	{
		f[i]=pw;
		for(int j=i-1,p=1;j>=0;j--,p=-p)
			f[i]=(f[i]+f[j]*c[i+1][j]%MOD*p+MOD)%MOD;
		f[i]=f[i]*inv[i+1]%MOD;
	}
	cout<<f[m];
	return 0;
}