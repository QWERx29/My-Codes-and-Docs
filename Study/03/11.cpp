#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,x1,x2,m,n;
	cin>>a>>b>>c;
	if(b*b-4*a*c>=0)
	{
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		printf("x1=%.5f;x2=%.5f",x1,x2);
	}
	else
	{
		x1=-b/(2*a);m=sqrt(4*a*c-b*b)/(2*a);
		x2=-b/(2*a);n=-sqrt(4*a*c-b*b)/(2*a);
		if(n>0)	printf("x1=%.5f+%.5fi;x2=%.5f+%.5fi",x1,m,x2,n);
		else printf("x1=%.5f+%.5fi;x2=%.5f%.5fi",x1,m,x2,n);
	}
	return 0;
}

