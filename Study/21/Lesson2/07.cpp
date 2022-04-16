#include<bits/stdc++.h>
using namespace std;
struct node
{
	int t,m;
}w[100860];
long long n,i,ans;
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(node u,node v)
{
	return u.t<v.t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;for(i=1;i<=n;i++) cin>>w[i].t>>w[i].m;
	sort(w+1,w+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(w[i].t<=q.size())
		{
			if(w[i].m>q.top())
			{
				ans-=q.top();
				q.pop();
				q.push(w[i].m);
				ans+=w[i].m;
			}
		}
		else
		{
			q.push(w[i].m);
			ans+=w[i].m;
		}
	}
	cout<<ans;
	return 0;
}

