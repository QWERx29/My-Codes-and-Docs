#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
int main()
{
	double r;
	scanf("%lf",&r);
	printf("%.4lf %.4lf %.4lf\n",2*r,2*PI*r,PI*r*r);
	return 0;
}
