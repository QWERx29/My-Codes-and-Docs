#include<bits/stdc++.h>
using namespace std;
long long a[9611000];
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int> > q2;
int n,m,q,r;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	r=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>q;
		for(int j=r;j<=q;j++)
		{
			q1.push(a[j]);
			if(q1.size()==i) 
			{
				q2.push(q1.top());
				q1.pop();
			}
		}
		r=q+1;
		cout<<q2.top()<<endl;
		q1.push(q2.top());
		q2.pop();
	}
	return 0;
}

