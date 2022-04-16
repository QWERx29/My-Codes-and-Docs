#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long m,a[10086];
	cin>>m;
	a[1]=1;a[2]=2;a[3]=4;
	for(int i=4;i<=m;i++)
	{
		
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	cout<<a[m];
	return 0;
}

