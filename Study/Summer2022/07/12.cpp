#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,x,y,c,d,w,q,r,e;
int exgcd(int a,int b,int& x,int &y)
{
    if(!b) return x=1,y=0,a;
    int d=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return d;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q>>w;
    for(int i=2;i<=n;i++)
    {
        cin>>e>>r;
        c=(r-w%e+e)%e;
        d=exgcd(q,e,x,y);
        int t=e/d;
        x=x*c/d%t;
        w+=q*x;
        q*=t;
        w=(w%q+q)%q;
    }
    cout<<w;
    return 0;
}