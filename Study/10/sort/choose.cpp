#include<bits/stdc++.h>
using namespace std;
int n,a[10086];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}	
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
