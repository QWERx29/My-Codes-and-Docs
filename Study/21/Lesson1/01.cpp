#include<bits/stdc++.h>
using namespace std;
int n,m,tree[10086];
int x,y,root,maxroot,sum,maxx; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		tree[y]=x;
	}
	for(int i=1;i<n;i++)
	{
		if(tree[i]==0)
		{
			root=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(tree[j]==i) sum++;
		}
		if(sum>maxx)
		{
			maxx=sum;maxroot=i;
		}
		
	}
	cout<<root<<endl<<maxroot<<endl;
	for(int i=1;i<=n;i++) 
	{
		if(tree[i]==maxroot) cout<<i<<" ";
	}
	return 0;
}

