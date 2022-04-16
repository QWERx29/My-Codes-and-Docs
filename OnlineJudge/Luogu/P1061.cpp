#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt,n,m,r,flag,ans,yuan,fu,s,t;
char a[27],an[27];
char b[27]={'*','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int vis[27];
void dfs(int cur) 
{
	if(cur==n+1)
	{
		int f2=0,f=0; 
		for(int i=1;i<=n;i++) if(a[i]!=an[i]) f=1; 
		if(f==0) return;
		for(int i=1;i<=n;i++)
		{
			if(an[i]>a[i]) break;
			else if(an[i]<a[i])
			{
				f2=1;
				break;
			}
		}
		if(f2==1) return;
		flag++;
		for(int i=1; i<n; i++) cout<<an[i];
		cout<<an[n]<<endl;
		if(flag==5) exit(0);
 
	} 
	else 
	{
		for(int i=s; i<=t; i++) 
		{
			if(vis[i]==0 && b[i]>an[cur-1]) 
			{
				an[cur]=b[i];
				vis[i]=1;
				dfs(cur+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&s,&t,&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	return 0;
}
