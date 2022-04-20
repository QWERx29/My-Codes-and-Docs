#include<bits/stdc++.h>
using namespace std;
int n;
queue<int> Q;
queue<int> q[1006];
char ch[30];
int a[10000000],x,f,k=1;
int main()
{
	while(scanf("%d",&n))
	{
		if(n==0) break;
		cout<<"Scenario #"<<k<<endl;	
		k++;
		memset(a,0,sizeof(a));
		for(int i=1;i<=1005;++i)
		{
			while(!q[i].empty()) q[i].pop();
		}
		while(!Q.empty()) Q.pop();
		int hhh;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&hhh);
			for(int j=0;j<hhh;++j)
			{
				scanf("%d",&x);
				a[x]=i;
			}
		}
		while(scanf("%s",&ch))
		{
			if(ch[0]=='S') break;
			if(ch[0]=='E')
			{
				scanf("%d",&x);
				if(q[a[x]].empty())
				{
					Q.push(x);
					q[a[x]].push(x);
				}
				else q[a[x]].push(x);
			}
			if(ch[0]=='D')
			{
				printf("%d\n",q[a[Q.front()]].front());
				q[a[Q.front()]].pop();
				if(q[a[Q.front()]].empty()) Q.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}
