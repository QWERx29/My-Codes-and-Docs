#include<bits/stdc++.h>
using namespace std;
int m,n;
int p[10086],f[10086],t[10086];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>p[i]>>t[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=t[i];j<=m;j++) 
			f[j]=max(f[j],f[j-t[i]]+p[i]);
	}
	cout<<f[m];
	return 0;
}