// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,m,z[50000],v[30],w[30];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--)
			if(j>=v[i]) z[j]=max(z[j-v[i]]+w[i]*v[i],z[j]);
	}
	cout<<z[m];
}
