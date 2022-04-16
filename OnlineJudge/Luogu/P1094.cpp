// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int w,n,ans,a[30005];
int main()
{
	cin>>w>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int x=1,y=n;
	while(x<=y)
	{
		if(a[x]+a[y]<=w)
		{
			x++;y--;ans++;
		}
		else
		{
			y--;ans++;
		}
    }
	cout<<ans;
}
