#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e5+10,M=N*42;

int son[M][2],dat[M],tag[M],tot=0;
int n,q,op,rt;
int L,R;

#define Mid ((l+r)>>1)
#define Len (r-l+1)
#define Root rt,1,n
#define Lpos son[pos][0]
#define Rpos son[pos][1]
#define Lson Lpos,l,Mid
#define Rson Rpos,Mid+1,r
#define This pos,l,r

void newNode(int &pos,int l,int r)
{
	pos=++tot;
	tag[pos]=1,dat[pos]=Len;
}
void setTag(int &pos,int l,int r,int v)
{
	if(!pos) newNode(This);
	tag[pos]=v,dat[pos]=(r-l+1)*v;
}
void pushdown(int pos,int l,int r)
{
	if(tag[pos]==-1) return ;
	setTag(Lson,tag[pos]),setTag(Rson,tag[pos]),tag[pos]=-1;
}
void pushup(int pos,int l,int r)
{
	dat[pos]=dat[Lpos]+dat[Rpos];
}
void update(int &pos,int l,int r,int L,int R,int v)
{
	if(!pos) newNode(This);
	if(L<=l&&r<=R) return setTag(This,v),void();
	pushdown(This);
	if(L<=Mid) update(Lson,L,R,v);
	if(R>Mid) update(Rson,L,R,v);
	pushup(This);
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
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