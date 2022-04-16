#include<iostream>
using namespace std;
int main()
{
	int m,n,x;
	cin>>m>>n;
	x=m>n?n:m;
	while(x>1&&((m%x!=0)||(n%x!=0)))
	{
		x--;
	}
	cout<<x;
	return 0;
}
