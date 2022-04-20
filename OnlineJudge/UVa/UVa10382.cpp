#include<bits/stdc++.h>
using namespace std;
int n,l,ans,cnt;
double h,t,r,x;
struct node
{
	double x,y;
}a[10005];

bool cmp(node a,node b)
{
	return a.x<b.x;
}
int main()
{
	while(cin>>n>>l>>h&&n)
	{
		cnt=0;
		for(int i=1;i<=n;i++) 
		{
			cin>>x>>r;
			if(r<=h/2)  continue;
			cnt++;
			a[cnt].x=x-sqrt(r*r-(h/2)*(h/2));
			a[cnt].y=x+sqrt(r*r-h*h*0.25);
		}
		sort(a+1,a+cnt+1,cmp);
		int flag=1,i=1;t=0,ans=0;
		while(t<l)
		{
        	ans++;
			double s=t;
			for(;a[i].x<=s&&i<=cnt;i++)  t=max(t,a[i].y);
			if(s==t&&s<l)
			{
				cout<<"-1"<<endl;
				flag=0;
				break;
			}
		}
		if(flag)  cout<<ans<<endl;
	}
	return 0;	
} 
