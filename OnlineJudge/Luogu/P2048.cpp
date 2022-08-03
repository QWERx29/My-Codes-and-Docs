#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e6+50;
ll n,k,L,R;
ll st[N][20],lg[N],val[N],ans,l,r;

inline void init()
{
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) st[i][0]=i;
	for(int j=0;j<lg[n];j++)
	{
		for(int i=1;i+(1<<(j+1))-1<=n;i++)
			st[i][j+1]=(val[st[i][j]]>val[st[i+(1<<j)][j]])?st[i][j]:st[i+(1<<j)][j];
	}
}
inline int query(int l,int r)
{
	int g=lg[r-l+1];
	return (val[st[l][g]]>val[st[r-(1<<g)+1][g]])?st[l][g]:st[r-(1<<g)+1][g];
}

struct node{
	int s,l,t,r;
	node(int _s=0,int _l=0,int _r=0)
		:s(_s),l(_l),r(_r) {
			t=query(l,r);
	};
	bool operator < (const node& x) const {
		return val[t]-val[s-1]<val[x.t]-val[x.s-1];
	}
}tmp;

priority_queue<node> pq;

int main()
{
	cin>>n>>k>>L>>R;
	for(int i=1;i<=n;i++) cin>>val[i],val[i]+=val[i-1];
	init();
	for(int i=1;i+L-1<=n;i++)
	{
		l=i+L-1,r=min(i+R-1,n);
		pq.push(node(i,l,r));
	}
	for(int i=1;i<=k;i++)
	{
		tmp=pq.top(),pq.pop();
		ans+=val[tmp.t]-val[tmp.s-1];
		if(tmp.t!=tmp.l) pq.push(node(tmp.s,tmp.l,tmp.t-1));
		if(tmp.t!=tmp.r) pq.push(node(tmp.s,tmp.t+1,tmp.r));
	}
	cout<<ans<<endl;
	return 0;
		
}