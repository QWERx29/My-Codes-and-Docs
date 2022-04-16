#include<bits/stdc++.h>
using namespace std;
long long a[10020],t,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];a[i]=a[j];a[j]=t;
			}
		}
	}
	for(int i=n;i>=1;i--) cout<<a[i]<<" ";
	return 0;
}
