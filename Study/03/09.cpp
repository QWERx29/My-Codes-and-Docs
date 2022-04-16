#include<iostream>
using namespace std;
int main()
{
	int a=0,b=0,c=0,x,y;
	cin>>x;
	c=x/4;
	y=x%4;
	switch(y)
	{
		case 0:cout<<a<<" "<<b<<" "<<c<<endl;break;
		case 1:c--;b=1;cout<<a<<" "<<b<<" "<<c<<endl;break;
		case 2:c--;a=1;cout<<a<<" "<<b<<" "<<c<<endl;break;
		case 3:c-=2;a=1;b=1;cout<<a<<" "<<b<<" "<<c<<endl;break;
	}
}

