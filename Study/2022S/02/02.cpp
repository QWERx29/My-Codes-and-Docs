#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,L=20;
int n,ans;
int l,r,ll,rr,mid;
int st[N][L],lg[N],val[N];
inline int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
inline void init(int n)
{
	lg[0]=-1;
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1,st[i][0]=val[i];
	for(int j=0;j+1<L;j++)
	{
		for(int i=1;i+(1<<(j+1))-1<=n;i++)
			st[i][j+1]=gcd(st[i][j],st[i+(1<<j)][j]);
	}
}
inline int query(int l,int r)
{
	int g=lg[r-l+1];
	return gcd(st[l][g],st[r-(1<<g)+1][g]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>val[i];
	init(n);
	for(int i=1;i<=n;i++)
	{
		l=1,r=i-1,ll=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(query(mid,i)==val[i]) ll=mid,r=mid-1;
			else l=mid+1;
		}
		l=i+1,r=n,rr=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(query(i,mid)==val[i]) rr=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,rr-ll+1);
	}
	cout<<ans;
	return 0;
}