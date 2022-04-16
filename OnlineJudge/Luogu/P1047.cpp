// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int l,m,a[10010],ans=0;
int main()
{
	cin>>l>>m;
	for(int i=0;i<=l;i++)
		a[i]=0;
	for(int i=1;i<=m;i++)
	{
		int s,e;
		cin>>s>>e;
		for(int j=s;j<=e;j++)
			if(a[j]==0) a[j]=1;	
	}
	for(int i=0;i<=l;i++)
		if(a[i]==0) ans++;
	cout<<ans;	
}
