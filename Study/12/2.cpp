#include<bits/stdc++.h>
using namespace std;
int n,q,l,r;
long long a[10086];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	l=1;r=n;
	while(l+1<r)
	{
		int m=(l+r)/2;
		if(a[m]>=q) r=m;
		else l=m;
	}
	if(a[l]==q) cout<<l;
	else if(a[r]==q) cout<<r;
		else cout<<-1;
	return 0;
}
