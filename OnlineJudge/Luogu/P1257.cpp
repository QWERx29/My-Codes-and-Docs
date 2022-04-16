#include<bits/stdc++.h>
using namespace std;
long long n,tmp[961100];
struct point
{
	double x,y;
}s[961100];
bool cmp(const point &a,const point &b)
{
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool cmpy(const int &a,const int &b)
{
	return s[a].y<s[b].y;
}
double min(double a,double b)
{
	return a<b?a:b;
}
double dist(int i,int j)
{
	double x=pow(s[i].x-s[j].x,2);
	double y=pow(s[i].y-s[j].y,2);
	return sqrt(x+y);
}
double merge(int l,int r)
{
	double d=84759866;
	if(l==r) return d;
	if(l+1==r) return dist(l,r);
	int mid=(l+r)>>1;
	double d1=merge(l,mid),d2=merge(mid+1,r);
	d=min(d1,d2);
	int k=0;
	for(int i=l;i<=r;++i)
	{
		if(fabs(s[mid].x-s[i].x)<=d) tmp[k++]=i;
		
	}
	sort(tmp,tmp+k,cmpy);
	for(int i=0;i<k;++i)
	{
		for(int j=i+1;j<k&&s[tmp[j]].y-s[tmp[i]].y<d;++j)
		{
			double d3=dist(tmp[i],tmp[j]);
			if(d>d3) d=d3;
		}
	}
	return d;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i].x>>s[i].y;
	sort(s,s+n,cmp);
	printf("%.4lf",merge(0,n-1));
}
