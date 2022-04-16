#include<bits/stdc++.h>
using namespace std;
int a[10086],n,t;
int main()
{
	cin>>n;
	while(n!=1)
	{
		++t;
		a[t]=n;
		if(n%2==0) n/=2;
		else n=n*3+1;
	}
	cout<<"1 ";
	for(int i=t;i>=1;i--) cout<<a[i]<<" ";
	return 0;
}

