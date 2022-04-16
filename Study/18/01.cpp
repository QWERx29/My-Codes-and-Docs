#include<bits/stdc++.h>
using namespace std;
int n,q,x,a[100860],c;
int main()
{
	while(scanf("%d%d",&n,&q)==2&&n)
	{
		cout<<"CASE# "<<++c<<":\n";
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		while(q--)
		{
			cin>>x;
			int p=lower_bound(a,a+n,x)-a;
			if(p<n&&a[p]==x) cout<<x<<" found at "<<p+1<<"\n";
			else cout<<x<<" not found"<<"\n";
		}
	}
	return 0;
}
