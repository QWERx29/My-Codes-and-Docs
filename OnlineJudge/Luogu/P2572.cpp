#include<bits/stdc++.h>
using namespace std;
const int N=100005;

#define Mid ((l+r)>>1)
#define Lpos (pos<<1)
#define Rpos (Lpos|1)
#define Lson Lpos,l,Mid
#define Rson Rpos,Mid+1,r
#define Len (r-l+1)
#define Root 1,1,n
#define This pos,l,r

int val[N],tag[N<<2];
struct node{
    int pre0,suf0,ans0,pre1,suf1,ans1,sum,len;
    inline node operator+(const node& r) const {
        node res;
        res.sum=sum+r.sum;
        res.len=len+r.len;
        res.pre0=pre0==len?len+r.pre0:pre0;
        res.suf0=r.suf0==r.len?suf0+r.len:r.suf0;
        res.ans0=max(max(ans0,r.ans0),suf0+r.pre0);
        res.pre1=pre1==len?len+r.pre1:pre1;
        res.suf1=r.suf1==r.len?suf1+r.len:r.suf1;
        res.ans1=max(max(ans1,r.ans1),suf1+r.pre1);
        return res;
    }
    inline void flip()
    {
        sum=len-sum;
        swap(pre0,pre1);
        swap(ans0,ans1);
        swap(suf0,suf1);
    }
    inline void init(int l,int v)
    {
        len=l;
        if(v) sum=pre1=suf1=ans1=l,pre0=suf0=ans0=0;
        else  sum=pre1=suf1=ans1=0,pre0=suf0=ans0=l;
    }
}dat[N<<2];

inline void upd(int pos)
{
    dat[pos]=dat[Lpos]+dat[Rpos];
}
inline void stg(int pos,int l,int r,int v)
{
    if(v<2) dat[pos].init(Len,v),tag[pos]=v;
    else 
    {
        dat[pos].flip();
        if(tag[pos]<=1&&tag[pos]>=0) tag[pos]^=1;
        else tag[pos]=1-tag[pos];
    }
}
inline void psd(int pos,int l,int r)
{
    if(tag[pos]==-1) return ;
    stg(Lson,tag[pos]),stg(Rson,tag[pos]),tag[pos]=-1;
}
inline void update(int pos,int l,int r,int L,int R,int v)
{
    if(L<=l&&r<=R) return stg(This,v),void();
    psd(This);
    if(L<=Mid) update(Lson,L,R,v);
    if(R>Mid)  update(Rson,L,R,v);
    upd(pos);
}
inline node qry(int pos,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return dat[pos];
    psd(This);
    if(R<=Mid) return qry(Lson,L,R);
    if(L>Mid)  return qry(Rson,L,R);
    return qry(Lson,L,R)+qry(Rson,L,R);
}
inline void bld(int pos,int l,int r)
{
    tag[pos]=-1;
    if(l==r) dat[pos].init(1,val[l]);
    else bld(Lson),bld(Rson),upd(pos);
}

int main()
{
    memset(tag,-1,sizeof(-1));
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    bld(Root);
    for(int i=1;i<=q;i++)
    {
        int op,l,r;
        cin>>op>>l>>r;
        l++,r++;
        if(op<=2) update(Root,l,r,op);
        if(op==3) cout<<qry(Root,l,r).sum<<endl;
        if(op==4) cout<<qry(Root,l,r).ans1<<endl;
    }
    return 0;
}