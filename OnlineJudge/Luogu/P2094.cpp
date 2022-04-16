#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int n,k,u;
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {cin>>u;q.push(u);}
    while(q.size()>1) 
	{
        int x=q.top();q.pop();
        int y=q.top();q.pop();
        q.push((x+y)/k);
    }
    cout<<q.top();
}
