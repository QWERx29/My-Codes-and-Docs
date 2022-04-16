#include<bits/stdc++.h>
using namespace std;
int x;
int xn(int n)
{
	if(n==0) return 1;
	else return x*xn(n-1);
}
int main()
{
	int n;
	cin>>x>>n;
	cout<<xn(n);
	return 0;
}

