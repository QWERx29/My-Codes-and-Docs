#include<cstdio>
int main()
{
	int n=0,max=-100000000,min=100000000,s=0,x;
	while(scanf("%d",&x)==1)
	{
		s+=x;
		if(x>max) max=x;
		if(x<min) min=x;
		++n;
	}
	printf("%d %d %.3lf",min,max,(double)s/n);
	return 0;
}
