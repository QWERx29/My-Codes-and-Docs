#include<bits/stdc++.h>
using namespace std;
int n,a[10086][5],sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			a[i][4]+=a[i][j];
		}
			
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(a[i][1]-a[j][1])<=5&&abs(a[i][2]-a[j][2])<=5&&abs(a[i][3]-a[j][3])<=5&&abs(a[i][4]-a[j][4])<=10)
				sum++;
		}
	}
	cout<<sum;
	return 0;
}

