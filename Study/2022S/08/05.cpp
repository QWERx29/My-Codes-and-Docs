#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;

int n,m,k;
int f[2][210][210][2];
char s[1010],t[210];
bool fr=1;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	cin>>s+1>>t+1;
	f[0][0][0][0]=f[1][0][0][0]=1;
	for(int i=1;i<=n;i++,fr^=1)
	{
		for(int j=1;j<=m;j++) 
		{
			for(int q=1;q<=k;q++)
			{
				if(s[i]==t[j])
				{
					f[fr][j][q][0]=(f[fr^1][j][q][0]+f[fr^1][j][q][1])%MOD;
					f[fr][j][q][1]=((f[fr^1][j-1][q][1]+f[fr^1][j-1][q-1][0])%MOD+f[fr^1][j-1][q-1][1])%MOD;
				}
				else
				{
					f[fr][j][q][0]=(f[fr^1][j][q][0]+f[fr^1][j][q][1])%MOD;
					f[fr][j][q][1]=0;
				}	
			}
		}
	}
	cout<<(f[n&1][m][k][0]+f[n&1][m][k][1])%MOD<<endl;
}