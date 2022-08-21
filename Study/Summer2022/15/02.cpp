#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514];
int l,r,ans;
inline bool check(int x)
{
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++) 
	{
		if(sum+a[i]<=x) sum+=a[i];
		else sum=a[i],cnt++;
	}
	if(cnt>=m) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],l=max(l,a[i]),r+=a[i];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1,ans=mid;
	}
	cout<<ans<<endl;
	return 0;
}