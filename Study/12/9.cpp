#include<iostream>
using namespace std;
int main()
{
	long long t,x=0,y=0,a,b;
	cin>>t;
	for(int i=1;i<=t;i++) 
	{
		cin>>a>>b;
		long long c=a%b,q=a,w=b;
		while(c!=0)
		{
			a=b;b=c;c=a%b;
		}
		x=b;
		y=q*w/x;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
