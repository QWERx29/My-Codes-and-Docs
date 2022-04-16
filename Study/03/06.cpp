#include<iostream>
using namespace std;
int main()
{
	double m,x;
	cin>>m;
	if(m<=20) x=1.68*m;
	else if(m>20)
	{
		x=1.98*m;
	}
	printf("%.2lf",x);
	return 0;
}
