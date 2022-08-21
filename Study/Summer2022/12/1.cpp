#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;

int n,x,cnt,f[N];
struct edge{
	int u,v,val;
}e[N];
inline bool cmp(edge x,edge y)
{
	return x.val<y.val;
}
inline int getf(int x)
{
	if(x==f[x]) return x;
	f[x]=getf(f[x]);
	return f[x];
}
inline int kruskal(int n,int m)
{
	int s=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fu=getf(e[i].u),fv=getf(e[i].v);
		if(fu!=fv) f[fv]=fu,s+=e[i].val;
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		e[++cnt].u=0,e[cnt].v=i,e[cnt].val=x;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			e[++cnt].u=i,e[cnt].v=j,e[cnt].val=x;
		}
	}
	cout<<kruskal(n,cnt)<<endl;
	return 0;
}