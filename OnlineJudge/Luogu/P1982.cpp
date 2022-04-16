// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+50;
long long n,p,a[N],b[N],dp[N],ans,flag=0;
int main()
{
	cin>>n>>p;ans=-1<<30;
	for(int i=1;i<=n;++i) cin>>a[i];
	b[1]=a[1];dp[1]=a[1];
	for(int i=2;i<=n;++i) dp[i]=max(dp[i-1]+a[i],a[i]);
	for(int i=2;i<=n;++i) dp[i]=max(dp[i],dp[i-1]);
	b[2]=b[1]+dp[1];ans=max(b[1],b[2]);
	for(int i=3;i<=n;++i)
	{
		if(dp[i-1]+b[i-1]<0&&b[i-1]>0) flag=1;
		if(flag==1) b[i]=(b[i-1]%p+dp[i-1])%p;
		else b[i]=max(b[i-1]+dp[i-1],b[i-1]);
		ans=max(ans,b[i]);
    }
    if(flag==1) cout<<b[n]%p;
    else cout<<ans%p;
}

