#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,c=0;
	while((scanf("%d",&t))==1&&t)
	{
		cout<<"Scenario #"<<++c<<endl;
		map<int,int>team;
		for(int i=0;i<t;i++)
		{
			int n,x;
			cin>>n;
			while(n--) {cin>>x;team[x]=i;}
		}
		queue<int>q,q2[10086];
		for(;;)
		{
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D') 
			{
				int t=q.front();
				cout<<q2[t].front()<<endl; q2[t].pop();
				if(q2[t].empty()) q.pop();
			}
			else if(cmd[0]=='E') 
			{
				cin>>x;
				int t=team[x];
				if(q2[t].empty()) q.push(t);
				q2[t].push(x);      
			}
			cout<<endl;
		}
	} 
	return 0;
}

