#include<stdio.h>
int main()
{
	double r1,r2;
	scanf("%lf %lf",&r1,&r2);
	printf("%.2lf",1/(1/r1+1/r2));
	return 0;
}
