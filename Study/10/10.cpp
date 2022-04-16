#include<bits/stdc++.h>
using namespace std;
long long n,b,h[961100],t,ans;
int main()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>h[i];
	sort(h+1,h+n+1);
	for(int i=n;i>=1;i--)
	{
		t+=h[i];
		ans++;
		if(t>=b) break;
	}
	cout<<ans;
	return 0;
}

