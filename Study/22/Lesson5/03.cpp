#include<bits/stdc++.h>
#define MAXV 1005
#define MAXE 10005
using namespace std;
struct node{
	int to;
	int val;
};
vector<node>v[MAXV];
int deg[MAXV],e[MAXV],n,m,len;
void topsort()
{
	queue<int>q;
	for(int i=0; i<n; i++)
		if(deg[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(!v[u].empty())
			len++;
		for(int i=0; i<v[u].size(); i++)
		{
			int t=v[u][i].to;
			deg[t]--;
			e[t]=max(e[t],e[u]+max(v[u][i].val,1));
			if(deg[t]==0)
				q.push(t);
		}
	}
}
int main()
{	
	while(~scanf("%d%d",&n,&m))
	{
		len=0;
		memset(e,0,sizeof(e));
		memset(deg,0,sizeof(deg));
		int ans=0;
		while(m--) {
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			deg[y]++;
			v[x].push_back((node){y,z});
		}
		topsort();
		for(int i=0; i<=n-1; i++){
			ans=max(ans,e[i]);
		}
		printf("%d\n",len==n?ans:ans+1);
		for(int i=0; i<=n; i++)
			v[i].clear();
	}
	return 0;
}

