#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10086],n,*p;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	p=&a[n];
	for(int i=n;i>=1;i--)
	{
		cout<<*p<<" ";
		p--;
	}
	return 0;
}
