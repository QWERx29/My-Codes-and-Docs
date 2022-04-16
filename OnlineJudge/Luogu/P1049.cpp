// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int m,n,f[20010],w[40]; 
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
			if(f[j]<f[j-w[i]]+w[i]) f[j]=f[j-w[i]]+w[i];
	}
	cout<<m-f[m];
}
