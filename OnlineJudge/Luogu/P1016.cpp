#include<bits/stdc++.h>
#define inf 9999999
using namespace std;
int n;
double p,d1,d2,c,p1,maxs;
struct price
{
	double pn,dn;
}z[15];
bool cmp(price x,price y)
{
	return x.dn<y.dn;
}
void run(int w,double l)
{
	int minn;double minp=inf;
	for(int i=w+1;i<=n;i++)
	{
		if(z[i].dn>z[w].dn+maxs) break;
		if(z[i].pn<minp) 
		{
			minp=z[i].pn;
			minn=i;
		}
	}
	if(z[w].pn<=minp&&z[w].dn+maxs>=d1)
	{
		p+=((d1-z[w].dn)/d2-l)*z[w].pn;
		printf("%.2lf\n",p);
		return ;
	}
	if(minp==inf)
	{
		cout<<"No Solution"<<endl;
		return ;
	}
	if(z[w].pn<minp)
	{
		p+=(c-l)*z[w].pn;
		l=c-(z[minn].dn-z[w].dn)/d2;
	}
	else 
	{
		p+=((z[minn].dn-z[w].dn)/d2-l)*z[w].pn;
		l=0.0;
	}
	run(minn,l);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>d1>>c>>d2>>p1>>n;
	z[0].dn=0;z[0].pn=p1;
	for(int i=1;i<=n;i++) cin>>z[i].dn>>z[i].pn;
	maxs=c*d2;
	sort(z+1,z+n+1,cmp);
	run(0,0.0);
	return 0;
}
