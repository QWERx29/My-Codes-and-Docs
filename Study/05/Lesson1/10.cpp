#include<bits/stdc++.h>
using namespace std;
int m,n,a[115][115];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		{
			if(a[i][j]!=0) cout<<setw(3)<<i<<setw(3)<<j<<setw(3)<<a[i][j]<<endl;
		}
	}
	return 0;
}

