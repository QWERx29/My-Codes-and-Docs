#include<bits/stdc++.h>
using namespace std;
int f[1000010],n,sum,t;
int main()
{
	cin>>n;
	for(int i=2;i<sqrt(n);i++)
	{
		sum=i;
		if(f[sum]==0)
		{
			while(sum<n)
			{
				sum=sum+i;
				f[sum]=1;
			}
		}
		
	 } 
	for(int i=2;i<=n;i++)
	{
		if(f[i]==0) 
		{
			cout<<i<<" ";
			t++;
			if(t%5==0) cout<<endl;
		}
	}
	return 0;
}

