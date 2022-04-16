// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int a[10],b,ans=0;
int main()
{
	for(int i=0;i<=9;i++)
		cin>>a[i];
	cin>>b;
	b+=30;
	for(int i=0;i<=9;i++)
	{
		if(a[i]<=b) ans++;
		else continue;
	}
	cout<<ans;
}
