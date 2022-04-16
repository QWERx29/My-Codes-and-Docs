#include<bits/stdc++.h>
int a[10010][350],into[10086],ans[10086],m,n,mny;
using namespace std;
void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[y][0]++;
		a[y][a[y][0]]=x;
		into[x]++;
	}
}
bool topsort()
{
	int tot=0,k=0,t;
	while(tot<n)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(into[i]==0)
			{
				tot++;t++;mny+=100;
				ans[t]=i;
				into[i]=0xffffff;
			}
		}
		if(t==0) return false;
		mny+=k*t;k++;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=a[ans[i]][0];j++) into[a[ans[i]][j]]--;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
    init();
    if(topsort())cout<<mny;
    else cout<<"Poor Xed";
	return 0;
}

