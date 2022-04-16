#include<iostream>
using namespace std;
int main()
{
	int n=0,s=0,sum;
	cin>>sum;
	while(s<sum)
	{
		++n;
		s+=n;
	}
	cout<<n;
	return 0;
}
