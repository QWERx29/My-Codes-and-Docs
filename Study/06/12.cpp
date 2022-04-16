#include<bits/stdc++.h>
using namespace std;
long long gcd(long long m,long long n)
{
	return m%n==0?n:gcd(n,m%n);
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<gcd(m,n);
	return 0;
}

