#include<bits/stdc++.h>
using namespace std;
int r,m,a[10010],t=0;
int main()
{
	cin>>r>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int s,e;
		cin>>s>>e;
		for(int j=s;j<=e;j++)
			if(a[j]==0) a[j]=1;	
	}
	for(int i=0;i<=r;i++)
		if(a[i]==0) t++;
	cout<<t;	
}
