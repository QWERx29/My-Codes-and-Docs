#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a[55];
	cin>>n;
	a[1]=1;a[2]=1;
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	printf("%d\n",a[n]);
	return 0;
}
