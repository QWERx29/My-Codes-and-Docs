#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10000010;
const int M=664580;

int t,r,n,m;
int pri[M],fac[N],inv[N],tot,pi[M],in[M],pos[N];
bool v[N];

inline void init()
{
    //get_pri
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
    //get_inv
	inv[1]=1;
	for(int i=2;i<r&&i<N;i++) inv[i]=(r-r/i)*inv[r%i]%r;
    //get_pi
	pi[0]=1; 
	for(int i=1;i<=tot;i++) pi[i]=pi[i-1]*(pri[i]-1)%r;
    //get_in
	in[0]=1; 
	for(int i=1;i<=tot;i++) 
	{
		if(pri[i]!=r) in[i]=in[i-1]*inv[pri[i]%r]%r; 
		else in[i]=in[i-1];
	}	
    //get_fac
	fac[0]=1;
	for(int i=1;i<N;i++) 
	{
		if(i!=r) fac[i]=fac[i-1]*i%r;
		else fac[i]=fac[i-1];
	}
    //get_pos
    for(int i=2;i<N;i++) 
	{
		if(v[i]) pos[i]=pos[i-1]; 
		else pos[i]=pos[i-1]+1; 
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>t>>r;
	init();
	while(t--)
	{
		cin>>n>>m;
        if(n>=r&&m<r) cout<<0<<endl;
		else cout<<fac[n]*pi[pos[m]]%r*in[pos[m]]%r<<endl;
	}
	return 0;
}
