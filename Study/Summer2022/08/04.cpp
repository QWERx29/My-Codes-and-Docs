#include<bits/stdc++.h>
using namespace std;

int f[114514*20][2],n,h[114514*20];

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	f[1][0]=f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(h[i]>h[i-1]) f[i][0]=f[i-1][1]+1;
		else f[i][0]=f[i-1][0];
		if(h[i-1]>h[i]) f[i][1]=f[i-1][0]+1;
		else f[i][1]=f[i-1][1];
	}
	cout<<max(f[n][0],f[n][1]);
	return 0;
}