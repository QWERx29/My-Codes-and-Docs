#include<bits/stdc++.h>
using namespace std;
int n,a[1001][1001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) cin>>a[i][j];
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i+1][j]>=a[i+1][j+1]) a[i][j]+=a[i+1][j];
			else a[i][j]+=a[i+1][j+1];
		}
	}
	cout<<a[1][1]<<endl;
	return 0;
}

