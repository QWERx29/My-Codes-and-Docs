#include<bits/stdc++.h>
using namespace std;

int f[55][55][55][55],a[1001],b[1001];
int n,m,x;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>x,b[x]++;
	f[0][0][0][0]=a[1];
	for(int q=0;q<=b[1];q++)
	{
		for(int w=0;w<=b[2];w++)
		{
			for(int e=0;e<=b[3];e++)
			{
				for(int r=0;r<=b[4];r++)
				{
					int t=q*1+w*2+e*3+r*4+1;
					if(q>0) f[q][w][e][r]=max(f[q][w][e][r],f[q-1][w][e][r]+a[t]);
					if(w>0) f[q][w][e][r]=max(f[q][w][e][r],f[q][w-1][e][r]+a[t]);
					if(e>0) f[q][w][e][r]=max(f[q][w][e][r],f[q][w][e-1][r]+a[t]);
					if(r>0) f[q][w][e][r]=max(f[q][w][e][r],f[q][w][e][r-1]+a[t]);
				}
			}
		}
	}
	cout<<f[b[1]][b[2]][b[3]][b[4]];
	return 0;
}