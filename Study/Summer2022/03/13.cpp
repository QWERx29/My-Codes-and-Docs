#include<bits/stdc++.h>
using namespace std;
const int N=5e4+20;

int c[N],w[N<<2];
struct node{
    int l,r,id;
    bool operator < (const node& x) const { return r<x.r; }
};
vector<node> area;
int t[N];

inline void upd(int x,int delta)
{
    for(;x<=N;x+=x&-x) t[x]+=delta;
}
inline int qry(int x)
{
    int res=0;
    for(;x;x-=x&-x) res+=t[x];
    return res; 
}
inline int cal(int x,int y)
{
    return qry(y)-qry(x-1);
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        area.push_back({l,r,i});
    }
    sort(area.begin(),area.end());
    unordered_map<int,int>mp;
    int pos=0;
    for(auto& op:area)
    {
        int l=op.l,r=op.r,id=op.id;
        while(pos+1<=r)
        {
            pos++;
            upd(pos,1);
            if(mp[w[pos]]) upd(mp[w[pos]],-1);
            mp[w[pos]]=pos;
        }
        w[id]=cal(l,r);
    }
    for(int i=1;i<=m;i++) cout<<w[i]<<endl;
}