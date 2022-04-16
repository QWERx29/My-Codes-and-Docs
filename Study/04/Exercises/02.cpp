#include<iostream>
using namespace std;
int main()
{
	double s=0,sum;
	int n=0;
	cin>>sum;
	while(1)
	{
		++n;
		s+=1.0/n;
		if(s>sum) break;
	}
	cout<<n;
	return 0;
}
