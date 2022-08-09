#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int s,e;
}a[1010];
bool cmp(node &a,node &b)
{
	return a.e<b.e;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].e;
	sort(a+1,a+n+1,cmp);
	int t=a[1].e,ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s>=t)
		{
			ans++;
			t=a[i].e;
		}
	}
	cout<<ans;
	return 0;
}
