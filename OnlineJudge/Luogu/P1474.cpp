#include<bits/stdc++.h>
using namespace std;
int v,n;
long long a[10086],f[10086];
int main()
{
	cin>>v>>n;
	for(int i=1;i<=v;i++) cin>>a[i];
	f[0]=1;
	for(int i=1;i<=v;i++)
	{
		for(int j=a[i];j<=n;j++) f[j]+=f[j-a[i]];
	}
	cout<<f[n];
	return 0;
}