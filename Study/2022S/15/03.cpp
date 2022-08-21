#include<bits/stdc++.h>
using namespace std;
int L,n,m,l,r,mid,now,a[96110],s,ans;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	l=0;r=L;
	while(l<=r)
	{
		mid=(r+l)>>1;
		now=0;s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[now]<mid) s++;
			else now=i;
		}
		if(s<=m) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}