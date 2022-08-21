#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int MOD=9999997;
const int base=233;
const int N=1e6+5;

ll pw[N],hs[N],h,ans,l1,l2;
char a[N],b[N];

inline void Hash_A(int n,char* s)
{
	pw[0]=1;
	for(int i=1;i<=n;i++)
	{
		pw[i]=(pw[i-1]*base)%MOD;
		hs[i]=(hs[i-1]*base+s[i])%MOD;
	}
}
inline void Hash_B(int n,char *s)
{
	for(int i=1;i<=n;i++) 
		h=(h*base+b[i])%MOD;
}
inline ll mod(ll x){ return (x%MOD+MOD)%MOD; }
inline ll Hash(int l,int r){ return mod(hs[r]-hs[l-1]*pw[r-l+1]); }

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>(a+1)>>(b+1);
	l1=strlen(a+1),l2=strlen(b+1);
	Hash_A(l1,a);
	Hash_B(l2,b);
	for(int i=1;i+l2-1<=l1;i++)
		if(Hash(i,i+l2-1)==h) ans++;
	cout<<ans;
	return 0;
}