#include<iostream>
using namespace std;
int main()
{
	int a,b,c,max;
	cin>>a>>b>>c;
	if(a>=b)
	{
		if(b>=c) max=a;
		else if(c>=a) max=c;
	}
	if(a<b)
	{
		if(c>=b) max=c;
		else if(c<b) max=b;
	}
	cout<<max<<endl;
	return 0;
}
