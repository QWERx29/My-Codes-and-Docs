#include<bits/stdc++.h>
using namespace std;
const int N=10086;
int v,n,t,w[N],c[N];
int q[N],f[101][101];
int main()
{
	cin>>v>>n>>t;
	for(int i=1;i<=n;i++) 
	{
		int p;
		cin>>w[i]>>c[i]>>p;
		f[p][++f[p][0]]=i;
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=v;j>=0;j--)
		{
			for(int k=1;k<=f[i][0];k++)
			{
				if(j>=w[f[i][k]])
				{
					int tmp=f[i][k];
					q[j]=max(q[j],q[j-w[tmp]]+c[tmp]);
				}	
			}
		}
	}
	cout<<q[v];
	return 0;
}