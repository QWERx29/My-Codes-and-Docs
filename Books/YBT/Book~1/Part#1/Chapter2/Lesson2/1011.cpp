#include<stdio.h>
int main()
{
	double x,y;
	scanf("%lf%lf",&x,&y);
	printf("%.3lf%%\n",y*100.0/x);
	return 0;
}
