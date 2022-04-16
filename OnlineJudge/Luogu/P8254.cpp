#include<bits/stdc++.h>
#define N 1020
using namespace std;
int a[N][N],c[N],b[N];
int n,m,x[N],y[N],ans=0;
int main()
{
   // freopen("kingdom.in","r",stdin);
  //  freopen("kingdom.out","w",stdout);
    cin>>n>>m;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cin>>a[i][j];
    		if(a[i][j]==1) x[j]++;
    		else y[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]>y[i]) b[i]=1;
		else b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(b[i]==c[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

