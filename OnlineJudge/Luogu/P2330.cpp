#include<bits/stdc++.h>
#define N 961100
#define ll long long
using namespace std;
struct point{
	ll x,y,v;
}a[N];
ll father[N];
ll n,m,x,tot,k,q,maxx=-1234567;
int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
void unionn(int x,int y)
{
	int fa=find(x),fb=find(y);
	if(fa!=fb) father[fa]=fb;
}
bool cmp(const point &a,const point &b)
{
	return a.v<b.v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].v;
	}
	for(int i=1;i<=n;i++) father[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			unionn(a[i].x,a[i].y);
			tot+=a[i].v;
			maxx=max(maxx,a[i].v); 
			k++;
		}
		if(k==n-1) break;
	}
	cout<<k<<" "<<maxx<<endl;
	return 0;
}

