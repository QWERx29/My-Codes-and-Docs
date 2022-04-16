#include<bits/stdc++.h>
using namespace std;
int n,a[10086],mina=10086;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<mina) mina=a[i];
	}
	cout<<mina;
	return 0;
}
