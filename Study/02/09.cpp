#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c;
	double p,s;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.3lf\n",s);
	return 0;
}
