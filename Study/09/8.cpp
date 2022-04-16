#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[2000];
int b[2000];
int c[2000];
int sum[2000];
void cheng(int *a,int c)
{
	int jw=0;
	for(int i=1;i<=1000;i++)
	{
		a[i]=a[i]*c+jw;
		jw=a[i]/10;
		a[i]%=10;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<n<<"!=";
	a[1]=1;
	for(int i=1;i<=n;i++)
	{
		cheng(a,i);
	}
	bool flag=0;
	for(int i=1000;i>=1;i--)
	{
		if(a[i]!=0) flag=1;
		if(flag) cout<<a[i];
	}
}
