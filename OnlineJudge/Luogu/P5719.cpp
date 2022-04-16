#include<bits/stdc++.h>
using namespace std;
double a,b;
int n,k,c;
int main()
{
	scanf("%d%d",&n,&k);
	c=n/k;
	a=c*(c+1)/2*k;
	b=n*(n+1)/2-a;
	printf("%.1f %.1f",a/c,b/(n-c));
	return 0;
}
