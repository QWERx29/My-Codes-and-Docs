#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1005],*p=a,n;
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=%d\n",i,*(a+i));
	}
	return 0;
}
