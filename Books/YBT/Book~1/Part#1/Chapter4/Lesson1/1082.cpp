#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,n,c;
	cin>>a>>b>>n;
	c=a;
	for(int i=1;i<=n;i++)
	{
		c%=b;
		c*=10;
	}
	c/=b;
	cout<<c;
    return 0;
}