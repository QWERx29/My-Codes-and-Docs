#include<bits/stdc++.h>
using namespace std;
int n,q,a[50050];
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	for(int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		cout<<upper_bound(a+1,a+n+1,x)-a<<endl;
	}
	return 0;
}