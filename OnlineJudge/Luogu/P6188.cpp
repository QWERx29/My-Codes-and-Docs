#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=n/14;i>=0;i--)
	{
		for(int j=n/4;j<=i;j++)
		{
			for(int k=n/3;k<=i;k++)
			{
				if(i*7+j*4+k*3==n) 
				{
					cout<<i<<" "<<j<<" "<<k;
					return 0;
				}
			}
		}
	 } 
	 cout<<-1;
	return 0;
}

