#include<bits/stdc++.h>
using namespace std;
typedef set<int> SET;
map<SET,int> IDcache;
vector<SET>SETcache;
int ID(const SET &x)
{
	if(IDcache.count(x)) return IDcache[x];
	SETcache.push_back(x);
	return IDcache[x]=SETcache.size()-1;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int t,n;
	cin>>t;
	SET empty,x;
	while(t--)
	{
		stack<int>s;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string op;
			cin>>op;
			if(op[0]=='P') s.push(ID(empty));
			else if(op[0]=='D') s.push(s.top());
			else
			{
				SET &x1=SETcache[s.top()];s.pop();
				SET &x2=SETcache[s.top()];s.pop();
				x.clear();
				if(op[0]=='U') set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
				if(op[0]=='I') set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
				if(op[0]=='A') x=x2,x.insert(ID(x1));
				s.push(ID(x));
			}
			cout<<SETcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}  
