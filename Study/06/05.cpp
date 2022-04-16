#include<bits/stdc++.h>
using namespace std;
void sorta(int n,int a[])
{
	int t;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
}
int main()
{
	int a[102010],n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sorta(n,a);
	for(int i=n;i>=1;i--) cout<<a[i]<<" ";
	return 0;
}

