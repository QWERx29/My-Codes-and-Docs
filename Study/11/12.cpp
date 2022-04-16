#include<bits/stdc++.h>
using namespace std;
long long a,n,m,x,k;
long long f[961100],g[961100];
int main()
{
	cin>>a>>n>>m>>x;
	f[1]=f[2]=1;f[3]=2;
	g[1]=g[2]=g[3]=0;g[4]=1;
	for(long long i=4;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2]-1;
	}
	for(long long i=5;i<=n;i++)
	{
		g[i]=g[i-1]+g[i-2]+1;
	}
	if(n<=4) k=0;
    else 	
		k=(m-a*f[n-1])/g[n-1];
	cout<<a*f[x]+k*g[x];
	
}
