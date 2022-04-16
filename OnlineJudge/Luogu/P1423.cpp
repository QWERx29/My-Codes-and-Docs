// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
double x,d,s=2;
int ans;
int main()
{
	cin>>x; 
	while(d<x)
	{
		d+=s;
		s*=0.98;
		ans++;
	}
	cout<<ans;
}
