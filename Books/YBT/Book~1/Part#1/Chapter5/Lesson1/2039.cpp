#include<bits/stdc++.h>
using namespace std;
long long a[10020],t,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}
