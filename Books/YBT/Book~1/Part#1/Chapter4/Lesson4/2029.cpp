#include<iostream>
using namespace std;
int q(int a)
{
	int b=a*a*a;
	return b;
}
int main()
{
	for(int i=100;i<=999;i++)
	{
		if((q(i/100)+q(i%10)+q((i/10)%10))==i)
			cout<<i<<endl;
	}
	return 0;
}
