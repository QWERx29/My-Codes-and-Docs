#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
const int MOD=998244353;

int d[N],f[N][N];
int n,m;

inline int mul(int x,int y)
{
	return (x*y)%MOD;
}
inline int add(int x,int y)
{
	return ((x+y)%MOD+MOD)%MOD;
}
inline int D(int n,int m)
{
	memset(d,0,sizeof(d));
	d[0]=1,d[1]=m,d[2]=add(mul(m,m+1),1);
	for(int i=3;i<=n;i++)
		d[i]=add(mul(i+m-1,d[i-1]),mul(i-1,d[i-2]));
	return d[n];
}
inline void C()
{
	f[0][0]=f[1][0]=f[1][1]=1;
	for(int i=2;i<N;i++)
	{
		f[i][0]=f[i][i]=1;
		for(int j=1;j<i;j++)
			f[i][j]=add(f[i-1][j],f[i-1][j-1]);
	}
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	C();
	for(int i=0;i<=m;i++)
		cout<<mul(f[m][i],D(m-i,n-m))<<endl;
	return 0;
}