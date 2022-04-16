#include<bits/stdc++.h>
using namespace std;
int n,c[10003],d[10003],w[10002];
struct node
{
	int m,num; 
}a[10002];
bool cmp(node a,node b)
{
	return a.m<b.m;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		a[i].m=min(c[i],d[i]);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	int l=0,r=n+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].m==c[a[i].num]) w[++l]=a[i].num;
		else w[--r]=a[i].num;
	}
	int ta=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		ta+=c[w[i]];
		if(ta>tb) tb=ta;
		tb+=d[w[i]];
	}
	cout<<tb<<endl;
	for(int i=1;i<=n;i++) cout<<w[i]<<" ";
	return 0;
} 
