#include<bits/stdc++.h>
using namespace std;
long long gcd(long long m,long long n)
{
	long long c=m%n,q=m,w=n,x,y;
	while(c!=0)
	{
		m=n;n=c;c=m%n;
	}
	x=n;
	y=q*w/x;
	return x;
	
}
int main()
{
	int m,n;
	cin>>m>>n;
	int q=gcd(m,n);
	m/=q;n/=q;
	cout<<m<<" "<<n;
	return 0;
}

