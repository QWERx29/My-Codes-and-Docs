#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,p;
	scanf("%lf%lf%lf",&a,&b,&c);
	p=(a+b+c)/2;
	printf("%.3lf",sqrt(p*(p-a)*(p-b)*(p-c)));
}
