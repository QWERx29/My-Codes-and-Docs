#include<bits/stdc++.h>
using namespace std;
int a[10020],n,m,k;
int main()
{
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=a[1];k=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=m)
		{
			m=a[i];
			k=i;
		}
	}
	cout<<k;
    return 0;
}
