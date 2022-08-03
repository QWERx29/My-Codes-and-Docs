#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e5+10,M=N*55;

int son[M][2],dat[M],tag[M],tot=0;
int n,q,op,rt=1;
int L,R;

#define Mid ((l+r)>>1)
#define Len (r-l+1)
#define Root rt,1,n
#define Lpos son[pos][0]
#define Rpos son[pos][1]
#define Lson Lpos,l,Mid
#define Rson Rpos,Mid+1,r
#define This pos,l,r

inline int newNode(int &pos,int l,int r)
{
	pos=++tot;
	tag[pos]=1,dat[pos]=Len;
}
inline void stg(int &pos,int l,int r,int v)
{
	if(!pos) newNode(This);
	tag[pos]=v,dat[pos]=Len*v;
}
inline void psd(int pos,int l,int r)
{
	if(tag[pos]==-1) return ;
	stg(Lson,tag[pos]),stg(Rson,tag[pos]),tag[pos]=-1;
}
inline void upd(int pos)
{
	dat[pos]=dat[Lpos]+dat[Rpos];
}
inline void update(int &pos,int l,int r,int L,int R,int v)
{
	if(!pos) newNode(This);
	if(L<=l&&r<=R) return stg(This,v),void();
	psd(This);
	if(L<=Mid) update(Lson,L,R,v);
	if(R>Mid) update(Rson,L,R,v);
	upd(pos);
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	newNode(Root);
	while(q--)
	{
		cin>>L>>R>>op;
		update(Root,L,R,--op);
		cout<<dat[rt]<<"\n";
	}
	cout<<flush;
	return 0;
}