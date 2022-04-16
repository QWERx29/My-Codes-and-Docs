// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int t,m,d[1005],w[105],v[105]; 
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=t;j>=0;j--)
			if(j>=w[i]) d[j]=max(d[j-w[i]]+v[i],d[j]);
	}
	cout<<d[t];
}
