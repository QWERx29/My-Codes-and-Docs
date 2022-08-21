#include<bits/stdc++.h>
using namespace std;

int f[1145141][4][3],a[1145141];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=a[i]+max(f[i-1][j][1],f[i-1][j-1][0]);
		}
	}
	cout<<max(f[n][3][0],f[n][3][1]);
	return 0;
}