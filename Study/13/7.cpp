#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
void dfs(int a,int b,int c)
{
	if(c==k)
	{
		if(b==n) ans++;
		return;
	}
	for(int i=a;b+i*(k-c)<=n;i++)
		dfs(i,b+i,c+1);
}
int main()
{
	cin>>n>>k;
	dfs(1,0,0);
	cout<<ans;
} 
