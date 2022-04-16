#include<bits/stdc++.h>
using namespace std;
int a[120],n,tmp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	tmp=a[1];
	for(int i=2;i<=n;i++) cout<<a[i]<<" ";
	cout<<tmp;
	return 0;
}
