#include<bits/stdc++.h>
using namespace std;
int a[120],i=1,n;
int main()
{
	while(scanf("%d",&n)==1)
	{
		a[i]=n;
		i++;
	}
	for(int j=i-1;j>=1;j--)
	{
		cout<<a[j]<<" ";
	}
	return 0;
}
