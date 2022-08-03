#include<bits/stdc++.h>
using namespace std;
const int N=503;
struct node{
	int t,v;
}q[N];
int m,n,ans;
bool vis[N];
bool cmp(node &x,node &y){return x.v>y.v;}
int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;i++) cin>>q[i].t;
	for(int i=1;i<=n;i++) cin>>q[i].v;
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++) 
	{
		int tmp=0;
		for(int j=q[i].t;j>=1;j--)
		{
			if(vis[j]==false) 
			{
				vis[j]=true;
				tmp=1;
				break;
			}
		}
		if(tmp==0)
		{
			for(int j=1;j>=1;j--)
			{
				if(vis[j]==false)
				{
					vis[j]=true;
					break;
				}
			}
			ans+=q[i].v;
		}
	}
	cout<<m-ans;
	return 0;
}