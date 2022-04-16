#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=-1;
	for(int i=1;i<=m;i++)
	{
		int x,mid,l=1,r=n;
		cin>>x;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(x<a[mid]) r=mid-1;
			else l=mid+1;
		}
		cout<<a[r]<<endl;
	}
	return 0;
}
