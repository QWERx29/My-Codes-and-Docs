#include<iostream>
using namespace std;
int main()
{
	int n,sum=0,k=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		k=(k*i)%1000000;
		sum=(sum+k)%1000000;
	}
	cout<<sum;
	return 0;
}
