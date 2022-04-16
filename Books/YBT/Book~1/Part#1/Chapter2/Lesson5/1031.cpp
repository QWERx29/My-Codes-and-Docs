#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	printf("%03d",a/100+(a%10)*100+(a/10)%10*10);
}
