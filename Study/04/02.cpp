#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	long long sum=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
	}
	printf("%lld\n",sum);
	return 0;
}
