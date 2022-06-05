#include<stdio.h>
int main()
{
	double x,y;
	scanf("%lf%lf",&x,&y);
	printf("%.4lf",(x*87+y*85)/(x+y));
	return 0;
}
