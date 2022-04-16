#include<bits/stdc++.h>
#define N 96110
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,l,p,maxv=0,minv=0;
	cin>>l>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		minv=max(minv,min(1+l-p,p));
		maxv=max(maxv,max(1+l-p,p));
	}
	cout<<minv<<" "<<maxv;
	return 0;
}

