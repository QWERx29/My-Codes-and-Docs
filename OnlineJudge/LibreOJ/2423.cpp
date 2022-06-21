#include<bits/stdc++.h>
using namespace std;
int l,n,m,lef,rig,mid,now,a[96110],s,ans,i;
int main()
{
	
	cin>>l>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	lef=0;rig=l;
	while(lef<=rig)
	{
		mid=(rig+lef)/2;
		now=0;s=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[now]<mid) s++;
			else now=i;
		}
		if(s<=m)
		{
			ans=mid;
			lef=mid+1;
		}
		else rig=mid-1;
	}
	cout<<ans;
	return 0;
}