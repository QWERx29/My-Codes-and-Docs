#include<bits/stdc++.h>
using namespace std;
struct net
{
	int x,y,z;
}a[200050];
int n,k,m,f[200050],ans,t=1;
bool cmp(net p,net q)
{
	return p.z<q.z;
}
int father(int v)
{
	if(v==f[v]) return v;
	f[v]=father(f[v]);
	return f[v];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		for(int j=1;j<=n;j++)
		{
			cin>>k;
			if(j>i)
			{
				m++;
				a[m].x=i;
				a[m].y=j;
				a[m].z=k;
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(father(a[i].x)!=father(a[i].y))
		{
			ans+=a[i].z;
			f[father(a[i].x)]=a[i].y;
			t++;
		}
		if(t==n) break;
	}
	cout<<ans;
}
