#include<iostream>
using namespace std;
int main()
{
	long long n,s=1,x=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s=1;
		for(int j=1;j<=i;j++)
		{
			s*=j;
		}
		x+=s;
	}
	cout<<x;
	return 0;
}
