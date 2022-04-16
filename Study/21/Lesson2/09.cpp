#include<bits/stdc++.h>
using namespace std;
long long n;
priority_queue<long long,vector<long long>,greater<long long> >h;
void work()
{
	long long x,y,i,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		h.push(x);
	}
	for(i=1;i<n;i++)
	{
		x=h.top();h.pop();
		y=h.top();h.pop();
		ans+=x+y;
		h.push(x+y);
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(false);
	work();
	return 0;
}
