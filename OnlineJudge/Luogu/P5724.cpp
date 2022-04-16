#include<bits/stdc++.h>
using namespace std;
int a[10086],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n]-a[1];
	return 0;
}

