#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double x,x1,x2;
double f(double q)
{
	return a*pow(q,3)+b*pow(q,2)+c*q+d;
}
int main()
{
	cin>>a>>b>>c>>d;
	for(x=-100;x<=100;x++)
	{
		x1=x;x2=x+1;
		if(f(x1)==0) printf("%.2lf ",x1);
		else if(f(x1)*f(x2)<0)
		{
			while(x2-x1>0.001)
			{
				double mid=(x1+x2)/2;
				if(f(x1)*f(mid)<=0) x2=mid;
				else x1=mid;
			}
			printf("%.2lf ",x1);
		}
	}
	return 0;
}
