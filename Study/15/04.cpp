#include<bits/stdc++.h>
using namespace std;
long long qpow(int a,int n,int k)
{
	long long b=a,ans=1;
	while(n>0)
	{
		if(n%2==1) ans=(ans*b)%k;
		b=b*b%k;
		n/=2;
	}
	return ans;
}
int main()
{
	int a,n,k;
	cin>>a>>n>>k;
	cout<<qpow(a,n,k);
	return 0;
}
