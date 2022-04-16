#include<iostream>
using namespace std;
int main()
{
	double s=0,sum;
	int n=0;
	cin>>sum;
	while(s<sum)
	{
		++n;
		s+=1.0/n;
	}
	cout<<n;
	return 0;
}
