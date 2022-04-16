// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int x,d,ans;
int main()
{
	cin>>x>>d;
	for(int i=1;i<=d;i++)
	{
		if(x!=6&&x!=7) ans+=250;
		if(x==7) x=1;
		else x++;
	}
	cout<<ans;
}
