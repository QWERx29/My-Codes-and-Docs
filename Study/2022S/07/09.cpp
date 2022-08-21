#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5;

int t,r,n,m;
int pri[N/10],fac[N],inv[N],sum[N],tot;
bool v[N];

inline void get_pri()
{
	v[0]=v[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!v[i]) pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<N;j++)
		{
			v[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
inline void get_inv()
{
	inv[1]=1;
	for(int i=2;i<N;i++) inv[i]=(r-r/i)*inv[r%i]%r;
}
inline void get_fac()
{
	fac[1]=1;
	for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%r;
}
inline void get_sum()
{
	sum[1]=1;
	for(int i=2,j=1;i<N;i++)
	{
		if(i==pri[j]) sum[i]=sum[i-1]*(pri[j]-1)%r*inv[pri[j]]%r,j++;
		else sum[i]=sum[i-1];
	}
}
inline void init()
{
	get_pri();
	get_inv();
	get_fac();
	get_sum();
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>t>>r;
	init();
	while(t--)
	{
		cin>>n>>m;
		cout<<fac[n]*sum[m]%r<<endl;
	}
	return 0;
}