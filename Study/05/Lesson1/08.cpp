#include<bits/stdc++.h>
using namespace std;
int m,n,a[15][15];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cout<<setw(3)<<a[j][i];
		cout<<endl;
	}
	return 0;
}

