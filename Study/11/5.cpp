#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long m,a[10086];
	cin>>m;
	a[1]=a[2]=1;
	for(int i=3;i<=m;i++) a[i]+=a[i-1]+a[i-2];
	cout<<a[m];
	return 0;
}

