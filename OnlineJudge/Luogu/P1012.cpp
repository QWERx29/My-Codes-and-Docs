#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a[101];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j-1]+a[j]<a[j]+a[j-1]) swap(a[j-1],a[j]);
		}
	}
	for(int i=0;i<n;i++) cout<<a[i];
}

