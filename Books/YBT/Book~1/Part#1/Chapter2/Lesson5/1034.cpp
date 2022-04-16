#include<stdio.h>
#include<math.h>
int main()
{
	int x1,y1,x2,y2,x3,y3;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	double p,s,d1,d2,d3;
	d1=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	d2=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
	d3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
	p=(d1+d2+d3)/2;
	s=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	printf("%.2lf",s);
}
