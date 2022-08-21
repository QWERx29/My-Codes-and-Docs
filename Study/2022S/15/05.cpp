#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1145141;
const int INF=0x3f3f3f3f3f3f3f;
int n,m,s,L,R,mid,res,tot;
int ans=INF,maxx=-1,minx=INF;
int w[N],v[N],l[N],r[N],s1[N],s2[N];
inline bool check()
{
	memset(s1,0,sizeof s1),memset(s2,0,sizeof s2);
	tot=0;
	for(int i=1;i<=n;i++) 
	{
		if(w[i]>=mid) s1[i]+=s1[i-1]+1,s2[i]+=s2[i-1]+v[i];
		else s1[i]=s1[i-1],s2[i]=s2[i-1];
	}
	for(int i=1;i<=m;i++)
		tot+=(s1[r[i]]-s1[l[i]-1])*(s2[r[i]]-s2[l[i]-1]);
	res=abs(tot-s);
	if(tot>s) return 1;
	else return 0;
} 
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) 
		cin>>w[i]>>v[i],maxx=max(maxx,w[i]),minx=min(minx,w[i]);
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
	L=minx-1,R=maxx+2;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check()) L=mid+1;
		else R=mid-1;
		if(res<ans) ans=res;
	}
	cout<<ans<<endl;
	return 0;
}