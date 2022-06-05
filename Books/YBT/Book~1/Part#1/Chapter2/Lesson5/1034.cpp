#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double p,s,d1,d2,d3;
	d1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	d2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	d3=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	p=(d1+d2+d3)/2;
	s=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	printf("%.2lf",s);
	return 0;
}
