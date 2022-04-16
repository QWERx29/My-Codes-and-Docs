#include<bits/stdc++.h>
using namespace std;
int n,ans=1,t;
struct node{
	int s;
	int e;
}a[1005];
bool cmp(node x,node y)
{
	return x.e<y.e;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i].s>>a[i].e;
	sort(a+1,a+1+n,cmp);
	t=a[1].e;
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

