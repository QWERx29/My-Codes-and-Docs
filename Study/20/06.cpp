#include<bits/stdc++.h>
using namespace std;
int x,y,n,minn=123456789;
int a[10086],b[10086];
void  dfs(int m,int c)
{
	if(m==y) minn=min(minn,c);
	else if(c<=minn)
	{
		b[m]=1;
		if(m+a[m]<=n&&b[m+a[m]]==0) dfs(m+a[m],c+1);
		if(m+a[m]>=1&&b[m-a[m]]==0) dfs(m-a[m],c+1);
		b[m]=0;
	}
}
int main()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(x,0);
	if(minn==123456789) cout<<-1;
	else cout<<minn;
	return 0;
}

