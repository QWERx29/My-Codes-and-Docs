#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD;
const int N=114514;

int f[N],inv[N],v[N];

inline int mul(int x,int y)
{
    return x*y%MOD;
}
inline void init()
{
    inv[1]=1;
    f[0]=f[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mul(inv[MOD%i],(MOD-MOD/i));
    }
    v[1]=inv[1];
    for(int i=2;i<N;i++)
        v[i]=mul(inv[i],v[i-1]);
}

inline int C(int n,int m)
{
    if(n<m) return 0;
    if(n==m||m==0) return 1;
    else return mul(mul(f[n],v[n-m]),v[m]);
}
inline int mod(int n)
{
    return (n%MOD+MOD)%MOD;
}

inline int lucas(int n,int m)
{
    if(n<m) return 0;
    if(n<MOD) return C(n,m);
    int p1=n/MOD,p2=n%MOD;
    int q1=m/MOD,q2=m%MOD;
    return mod(mul(lucas(p1,q1),C(p2,q2)));
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>MOD;
        init();
        cout<<lucas(n+m,n)<<endl;
    }
    return 0;
}