#include<cstdio>
using namespace std;
int main()
{
	const double pi=3.14159;
	double r,c,s;
	scanf("%lf",&r);
	s=pi*r*r;
	c=2*pi*r;
	printf("%0.2lf\n%0.2lf\n",c,s);
	return 0;
}
