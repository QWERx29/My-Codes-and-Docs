#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t=0;
	cin>>n;
	while(n>=1)
	{
		n/=2;
		t++;
	}
	cout<<t;
	return 0;
}

