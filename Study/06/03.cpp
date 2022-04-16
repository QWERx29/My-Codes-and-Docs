#include<bits/stdc++.h>
using namespace std;
double s(double a,double b,double c)
{
	double p=(a+b+c)/2,w;
	w=sqrt(p*(p-a)*(p-b)*(p-c));
	return w;
 } 
int main()
{
	double b1,b2,b3,b4,b5,b6,b7,q;
	cin>>b1>>b2>>b3>>b4>>b5>>b6>>b7;
	q=s(b1,b5,b6)+s(b2,b6,b7)+s(b3,b4,b7);
	printf("%.3lf",q);
	return 0;
}

