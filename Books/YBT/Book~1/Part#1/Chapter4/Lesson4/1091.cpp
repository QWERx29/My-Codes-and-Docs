#include<iostream>
using namespace std;
int main()
{
	int n,sum=0,k=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		k*=i;
		sum+=k;
	}
	cout<<sum;
	return 0;
}
