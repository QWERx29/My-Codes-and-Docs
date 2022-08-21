#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+20;
const int MOD=1e9+7;

int k[N],b[N];
int n,q;
char op;
struct node{
	int k,b;
	inline node operator + (const node& r) const
	{
		node res;
		res.k=(k*r.k)%MOD;
		res.b=(r.k*b+r.b)%MOD;
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
	if(l==r) dat[pos].k=k[l],dat[pos].b=b[l];
	else bld(Lson),bld(Rson),upd(pos);
}
inline void upd(int pos,int l,int r,int p,node f)
{
	if(l==r) return dat[pos]=f,void();
	if(p<=Mid) upd(Lson,p,f);
	else  upd(Rson,p,f);
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
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>k[i]>>b[i];
	bld(Root);
	for(int i=1;i<=q;i++)
	{
		int x,y,z;
		cin>>op>>x>>y>>z;
		if(op=='Q') 
		{
			node f=qry(Root,x,y);
			cout<<(f.k*z+f.b+MOD)%MOD<<endl;
		}	
		else 
			upd(Root,x,{y,z});
	}
	return 0;
}