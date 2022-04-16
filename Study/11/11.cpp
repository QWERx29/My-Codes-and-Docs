#include<bits/stdc++.h>
using namespace std;
int n,m,a,c,b,d;
long long step[60][60];
int main()
{
	cin>>n>>m;
	cin>>a>>c>>b>>d;
	step[a][c]=1;
	for(int i=a;i<=b;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(step[i][j])
			{
				if(j-2>=1)step[i+1][j-2]+=step[i][j];
				if(j-1>=1)step[i+2][j-1]+=step[i][j];
				if(j+1<=n)step[i+2][j+1]+=step[i][j];
				if(j+2<=n)step[i+1][j+2]+=step[i][j];
			}
		}
	}		
	cout<<step[b][d];
	return 0;
}
