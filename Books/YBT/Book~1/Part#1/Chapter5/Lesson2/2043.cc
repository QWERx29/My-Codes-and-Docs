#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			a[i][1]=1;a[i][i]=1;
			if(i>2&&j<i) a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}