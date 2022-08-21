#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,c;
int mp[110][110],mpp[110][110][11],vis[110][110][11];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
inline void dijkstra()
{
	priority_queue<pair<int,pair<int,pair<int,int> > > > q;
	memset(mpp,0x3f,sizeof mpp);
	mpp[1][1][k]=0;
	q.push(make_pair(0,make_pair(k,make_pair(1,1))));
	while(!q.empty())
	{
		int x=q.top().second.second.first,y=q.top().second.second.second;
		int z=q.top().second.first;
		q.pop();
		if(!vis[x][y][z])
		{
			vis[x][y][z]=1;
			for(int i=0;i<4;i++)
			{
				int x1=x+dx[i],y1=y+dy[i],z1=z-1,cost=mpp[x][y][z];
				if(x1>0&&x1<=n&&y1>0&&y1<=n)
				{
					if(mp[x1][y1]) cost+=a,z1=k;
					if(!z1) cost+=c+a,z1=k;
					if(i>=2) cost+=b;
					if(cost<mpp[x1][y1][z1]) 
						mpp[x1][y1][z1]=cost,q.push(make_pair(-cost,make_pair(z1,make_pair(x1,y1))));
				}
			}
		}
	}
}signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k>>a>>b>>c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	dijkstra();
	int ans=1919810;
	if(mpp[n][n][k]!=0x3f) mpp[n][n][0]=mpp[n][n][k]-c-a;
	for(int i=0;i<k;i++) ans=min(ans,mpp[n][n][i]);
	cout<<ans<<endl;
	return 0;
}