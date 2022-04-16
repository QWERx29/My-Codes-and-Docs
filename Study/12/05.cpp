#include<bits/stdc++.h>
using namespace std;
long long f(int n,int k)
{
	if(k>n||k==0) return 0;
	if(k==n||k==1) return 1;
	return f(n-1,k-1)+k*f(n-1,k);
}
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<f(n,k); 
	return 0;
}

