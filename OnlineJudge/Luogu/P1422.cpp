// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a;
	double b;
	cin>>a;
	if(a<=150)
	{
		b=a*0.4463;
	}
	else if(a>150&&a<=400)
	{
		b=(a-150)*0.4663+150*0.4463;
	}
	else if(a>=401&&a<=10000) 
	{
		b=(a-400)*0.5663+250*0.4663+150*0.4463;
	}
	printf("%.1lf",b);
}
