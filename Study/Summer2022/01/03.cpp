#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.5e5+10;
ll n,cnt,l,h,x,r;
struct node{
	double x,y;
	bool operator < (const node& t) const { return x<t.x; }
}a[N];
bool cmp(node q,node w){ return q.x<w.x; }
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>l>>h;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>r;
			if(r<=h/2) continue;
			cnt++;
			a[cnt].x=x-sqrt(r*r-h*h/4.0);
			a[cnt].y=x+sqrt(r*r-h*h/4.0);
		}
		sort(a+1,a+cnt+1,cmp);
		double t=0;
		int ans=0,i=1;
		while(t<l)
		{
			ans++;
			double s=t;
			for(;a[i].x<=s&&i<=cnt;i++) 
				if(t<a[i].y) t=a[i].y;
			if(t==s&&s<l) 
			{
				ans=-1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}