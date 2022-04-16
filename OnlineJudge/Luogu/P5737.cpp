#include<bits/stdc++.h>
using namespace std;
int a,b,sum,r[10086];
int main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(i%4==0)
		{
			if(i%100==0) 
			{
				if(i%400==0)
				{
					++sum;
					r[sum]=i;
				}
				else continue;
			}
			
			else
			{
				++sum;
				r[sum]=i;
			}
		}
		else continue;
	}
	cout<<sum<<endl;
	for(int i=1;i<=sum;i++)
	{
		cout<<r[i]<<" ";
	}
	return 0;
}

