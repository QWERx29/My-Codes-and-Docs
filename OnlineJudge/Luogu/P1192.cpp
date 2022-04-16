#include<bits/stdc++.h>
using namespace std;
const int mod=1e5+3;
typedef long long LL;
LL f[100001],n,k;
int main()
{
	cin>>n>>k;
    f[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)
		{
			for(int j=0;j<i;j++)
		    {
			    f[i]=(f[j]+f[i])%mod;
            }
        }
        else
		{
			for(int j=1;j<=k;j++)
			{
				f[i]=(f[i-j]+f[i])%mod;
			}
 	    }
    }
    cout<<f[n];
}
