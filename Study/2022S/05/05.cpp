#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50;
//const int MOD=1e9+7;

int k,mod,n=5;
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
    mat res(1);
    for(;y;y>>=1)
	{
        if(y&1) res=res*x;
        x=x*x;
    }
	return res;
}
inline void init()
{
	s.a[0][1]=s.a[0][3]=1;
	t.a[0][0]=t.a[1][0]=t.a[1][1]=t.a[1][2]=1;
	t.a[2][1]=1;
	t.a[3][1]=t.a[3][3]=t.a[3][4]=1;
	t.a[4][1]=2,t.a[4][3]=1;
}

int main()
{
	init();
	cin>>k>>mod;
	s=s*qpow(t,k);
	cout<<s.a[0][0];
	return 0;
}