#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >h;
int t[10086],f[10086],d[10086];
int ans,m,maxx,n,k,q,T;
void work()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>f[i];
	for(i=1;i<=n;i++) cin>>d[i];
	for(i=1;i<n;i++)  cin>>t[i];
	cin>>m;
	for(k=1;k<=n;k++)
	{
		T=m-q;
		ans=0;
		for(i=1;i<=k;i++) h.push(make_pair(f[i],i));
		while(T>0&&h.top().first>0)
		{
			pair<int,int>a=h.top();
			h.pop();
			ans+=a.first;
			a.first-=d[a.second];
			h.push(a);
			T--;
		}
		if(ans>maxx) maxx=ans;
		q+=t[k];
	}
	cout<<maxx;
}
int main()
{
	ios::sync_with_stdio(false);
	work();
	return 0;
}
