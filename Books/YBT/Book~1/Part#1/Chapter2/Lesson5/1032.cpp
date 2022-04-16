#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
int main()
{
	int r,h;
	double v;
	scanf("%d%d",&h,&r);
	v=h*PI*r*r;
	printf("%d",20000/(int)v);
}
