#include<bits/stdc++.h>
int n,a,b,c[34],d[8];
using namespace std;
int main()
{
	cin>>n;
	for(int i=1;i<=7;i++)
	{
		cin>>b;
		c[b]=1; 
	}
	for(int i=1;i<=n;i++)
	{
		int sx=0;
		for(int j=1;j<=7;j++)
		{ 
			cin>>a;
			if(c[a]==1)sx++;
		} 
		d[7-sx+1]++;
	} 
	for(int i=1;i<=7;i++) cout<<d[i]<<" ";
	return 0;
}
