#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+20,MOD=666666;

int dat[N<<2],val[N],tga[N<<2],tgm[N<<2];
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

inline void stga(int pos,int l,int r,int v)
{
	dat[pos]=(dat[pos]+Len*v)%MOD;
	tga[pos]=(tga[pos]+v)%MOD;
}
inline void stgm(int pos,int l,int r,int v)
{
	dat[pos]=(dat[pos]*v)%MOD;
	tga[pos]=(tga[pos]*v)%MOD;
	tgm[pos]=(tgm[pos]*v)%MOD;
}
inline void psd(int pos,int l,int r)
{
	if(tgm[pos]!=1) stgm(Lson,tgm[pos]),stgm(Rson,tgm[pos]),tgm[pos]=1;
	if(tga[pos]!=0) stga(Lson,tga[pos]),stga(Rson,tga[pos]),tga[pos]=0;
}
inline void upd(int pos)
{
	dat[pos]=(dat[Lpos]+dat[Rpos])%MOD;
}
inline void bld(int pos,int l,int r)
{
	tgm[pos]=1,tga[pos]=0;
	if(l==r) dat[pos]=val[l];
	else bld(Lson),bld(Rson),upd(pos);
}
inline void upda(int pos,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R) return stga(This,v),void();
	psd(This);
	if(L<=Mid) upda(Lson,L,R,v);
	if(R>Mid) upda(Rson,L,R,v);
	upd(pos);
}
inline void updm(int pos,int l,int r,int L,int R,int v)
{
	if(L<=l&&r<=R) return stgm(This,v),void();
	psd(This);
	if(L<=Mid) updm(Lson,L,R,v);
	if(R>Mid) updm(Rson,L,R,v);
	upd(pos);
}
inline int qry(int pos,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return dat[pos];
	psd(This);
	if(R<=Mid) return qry(Lson,L,R);
	if(L>Mid) return qry(Rson,L,R);
	return (qry(Lson,L,R)+qry(Rson,L,R))%MOD;
}

signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>val[i];
	bld(Root);
	for(int i=1;i<=q;i++)
	{
		int L,R,x;
		cin>>op>>L>>R;
		if(op[0]=='Q') 
			cout<<(qry(Root,L,R)+MOD)%MOD<<endl;
		else if(op[0]=='A') 
			cin>>x,upda(Root,L,R,x);
		else 
			cin>>x,updm(Root,L,R,x);
	}
	return 0;
}