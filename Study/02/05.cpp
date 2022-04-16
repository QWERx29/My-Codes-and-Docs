#include<iostream>
using namespace std;
int main()
{
	int a,x,y,z;
	cin>>a;
	x=a/100;
	y=(a/10)%10;
	z=a%10;
	cout<<z*100+y*10+x<<endl;
	return 0;
}
