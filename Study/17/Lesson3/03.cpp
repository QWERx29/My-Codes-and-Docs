#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10086],f[110][8],n,k;
char c;
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		a[i]=c-'0';
	}
	f[1][0]=a[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i-1,k);j++)
		{
			if(j==0) f[i][j]=f[i-1][j]*10+a[i];
			else 
			{
				for(int q=1;q<i;q++)
				{
					int tmp=0;
					for(int w=q+1;w<=i;w++) tmp=tmp*10+a[w];
					f[i][j]=max(f[i][j],f[q][j-1]*tmp);
				}
			}
		}
	}
	cout<<f[n][k];
	return 0;
}