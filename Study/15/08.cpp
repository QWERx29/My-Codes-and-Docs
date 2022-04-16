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
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	cout<<(x%n+m%n*qpow(10,k,n))%n;
	return 0;
}
