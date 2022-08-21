#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+50;

int p[N],phi[N],tot=0,n,ans;
bool v[N];

inline void get_phi()
{
	phi[1]=1;
	v[0]=v[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!v[i]) p[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&p[j]*i<=n;j++)
		{
			int pri=p[j],ip=i*pri;
			v[ip]=1;
			if(i%pri==0) 
			{
				phi[ip]=phi[i]*pri;
				break;
			}
			else phi[ip]=phi[i]*phi[pri];
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	get_phi();
	for(int i=2;i<=n;i++) phi[i]+=phi[i-1];
	if(n!=1) cout<<phi[n-1]*2+1;
	else cout<<0;
	return 0;
}