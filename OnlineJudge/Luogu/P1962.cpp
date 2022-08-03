#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=2;
//const int MOD=1e9+7;

int k,mod,n=2;
struct mat{
	ll a[N][N];
	inline mat(int op=0)
	{
        memset(a,0,sizeof(a));
        if(op)for(int i=0;i<n;++i) a[i][i]=1;
    }
	inline const ll* operator[](int x) const { return a[x]; }
	inline ll* operator[](int x) { return a[x]; }
	inline mat operator*(const mat& b)const
	{
		mat c;
		for(int i=0;i<n;i++)
			for(int k=0;k<n;k++)
			{
				ll tmp=a[i][k];
				for(int j=0;j<n;j++)
					c[i][j]=(c[i][j]+tmp*b[k][j])%mod;
			}
		return c;
	}
}s,t;

inline mat qpow(mat x,int y)
{
    mat res=mat(1);
    for(;y;y>>=1)
	{
        if(y&1) res=res*x;
        x=x*x;
    }
	return res;
}
inline void init()
{
	s.a[0][0]=1,s.a[0][1]=0;
	t.a[0][0]=t.a[1][0]=t.a[0][1]=1,t.a[1][1]=0;
}

signed main()
{
	init();
	cin>>k;mod=1e9+7;
	s=s*qpow(t,k-1);
	cout<<s.a[0][0];
	return 0;
}