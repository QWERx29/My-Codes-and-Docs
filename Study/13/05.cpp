#include<bits/stdc++.h>
using namespace std;
int n,c[21][21],minn=123456789,sum=0;
bool f[21];
void search(int x)
{
	if(sum>minn)return;
	if(x==(n+1))
	{
		if(sum<minn) minn=sum;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		{
			sum+=c[i][x];
			f[i]=false;
			search(x+1);
			sum-=c[i][x];
			f[i]=true;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	for(int i=1;i<=n;i++)f[i]=true;
	search(1);
	cout<<minn;
	return 0;
}

