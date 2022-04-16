// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int q[20005],w[20005],e[105];
int n,ans,maxx; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
		w[e[i]]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)	
		{
			q[e[i]+e[j]]++;
			maxx=max(maxx,e[i]+e[j]);
		}
	}
	for(int i=1;i<=maxx;i++)
	{
		if(q[i]>0&&w[i]!=0) ans++;
	}
	cout<<ans;
}
