#include<bits/stdc++.h>
using namespace std;
const int max1=51;
int a[max1],n,m;
bool sum(int n,int m)
{
	if(a[n]==m) return true;	 
	else if(n==1) return false;
	else
	{
		return sum(n-1,m-a[n])||sum(n-1,m);
	}
}
int main()
{
	cin>>n;
	for (int i=1; i<=n; ++i) cin>>a[i];
	cin>>m;
	if (sum(n,m)) cout<<"YES"<<endl;
	else  cout<<"NO"<<endl;
	return 0;
}

