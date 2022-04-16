#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],c[1010][1010],b[10086];
int s,tot;
void dfs(int t)
{
	if(t>n) 
	{
		if(s<=tot)
		{
			return ;
		}
		tot=s;
		for(int i=1;i<=n;i++) a[i]=b[i];
		return ;
	}
	int ch=1;
	for(int q=1;q<t;q++) 
	{
		if(c[q][t]&&b[q]) 
		{
			ch=0;
			break;
		}
	}
	if(ch) 
	{
		b[t]=1;
		s++;
		dfs(t+1); 
		s--;
		b[t]=0;
	}
	dfs(t+1);
    return;
}
int main() 
{
	cin>>n>>m;	
	int u,v;
	for(int i=1;i<=m;i++) 
	{
		cin>>u>>v;
		c[u][v]=1;
		c[v][u]=1;
	}
	dfs(1);
	cout<<tot<<endl;	
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";	
	return 0;
}

