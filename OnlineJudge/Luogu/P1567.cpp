// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int n,ans=1,maxx; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
		{
			ans++;
			b[i]=ans;
		}
		else
		{
			ans=1;
			b[i]=ans;
		}
	}
	maxx=b[1];
	for(int i=1;i<=n;i++) 
	{
		if(maxx<b[i]) maxx=b[i];
		else continue;
	}
	cout<<maxx;
}
