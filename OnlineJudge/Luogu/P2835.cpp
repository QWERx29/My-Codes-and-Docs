#include<bits/stdc++.h>
using namespace std;
int a[201][201],b[201];
int n,x,y,ans,i;
int dfs(int q)
{
    if(b[q]==i) return 0;
    b[q]=i;
	for(int k=1;k<=a[q][0];k++) dfs(a[q][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;++i)
	{
    	while(cin>>x)
    	{
    		if(x==0) break;
    		a[i][++a[i][0]]=x;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0) dfs(i);
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==i) ans++;
	}
	cout<<ans;
	return 0;
}
