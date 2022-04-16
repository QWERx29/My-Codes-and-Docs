// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int a,b,x,n,ans;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		b=i;
		while(b!=0)
		{
			a=b%10;
			b/=10;
			if(a==x) ans++;
		}
	}
	cout<<ans;
}
