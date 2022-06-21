#include<bits/stdc++.h>
using namespace std;
char a[2022],b[2022];
int f[2022][2022];
int main()
{
	cin>>a>>b;
	int m=strlen(a),n=strlen(b);
	for(int i=1;i<=m;i++) f[i][0]=i;
	for(int i=1;i<=n;i++) f[0][i]=i;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1]) f[i][j]=f[i-1][j-1];
			else f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
		}
	}
	cout<<f[m][n];
	return 0;
}