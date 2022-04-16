#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	const double pi=3.14159;
	double r,h,s1,s2,s;
	scanf("%lf%lf",&r,&h);
	s1=pi*r*r;
	s2=2*pi*r*h;
	s=s1*2+s2;
	printf("%0.3lf\n",s);
	return 0;
}
