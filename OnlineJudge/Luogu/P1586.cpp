#include<bits/stdc++.h>
using namespace std;
int q[32800][5];
int main()
{
	int n=32768,t,ans;
	q[0][0]=1;
	for(int i=1;i*i<=n;i++)
	{
		for(int j=i*i;j<=n;j++)
		{
			for(int k=1;k<=4;k++)
				q[j][k]+=q[j-i*i][k-1];
		}
	}
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=4;i++)	
			ans+=q[n][i];
		cout<<ans<<endl;
	}
}

