#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;

int dat[N<<2],val[N],tag[N<<2];
int n,q;
string op;

#define Mid ((l+r)>>1)
#define Len (r-l+1)
#define Root 1,1,n
#define Lpos pos<<1
#define Rpos Lpos|1
#define Lson Lpos,l,Mid
#define Rson Rpos,Mid+1,r
#define This pos,l,r

inline void stg(int pos,int l,int r,int v)
{
	tag[pos]+=v,dat[pos]+=Len*v;
}
inline void psd(int pos,int l,int r)
{
	stg(Lson,tag[pos]),stg(Rson,tag[pos]),tag[pos]=0;
}
inline void upd(int pos)
{
	dat[pos]=dat[Lpos]+dat[Rpos];
}
inline void bld(int pos,int l,int r)
{
	if(l==r) dat[pos]=val[l];
	else bld(Lson),bld(Rson),upd(pos);
}
inline void upd(int pos,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R) return stg(This,v),void();
	psd(This);
	if(L<=Mid) upd(Lson,L,R,v);
	if(R>Mid) upd(Rson,L,R,v);
	upd(pos);
}
inline int qry(int pos,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return dat[pos];
	psd(This);
	if(R<=Mid) return qry(Lson,L,R);
	if(L>Mid) return qry(Rson,L,R);
	return qry(Lson,L,R)+qry(Rson,L,R);
}

signed main()
{
//	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>val[i];
	bld(Root);
	for(int i=1;i<=q;i++)
	{
		int L,R,x;
		cin>>op>>L>>R;
		if(op=="Query") 
			cout<<qry(Root,L,R)<<endl;
		else 
			cin>>x,upd(Root,L,R,x);
	}
	return 0;
}