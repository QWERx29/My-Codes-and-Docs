#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
struct point{
	int x,y,v;
}a[9901];
int father[110];
int n,m,x,tot,k,q;
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			cin>>x;
			if(x!=0)
			{
				q++;
				a[q].x=i,a[q].y=j,a[q].v=x;
			}
		}
	}
	for(int i=1;i<=n;i++) father[i]=i;
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			unionn(a[i].x,a[i].y);
			tot+=a[i].v;
			k++;
		}
		if(k==n-1) break;
	}
	cout<<tot<<endl;
	return 0;
}

