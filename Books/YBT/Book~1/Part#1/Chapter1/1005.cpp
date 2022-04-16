#include<stdio.h>
int main()
{
	double x,a,y,b,z;
	scanf("%lf%lf%lf%lf",&x,&a,&y,&b);
    z=(x*a-y*b)/(a-b);
    printf("%.2lf",z);
	return 0;
}
