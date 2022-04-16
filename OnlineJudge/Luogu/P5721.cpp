#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			++t;
			if(t<10) cout<<0;
			cout<<t;
		}
		cout<<endl;
	 } 
	return 0;
}

