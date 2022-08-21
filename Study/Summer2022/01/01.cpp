#include<bits/stdc++.h>
using namespace std;
int n,x;
priority_queue<int,vector<int>,greater<int> > pq;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t==1) cin>>x,pq.push(x);
		if(t==2) cout<<pq.top()<<endl;
		if(t==3) pq.pop();
	} 
	return 0;
}