#include<bits/stdc++.h>
using namespace std;
int js(int a)
{
	int sum=1;
	for(int i=1;i<=a;i++)
	{
		sum*=i;
	}
	return sum;
 } 
int main()
{
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s+=js(i);
	}
	cout<<s;
	return 0;
}

