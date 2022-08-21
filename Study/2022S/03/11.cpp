#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;

int a[N],c[N],n,ans;

inline int query(int x)
{
	int res=0;
	for(;x;x-=x&-x) res+=c[x];
	return res;
}
inline void update(int x,int delta)
{
	for(;x<N;x+=x&-x) c[x]+=delta;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		ans+=query(a[i]-1);
		update(a[i],1);
	}
	cout<<ans;
	return 0;
}