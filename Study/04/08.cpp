#include<iostream>
using namespace std;
int main()
{
	int a,x=1,i=0,u;
	cin>>a;
	u=a%100;
	do
	{
		++i;
		x=(x*u)%100;
	}while(i!=a);
	cout<<x;
	return 0;
}
