#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+20;

int val[N];
int n,q,op;
struct node{
	int sum,pre,suf,ans;
	node() {}
	node(int val) {	sum=pre=suf=ans=val; }
	inline node operator + (const node& r) const
	{
		node res;
		res.sum=sum+r.sum;
		res.pre=max(pre,sum+r.pre);
		res.suf=max(suf+r.sum,r.suf);
		res.ans=max(max(ans,r.ans),suf+r.pre);
		return res;
	}
}dat[N<<2];

#define Mid ((l+r)>>1)
#define Len (r-l+1)
#define Root 1,1,n
#define Lpos pos<<1
#define Rpos Lpos|1
#define Lson Lpos,l,Mid
#define Rson Rpos,Mid+1,r
#define This pos,l,r

inline void upd(int pos)
{
	dat[pos]=dat[Lpos]+dat[Rpos];
}
inline void bld(int pos,int l,int r)
{
	if(l==r) dat[pos]=node(val[l]);
	else bld(Lson),bld(Rson),upd(pos);
}
inline void upd(int pos,int l,int r,int p,int v)
{
	if(l==r) return dat[pos]=node(v),void();
	if(p<=Mid) upd(Lson,p,v);
	else  upd(Rson,p,v);
	upd(pos);
}
inline node qry(int pos,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return dat[pos];
	if(R<=Mid) return qry(Lson,L,R);
	if(L>Mid) return qry(Rson,L,R);
	return qry(Lson,L,R)+qry(Rson,L,R);
}

signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>val[i];
	bld(Root);
	for(int i=1;i<=q;i++)
	{
		int L,R,p,x;
		cin>>op;
		if(op==1) 
		{
			cin>>L>>R;
			if(L>R) swap(L,R);
			cout<<qry(Root,L,R).ans<<endl;
		}	
		else 
			cin>>p>>x,upd(Root,p,x);
	}
	return 0;
}